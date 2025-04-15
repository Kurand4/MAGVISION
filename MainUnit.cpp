//---------------------------------------------------------------------------
#include <vcl.h>
#include <IniFiles.hpp>
#pragma hdrstop

#include <math.h>
#include <stdio.h>
#include <registry.hpp>
#include <dstring.h>
#include <ctype.h>

#include "MainUnit.h"
#include "CommentUnit.h"
#include "SUnit.h"
#include "TrackUnit.h"
#include "PauseUnit.h"
#include "SeaCommentUnit.h"
#include "FragmentUnit.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Chart"
#pragma link "TeEngine"
#pragma link "TeeProcs"
#pragma link "DBChart"
#pragma link "Series"
#pragma link "BubbleCh"
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner) : TForm(Owner){}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
	Width  = 1328;
	Height = 760;
	WorkDir 		= GetCurrentDir();
	DataBaseDir = GetCurrentDir() + "\\DB";
	GetInfFile();
	StartWay    			= 0;
	WaterAlarmCount   = 0;
	GPSReadyFlag      = false;
	ReadyFlag         = false;
	AbortFlag 	 	  	= false;
	NoGPSDataFlag   	= false;
	MetkaDoneFlag   	= false;
	FastCommentFlag		= false;            // one of WAY button was  pressed
	KeyPressedFlag  	= false;
	StopFlag        	= false;     // выход из цикла ихмерений
	RunFlag         	= false;     // идет процесс измерений
//	UseGPSFlag 				= true;      // по умолчанию работаем с GPS
	RunGPSFlag 				= false;     // true, если подключилось GPS
	PausedFlag				= false;
	TestModeFlag 			= false;
	FragmSearchFlag   = false;
	OpenTubeFlag      = false;
	MARGINPOINT       = 20; 	          // кол. точек до конца оси х на графиках
	UseGPSFlag = !CheckBox_UseGPS->Checked;
	UseBGrndFlag = false;
	SetHorizontalAxis(1);
	SetIniVerticalAxis(0);
	WaterAlarmLabel->Visible = false;
	WaterAlarmLabel->Font->Color = clYellow;
	sGPS = "";
	NoKMDFlag = false;
	KMDThread = NULL;
	InternalGPSflag 	= false;
}
//---------------------------------------------------------------------------
void TMainForm::SaveInfFile()
{
	TIniFile	*	InfFile;
	AnsiString s;

	s = GetCurrentDir() + "\\Hardware.inf";
	InfFile 	= new TIniFile(s.c_str());
	StartWay = 0;
	InfFile->WriteInteger("X", "StartWay", StartWay);
	InfFile->Free();
}
//---------------------------------------------------------------------------
void TMainForm::GetInfFile()
{
	TIniFile	*	InfFile;
	AnsiString s;

	s = GetCurrentDir() + "\\Hardware.inf";
	if (!FileExists(s.c_str())) return;
	InfFile 	  = new TIniFile(s.c_str());
	BthKMDname  = InfFile->ReadString("KMD",  "BthKMDname", "BthModem0");
	BthGPSname  = InfFile->ReadString("GPS",  "BthGPSname", "BthModem4");
	GPSspeed    = InfFile->ReadInteger("GPS", "GPSspeed", 115200);
	MAXPOINT 	  = InfFile->ReadInteger("X",   "MAXPOINT", 5000);  // кол. точек по оси х на графиках
	StartWay    = InfFile->ReadInteger("X",   "StartWay", 0);
	sWay 				= (String)StartWay;
	MarkerStep  = InfFile->ReadInteger("X",   "MarkerStep", 50);
	AUTORESTART	 = InfFile->ReadInteger("X", "AUTORESTART", 100000);    // кол. точек по оси х на графиках
	InfFile->Free();
	if (AUTORESTART) InfoCounterLabel->Caption = "AutoRestart: " + (String)AUTORESTART; else  InfoCounterLabel->Caption = "___";
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CloseButtonClick(TObject *Sender)
{
	if (!RunFlag) {
		SaveInfFile();
		Close();
	} else {
		Timer1->Enabled = false;
		ReadyFlag       = false;
		PausedFlag  		= true;
		PauseForm->ShowModal();
		switch (PauseForm->PauseResult) {
			case 0:                             // continue
				PausedFlag = false;
				RenewTotalDistance();
				Timer1->Enabled = true;
				ReadyFlag       = true;
				break;
			case 1:
				DoFastComment(5);      						// Restart
				Timer1->Enabled = false;
				Timer2->Enabled = false;
				CloseDTfile();
				ResetBeforeStart();
				ShowButtonStatus();
				Timer1->Enabled = true;
				ReadyFlag       = true;
				break;
			case 2:                            // Quit
				RunButtonClick(this);
				break;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormActivate(TObject *Sender)
{
//	if (AUTORESTART) InfoCounterLabel->Caption = "AutoRestart: " + (String)AUTORESTART; else  InfoCounterLabel->Caption = "___";
	ShowWayButtonStatus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetIniVerticalAxis(int iOutputType)
{
	VizorPlot1->LeftAxis->Minimum   = -99999;
	VizorPlot1->LeftAxis->Maximum   = 80;
	switch (iOutputType) {
	 case 0:
		VizorPlot1->LeftAxis->Minimum = 30;
		break;
	 case 1:
		VizorPlot1->LeftAxis->Minimum =  0;
		break;
	 case 2:
		VizorPlot1->LeftAxis->Minimum =  0;
		break;
	}
}
//---------------------------------------------------------------------------
void TMainForm::ShowButtonStatus()
{
	RunButton->Enabled 		   = ((RunGPSFlag && !NoGPSDataFlag) || (!UseGPSFlag));
	if (RunFlag) {
		CloseButton->Caption = "Pause";
		if ((KMDThread != NULL) || NoKMDFlag)
		  RunButton->Caption = "STOP";
	} else {
		CloseButton->Caption 	 = "Quit";
		RunButton->Caption = "START";
	}
	ShowTrackButton->Enabled  = RunButton->Enabled && (UseGPSFlag || InternalGPSflag);
	IzolMarkButton->Enabled   = RunFlag;
	KIPMarkButton->Enabled    = RunFlag;
	CrossMarkButton->Enabled  = RunFlag;
	RoadMarkButton->Enabled   = RunFlag;
	TurnMarkButton->Enabled   = RunFlag;
	CommentButton->Enabled 	  = RunFlag;
	CheckBox_UseGPS->Enabled  = (!RunFlag && !RunGPSFlag);
	GPSButton->Enabled 			  = UseGPSFlag && !RunGPSFlag;
	if (AUTORESTART) InfoCounterLabel->Caption = "AutoRestart: " + (String)AUTORESTART; else  InfoCounterLabel->Caption = "___";
//	BegOpenTubeButton->Enabled = !OpenTubeFlag;
//	EndOpenTubeButton->Enabled = OpenTubeFlag;
	Application->ProcessMessages();
}
//---------------------------------------------------------------------------
AnsiString __fastcall TMainForm::GetCOMnum(AnsiString DeviceName)
{
	int j;
	AnsiString  s;
	AnsiString  sComPort="";
	TRegistry		* Reg 	= new TRegistry;
	TStringList * List 	= new TStringList;

	if (DeviceName.Pos("COM") == 1)
		return DeviceName;
	 else {
		Reg->RootKey = HKEY_LOCAL_MACHINE;
		Reg->OpenKeyReadOnly("HARDWARE\\DEVICEMAP\\SERIALCOMM");
		Reg->GetValueNames(List);
		if (!List->Count) return sComPort;
		for (int i=0; i<List->Count; i++) {
			sComPort 	= Reg->ReadString(List->Strings[i]);
			s 				= List->Strings[i];
			j = s.Pos(DeviceName);
			if (j) break;
			sComPort="";
		}
	}
	return sComPort;
}
//---------------------------------------------------------------------------
void TMainForm::KMDResult(bool bShow)
{
	RunFlag = true;
	ShowDataToPlot(0);   			// вывод на график
	ShowHour(false);
}
//---------------------------------------------------------------------------
bool TMainForm::DoKMDConnect()
{
	if (KMDComPort == "") {
		if (BthKMDname.Pos("COM") == 1)
			KMDComPort = BthKMDname;
		 else
			KMDComPort = GetCOMnum(BthKMDname);         // if user indicate the name of USB-device
		StatusBar1->Panels->Items[5]->Text = KMDComPort;
	}
	return (KMDComPort != "");
}
//---------------------------------------------------------------------------
void TMainForm::ResetBeforeStart()
{
	L_StartLng->Caption = FloatToStrF(d_lng, ffFixed, 9, 6);
	L_StartLat->Caption = FloatToStrF(d_lat, ffFixed, 9, 6);
	fStartLat  	= d_lat;
	fStartLong 	= d_lng;
	TrackForm->FirstPointSeries->AddXY(d_lng, d_lat, "", clRed);
	TrackForm->SetIniCoordAxis(d_lng, d_lat);
	LatCoeff = cos(fStartLat*PI/180.0);
	CoordCount    = 0;
	BadCoordCount = 0;
	fTotalDistance  		= 0;
	fTotalDistance0 		= 0;
	fDistanceFromStart 	= 0;
	Edit_Way0->Text   = FloatToStrF(fDistanceFromStart, ffFixed,8,0);
	Label_Way1->Caption   = int(fTotalDistance);
	TrackForm->ClearTrack();
	TrackForm->Label_Way1->Caption   		= int(fDistanceFromStart);
//	TrackForm->Label_totSpeed->Caption   		= int(fTotalDistance);
	TrackForm->L_CoordCount->Caption 		= "0";
	TrackForm->L_BadCoordCount->Caption = "0";
	sWay 					= (String)StartWay;
	fStartTime0 	= GetTime();
	iCount				= 0;
	ikCount				= 0;
	C_Count 			= 0;
	NoDataCount	  = 0;
	ButtonWay1->Enabled = true;
	ButtonWay2->Enabled = true;
	ButtonWay3->Enabled = true;

	ClearPlot();
	Application->ProcessMessages();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RunButtonClick(TObject *Sender)
{
	if (NoKMDFlag && !UseGPSFlag) return;
	if (!RunFlag) { 			//	if (IsConnected()) Btn_Connect->Caption = "Run"; else Btn_Connect->Caption = "Stop";
		GetInfFile();
		ResetBeforeStart();
//		ShowHour(true);

		if (!NoKMDFlag) {      // Start
			if (!DoKMDConnect()) return;        // com port from inf file
			KMDThread = new TKMD(false);
			if (KMDThread == NULL) return;
			KMDThread->FreeOnTerminate = true;
		}	else {
			Timer1->Enabled = true;
//			RunFlag = true;
			ShowTrackButtonClick(this);
		}

		FragmSearchFlag = SForm->CB_FragmSearch->Checked;
		if ((FragmSearchFlag) && (FragmentForm == NULL)) {
			Application->CreateForm(__classid(TFragmentForm), &FragmentForm);
			FragmentForm->Init(SForm->FragmentName);
			FragmentForm->Show();
		}
		RunFlag    = true;
		ReadyFlag  = true;
		Timer2->Enabled = true;
	} else {
		DoFastComment(5);      // Finish
		if (!NoKMDFlag) {
			KMDThread->Terminate();
		}
		Timer1->Enabled = false;
		Timer2->Enabled = false;
		RunFlag = false;
		CloseDTfile();
		KMDThread = NULL;
	}
	ShowButtonStatus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CheckBox_UseGPSClick(TObject *Sender)
{
	UseGPSFlag = !CheckBox_UseGPS->Checked;
	ShowButtonStatus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CheckBox_NoKMDClick(TObject *Sender)
{
	NoKMDFlag = CheckBox_NoKMD->Checked;
	ShowButtonStatus();
}
//---------------------------------------------------------------------------
void TMainForm::AddRecordToDTfile()
{
	if (!iCount) OpenDTfile();
	__int64   BlockCount = iCount % BLOCKSIZE;

	iCount++;

	BDT[BlockCount].DT_TIME = Now();
	for (int i = 0; i < 6; i++) {
		if (NoKMDFlag) {
			BDT[BlockCount].DT_DATA[i] = 0;
			BDT[BlockCount].AV_DATA[i] = 0;
		}  else {
			BDT[BlockCount].DT_DATA[i] = Data_Array[i];
			BDT[BlockCount].AV_DATA[i] = CAV[i];     // average values
		}
	}
	(MetkaFlag || CommentFlag) ?  BDT[BlockCount].Metka = C_Count : BDT[BlockCount].Metka = 0;
	if (CommentFlag || FastCommentFlag) {
		BDT[BlockCount].Metka += 1000;
		if (CommentForm->BadIzolFlag) {
			BDT[BlockCount].StdCommentType[0] = true;
			CommentForm->BadIzolFlag   = false;
		} else BDT[BlockCount].StdCommentType[0] = false;
		if (CommentForm->AnshlagFlag) {
			BDT[BlockCount].StdCommentType[1] = true;
			CommentForm->AnshlagFlag   = false;
		} else BDT[BlockCount].StdCommentType[1] = false;
		if (CommentForm->CrossTubeFlag) {
			BDT[BlockCount].StdCommentType[2] = true;
			CommentForm->CrossTubeFlag   = false;
		} else BDT[BlockCount].StdCommentType[2] = false;

		if (CommentForm->CrossRoadFlag) {
			BDT[BlockCount].StdCommentType[3] = true;
			CommentForm->CrossRoadFlag   = false;
		} else BDT[BlockCount].StdCommentType[3] = false;

		if (CommentForm->TurnFlag) {
			BDT[BlockCount].StdCommentType[4] = true;
			CommentForm->TurnFlag   = false;
		} else BDT[BlockCount].StdCommentType[4] = false;

		if (CommentForm->BegOpenTubeFlag) {
			BDT[BlockCount].Depth = -9999;
			CommentForm->TurnFlag   = false;
		}

		if (CommentForm->EndOpenTubeFlag) {
			BDT[BlockCount].Depth = 9999;
			CommentForm->TurnFlag   = false;
		}

		TubeDepth = CB_DepthBox->Text.ToInt();
		BDT[BlockCount].Depth = Int(TubeDepth);
	}
	if (RunGPSFlag) {
		BDT[BlockCount].Way = fTotalDistance;
		BDT[BlockCount].Lat = d_lat;
		BDT[BlockCount].Lng = d_lng;
		BDT[BlockCount].Spd = fSpeed;
//		BDT[BlockCount].Depth = CB_DepthBox->Text.ToInt();
	}
	if (BlockCount == BLOCKSIZE-1) {                   // write block to disk
		for (int i=0; i<BLOCKSIZE; i++) fwrite(&BDT[i], sizeof(DT_STRUCT), 1, df);
	}
	if ((MetkaFlag) || (CommentFlag)) {
		CommentForm->TurnFlag   	 	 = false;
		CommentForm->BadIzolFlag   	 = false;
		CommentForm->AnshlagFlag   	 = false;
		CommentForm->CrossTubeFlag 	 = false;
		CommentForm->CrossRoadFlag 	 = false;
		CommentForm->BegOpenTubeFlag = false;
		CommentForm->EndOpenTubeFlag = false;
		MetkaFlag 			= false;
		CommentFlag 		= false;
		FastCommentFlag = false;
		PausedFlag 			= false;
		MetkaDoneFlag 	= true;
	}
	if (AUTORESTART == 0) return;
	if (iCount % AUTORESTART == 0) {
		CloseDTfile();
		OpenDTfile();
	}
}
//---------------------------------------------------------------------------
void  TMainForm::ClearPlot()
{
	Series1->Clear();
	Series2->Clear();
	Series3->Clear();
	Series7->Clear();

	Series1->Color = clRed;
	Series2->Color = clBlue;
	Series3->Color = clGreen;

	FastLineSeries1->Clear();
	FastLineSeries2->Clear();
	PointSeries1->Clear();

	FastLineSeries1->Color = clRed;
	FastLineSeries2->Color = clBlue;
}
//---------------------------------------------------------------------------
void TMainForm::OpenDTfile()
{
	Word Year, Month, Day, Hour, Min, Sec, MSec;

	TDateTime dtPresent = Now();
	DecodeDate(dtPresent, Year, Month, Day);
	DecodeTime(dtPresent, Hour, Min, Sec, MSec);
	// file name: 00_YYMMDD_HHMM.VDT
	OutputFileName = SForm->LeadZero(StrToInt(SForm->sDevNum), 2) + "_" +
		SForm->LeadZero(Year-2000, 2) + SForm->LeadZero(Month,2) + SForm->LeadZero(Day,2) +
		"_"+SForm->LeadZero(Hour,2) + SForm->LeadZero(Min,2);

	AnsiString s;
	DataBaseDir = GetCurrentDir() + "\\DB\\" + SForm->LeadZero(Year-2000, 2) + SForm->LeadZero(Month,2) + SForm->LeadZero(Day,2);
	if(!DirectoryExists(DataBaseDir))	MkDir(DataBaseDir);
	s = DataBaseDir + "\\" + OutputFileName + ".VDT";
	df = fopen(s.c_str(), "wb");    // main data file
	if (df==NULL)
		ShowMessage("Cannot open file " + s);
}
//---------------------------------------------------------------------------
void TMainForm::CloseDTfile()
{
	__int64     BlockCount = iCount % BLOCKSIZE;

	for (int i=0; i<BlockCount; i++) fwrite(&BDT[i], sizeof(DT_STRUCT), 1, df);
	fclose(df);

//	DataBaseDir = GetCurrentDir() + "\\DB\\" + SForm->LeadZero(Year-2000, 2) + SForm->LeadZero(Month,2) + SForm->LeadZero(Day,2);
//	if(!DirectoryExists(DataBaseDir))	MkDir(DataBaseDir);

	if (TestModeFlag) {
		AnsiString s0, s1;
		s0 = DataBaseDir + "\\" + OutputFileName + ".VDT";
		s1 = DataBaseDir + "\\T" + OutputFileName + ".VDT";
		RenameFile(s0, s1);
		for (int i = 0; i < C_Count; i++) {
			s0 = DataBaseDir + "\\" + OutputFileName+"_M"+IntToStr(i) + ".TXT";
			s1 = DataBaseDir + "\\T" + OutputFileName+"_M"+IntToStr(i) + ".TXT";
			try {
				RenameFile(s0, s1);
			} catch (...) {
			}
		}
	}
}
//---------------------------------------------------------------------------
double __fastcall TMainForm::Dist(double lt1, double lt2, double lg1, double lg2)   // distance between two points m
{
	double	offLat, offLng;

	LatCoeff = cos((lt1 + lt2) * PI / 360.0);

	if (!lt1 || !lt2) return 0;   // no coordinates

	offLat = (lt2-lt1) * 111120 * (lt2-lt1)* 111120;
	offLng = (lg2-lg1) * 111120 * LatCoeff * (lg2-lg1) * 111120 * LatCoeff;
	if ((offLat + offLng) > 0)
		return sqrt(offLat + offLng);
	else
		return 0;       // no move
}
//---------------------------------------------------------------------------
void TMainForm::ShowStatusBarInfo()
{
	Word Year, Month, Day, H, M, S, MSec;
	DecodeTime(GetTime()-fStartTime0, H, M, S, MSec);

	StatusBar1->Panels->Items[0]->Text  = SForm->LeadZero(H,2) +":" + SForm->LeadZero(M,2) +":" + SForm->LeadZero(S,2);
	StatusBar1->Panels->Items[1]->Text  = SForm->LeadZero(hour,2) +":" + SForm->LeadZero(min,2) + ":" + SForm->LeadZero(sek,2);

	StatusBar1->Panels->Items[2]->Text  = FloatToStrF(d_lat, ffFixed, 10, 6);
	StatusBar1->Panels->Items[3]->Text  = FloatToStrF(d_lng, ffFixed, 10, 6);
	StatusBar1->Panels->Items[4]->Text  = FloatToStrF(fSpeed, ffFixed,5, 1);          // Data_Array

	if ((SForm->iOutputType == 0) || (SForm->iOutputType == 3)) {
		StatusBar1->Panels->Items[6]->Text  = FloatToStrF(Data_Array[0], ffFixed,5, 1);
		StatusBar1->Panels->Items[7]->Text  = FloatToStrF(Data_Array[1], ffFixed,5, 1);
		StatusBar1->Panels->Items[8]->Text  = FloatToStrF(Data_Array[2], ffFixed,5, 1);
		StatusBar1->Panels->Items[9]->Text  = FloatToStrF(Data_Array[3], ffFixed,5, 1);
		StatusBar1->Panels->Items[10]->Text = FloatToStrF(Data_Array[4], ffFixed,5, 1);
		StatusBar1->Panels->Items[11]->Text = FloatToStrF(Data_Array[5], ffFixed,5, 1);
	} else {
		StatusBar1->Panels->Items[6]->Text  = FloatToStrF(CAV[0], ffFixed,5, 1);
		StatusBar1->Panels->Items[7]->Text  = FloatToStrF(CAV[1], ffFixed,5, 1);
		StatusBar1->Panels->Items[8]->Text  = FloatToStrF(CAV[2], ffFixed,5, 1);
		StatusBar1->Panels->Items[9]->Text  = FloatToStrF(CAV[3], ffFixed,5, 1);
		StatusBar1->Panels->Items[10]->Text = FloatToStrF(CAV[4], ffFixed,5, 1);
		StatusBar1->Panels->Items[11]->Text = FloatToStrF(CAV[5], ffFixed,5, 1);
	}
	Application->ProcessMessages();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetHorizontalAxis(Longint n)
{    // установка горизонтальных осей в режиме измерений с небольшим правым полем MARGINPOINT
	if (n < (MAXPOINT - MARGINPOINT)) {
		VizorPlot1->BottomAxis->Minimum = 0;
		VizorPlot1->BottomAxis->Maximum = MAXPOINT;
	 } else {
		VizorPlot1->BottomAxis->Maximum = n + MARGINPOINT;
		VizorPlot1->BottomAxis->Minimum = n - (MAXPOINT-MARGINPOINT);
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Timer1Timer(TObject *Sender)
{
	if (!RunFlag) return;
	Application->ProcessMessages();
	if (NoKMDFlag) {
		AddRecordToDTfile();
	}
	ShowDataToPlot(iCount);   			// вывод на график
	ShowStatusBarInfo();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Timer2Timer(TObject *Sender)
{
	GPSReadyFlag = true;
	if (UseGPSFlag) TrackForm->ShowSpeedInfo(d_lat, d_lng); // marker on the track
	if ((!RunFlag) || (PausedFlag) || (NoKMDFlag)) return;
	NoDataCount++;
	if (NoDataCount > 5) Beep();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::VizorPlot1DblClick(TObject *Sender)
{
	VizorPlot1->LeftAxis->Automatic = true;
	VizorPlot1->MarginLeft = 5; //m;
}
//---------------------------------------------------------------------------
bool TMainForm::DecodeGPS(AnsiString sG, double & s_lat, double & s_lng)
{
//        time        lat             long           type  SatNum
//$GPGGA,123519   ,  4807.03800000,N,01131.00000000,E, 1    ,08    ,0.9,545.4,M,46.9,M,,*47
//        time        lat             long            скор  курс
//$GPRMC,142954.60,A,6020.01528953,N,03022.62449359,E,0.007,288.4,130221,11.0,E
	AnsiString s0 = sG, s, t, d;
	bool bRMCflag = false;
	int n = 0;
	int DecisionType, HDOP;
	SatNum = 0;
//	static double pLat, pLng;

	bRMCflag = (sG.Pos("RMC") > 0);
	try {
		s = "";
		while (s0[++n] != ',') s += s0[n];  // $GPGGA                                                         +
		s = "";
		while (s0[++n] != ',') s += s0[n];  // time
		if (s != "") {
			hour 		= s.SubString(1,2).ToInt();
			min  		= s.SubString(3,2).ToInt();
			sek  		= s.SubString(5,2).ToInt();
			StatusBar1->Panels->Items[1]->Text = SForm->LeadZero(hour,2) +":"+ SForm->LeadZero(min,2) +":" + SForm->LeadZero(sek,2);
		}
		if (bRMCflag) {   // quality A - good   V - bad
			s = "";
			while (s0[++n] != ',') s += s0[n];
			if (s != "A") return false;
		}
		s = "";
		while (s0[++n] != ',') s += s0[n];  // latitude
		if (s != "")
			s_lat  = StrToInt(s.SubString(1, 2))+StrToFloat(s.SubString(3,2)+"."+s.SubString(6,4))/60; else s_lat = 0;
		while (s0[++n] != ',');   // pass "N,"
		if (s0[n-1] == 'S') s_lat = -s_lat;
		if (((s0[n-1] != 'N') && (s0[n-1] != 'S')) || (s_lat == 0)) return false;

		s = "";
		while (s0[++n] != ',') s += s0[n];  // longitude
		if (s != "")
			s_lng  = StrToInt(s.SubString(1, 3))+StrToFloat(s.SubString(4,2)+"."+s.SubString(7,4))/60; else s_lng = 0;
		while (s0[++n] != ',');   // pass "E,"
		if (s0[n-1] == 'W') s_lng = -s_lng;
		if (((s0[n-1] != 'E') && (s0[n-1] != 'W')) || (s_lng == 0)) return false;
		if (!bRMCflag) {
			// Fix Quality: 0 = Invalid 1 = GPS fix  2 = DGPS fix
			s = "";
			while (s0[++n] != ',') s += s0[n];
			DecisionType = s.ToInt();
		//		if (!DecisionType) return false;
		// Number of Satellites
			s = "";
			while (s0[++n] != ',') s += s0[n];
			if (s != "") 	SatNum = s.ToInt();
		}
		Application->ProcessMessages();
	} catch (...) {
		return false;
	}
	return true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ShowGPSData()
{
	TrackForm->L_CoordCount->Caption 		= CoordCount;
	TrackForm->L_BadCoordCount->Caption = BadCoordCount;
	L_SatNum->Caption = SatNum;
	Edit_Way0->Text   = FloatToStrF(fDistanceFromStart, ffFixed,8,0);
//	TrackForm->Label_totSpeed->Caption   = int(fDistanceFromStart);
	Label_Way1->Caption   = int(fTotalDistance);
	TrackForm->Label_Way1->Caption   = int(fTotalDistance);
	TrackForm->Series_Track->AddXY(d_lng, d_lat, "", clGreen);
	ShowStatusBarInfo();
	Application->ProcessMessages();
}
//---------------------------------------------------------------------------
void TMainForm::ShowGPS(DWORD  BytesRead)      // sent from GPS thread
{
	AnsiString s = "";
	GPSReadyFlag = false;
	Application->ProcessMessages();
	for (int k=0; k<BytesRead; k++) s += G[k];
	if (DecodeGPS(s, d_lat, d_lng)) {
		L_StartLng->Caption = FloatToStrF(d_lng, ffFixed, 9, 6);
		L_StartLat->Caption = FloatToStrF(d_lat, ffFixed, 9, 6);
		if (!CoordCount) {      // first point
			RunGPSFlag  = true;
			fStartLat  	= d_lat;
			fStartLong 	= d_lng;
			TrackForm->FirstPointSeries->AddXY(d_lng, d_lat, "", clRed);
			TrackForm->SetIniCoordAxis(d_lng, d_lat);
			LatCoeff = cos(fStartLat*PI/180.0);
			++CoordCount;
			return;
		}
		++CoordCount;

		if (MaxLat < d_lat)  MaxLat = d_lat;
		if (MaxLng < d_lng)  MaxLng = d_lng;
		if (MinLat > d_lat)  MinLat = d_lat;
		if (MinLng > d_lng)  MinLng = d_lng;

		// перемещение от точки старта:
		fDistanceFromStart = Dist(fStartLat, d_lat, fStartLong, d_lng);
		if (RunFlag) {
			// перемещение от предыдущей точки комментария:
			fTotalDistance = fTotalDistance0 + Dist(fPrLat, d_lat, fPrLong, d_lng);
		}
		TrackForm->Series_Track->AddXY(d_lng, d_lat, "", clGreen);
		TrackForm->SetCoordAxis(d_lng, d_lat);
		ShowGPSData();
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ShowDataToPlot(Longint n)   // вывод графиков в режиме измерений
{
	int     c1, c2, c3, c4, c5, c6;
	SetHorizontalAxis(n);
	switch (SForm->iOutputType) {
	 case 0:
		if (V1) Series1->AddXY(n, V1, "", clRed);
		if (V2) Series2->AddXY(n, V2, "", clBlue);
		if (VB) Series3->AddXY(n, VB, "", clGreen);
		break;
	 case 1:
		FastLineSeries1->AddXY(n, VA1, "", clRed);
		FastLineSeries2->AddXY(n, VA2, "", clBlue);
		break;
	 case 2:
		if (V1) Series1->AddXY(n, V1, "", clRed);
		if (V2) Series2->AddXY(n, V2, "", clBlue);
		FastLineSeries1->AddXY(n, VA1, "", clRed);
		FastLineSeries2->AddXY(n, VA2, "", clBlue);
		break;
	 case 3:
		Series1->AddXY(n, Data_Array[3], "", clRed);
		Series2->AddXY(n, Data_Array[4], "", clBlue);
		Series3->AddXY(n, Data_Array[5], "", clGreen);
		break;
	}
	if (UseGPSFlag) TrackForm->ShowTimeInfo(d_lat, d_lng); // marker on the track
	if (CommentFlag) {
		if (SForm->iOutputType == 0) Series7->AddXY(n, V1, "", clBlue);                                   				// marker on the plot1
		if (SForm->iOutputType == 1) PointSeries1->AddXY(n, VA1, "", clBlue);                             				// marker on the plot2
		if (SForm->iOutputType == 3) Series7->AddXY(n, Data_Array[3], "", clBlue);                                // marker on the plot1
		if (UseGPSFlag) TrackForm->MarkerSeries->AddXY(d_lng, d_lat, "", clGreen);; // marker on the track
	}
}
//---------------------------------------------------------------------------
void TMainForm::ProccessRecord()
{
	if (NoKMDFlag) {
		for (int k=0; k < 9; k++) {
			Data_Array[k] = 0;
		}
	}
	int j;
	for (int k=0; k < 6; k++) {          // average values
		(UseBGrndFlag) ? j = k + 3 : j = k;                       //  при использовании фонового прибора первые 3 значения CAV - средние
		CAV[k] = (CAV[k] * ikCount + Data_Array[j]) /(ikCount+1);   //  по нижнему датчику, а три последних - средний фон

//		if (!UseBGrndFlag) {
//			if ((ikCount < 10) || (fabs(CAV[k] - Data_Array[k])) < 6.0)
//				CAV[k] = CAV[k] * ikCount/(ikCount+1) + Data_Array[k]/(ikCount+1);
//		} else {
//			if ((ikCount < 10) || (fabs(CAV[k] - Data_Array[k+3])) < 6.0)
//				CAV[k] = CAV[k] * ikCount/(ikCount+1) + Data_Array[k+3]/(ikCount+1);
//		}
		//	disp:		if (i>0) ZDd = ZDd*(i-1)/i + (fADT[N].DT_DATA[9]-ZDs)*(fADT[N].DT_DATA[9]-ZDs)/i;
	}
	ikCount++;    // счетчик измерений для прямолин участка
	if (!CommentFlag) {  // если был комментарий, то остаются пред.знач.
		// full vectors:
		V1 = Sqrt(Data_Array[0] *Data_Array[0]  + Data_Array[1]*Data_Array[1] + Data_Array[2]*Data_Array[2]);    // верхний
		V2 = Sqrt(Data_Array[3] *Data_Array[3]  + Data_Array[4]*Data_Array[4] + Data_Array[5]*Data_Array[5]);    // нижний
		if (UseBGrndFlag)
			VB = Sqrt(Data_Array[6] *Data_Array[6]  + Data_Array[7]*Data_Array[7] + Data_Array[8]*Data_Array[8]);    // BG
		else
			VB = Sqrt(CAV[3]*CAV[3]  + CAV[4]*CAV[4] + CAV[5]*CAV[5]);    // BG
		// anomaly vectors:
		if (!UseBGrndFlag) {
			VA1 = Sqrt((Data_Array[0] - CAV[0])*(Data_Array[0] - CAV[0]) + (Data_Array[1] - CAV[1])*(Data_Array[1] - CAV[1]) + (Data_Array[2] - CAV[2])*(Data_Array[2] - CAV[2]));    // верхний
			VA2 = Sqrt((Data_Array[3] - CAV[3])*(Data_Array[3] - CAV[3]) + (Data_Array[4] - CAV[4])*(Data_Array[4] - CAV[4]) + (Data_Array[5] - CAV[5])*(Data_Array[5] - CAV[5]));    // нижний
		} else {
			VA1 = Sqrt((Data_Array[0] - CAV[3])*(Data_Array[0] - CAV[3]) + (Data_Array[1] - CAV[4])*(Data_Array[1] - CAV[4]) + (Data_Array[2] - CAV[5])*(Data_Array[2] - CAV[5]));    // верхний
			VA2 = Sqrt((Data_Array[3] - CAV[3])*(Data_Array[3] - CAV[3]) + (Data_Array[4] - CAV[4])*(Data_Array[4] - CAV[4]) + (Data_Array[5] - CAV[5])*(Data_Array[5] - CAV[5]));    // нижний
		}
	}
	StaticText_PlotN->Caption = IntToStr(iCount);
	StaticText_Plot1->Caption = FloatToStrF(V1, ffFixed, 5, 0);
	StaticText_Plot2->Caption = FloatToStrF(V2, ffFixed, 5, 0);
	StaticText_BGrnd->Caption = FloatToStrF(VB, ffFixed, 5, 0);
//	StaticText_Plot1->Caption = FloatToStrF(Data_Array[6], ffFixed, 5, 1);
//	StaticText_Plot2->Caption = FloatToStrF(Data_Array[7], ffFixed, 5, 1);
//	StaticText_BGrnd->Caption = FloatToStrF(Data_Array[8], ffFixed, 5, 1);
	fDistanceFromStart = Dist(fStartLat, d_lat, fStartLong, d_lng);
	Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
void TMainForm::ShowKMD(DWORD  BytesRead)        // get data from KMD thread
{
	ReadyFlag  = false;

	int static InfoCount = 0;
	if (PausedFlag) return;
	Timer1->Enabled = true;

	bool		uFlag=false, dFlag=false, bgFlag=false;
	double	x1,y1,z1,x2,y2,z2,xb,yb,zb;
	signed char		x1h,y1h,z1h,x2h,y2h,z2h,xbh,ybh,zbh;
	unsigned char	x1l,y1l,z1l,x2l,y2l,z2l,xbl,ybl,zbl;


//	for (int k = 1; k < DATABUF-18; k++) {
	int k = 0;
	do {
		if ((D[k]==0x0D)&&(D[k+1]==0x0A)&&(D[k+2]==0x31)) {              // bottom sensor
			x2h = D[k+7]; x2l = D[k+8];
			x2  = (x2h*256 + x2l)/150.0;
			y2h = D[k+5]; y2l = D[k+6];
			y2  = (y2h*256 + y2l)/150.0;
			z2h = D[k+3]; z2l = D[k+4];
			z2  = (z2h*256 + z2l)/150.0;
			Data_Array[3] =  x2;
			Data_Array[4] =  y2;
			Data_Array[5] = -z2;
			if (!iCount) {
				for (int i = 3; i < 6; i++) pr[i] = Data_Array[i];
			} else {  // if big difference then set the previous value
				for (int i = 3; i < 6; i++) if (fabs(Data_Array[i]-pr[i]) > ERRTHRESHOLD) Data_Array[i] = pr[i];
				for (int i = 3; i < 6; i++) pr[i] = Data_Array[i];
			}
			dFlag = true;
			k += 8;
		}
		if ((D[k]==0x0D)&&(D[k+1]==0x0A)&&(D[k+2]==0x32)) {            // top sensor
			x1h = D[k+7];  x1l = D[k+8];
			x1 = (x1h*256 + x1l)/150.0;
			y1h = D[k+5];  y1l = D[k+6];
			y1 = (y1h*256 + y1l)/150.0;
			z1h = D[k+3]; z1l = D[k+4];
			z1 = (z1h*256 + z1l)/150.0;

			Data_Array[0] =  x1;
			Data_Array[1] = -y1;
			Data_Array[2] =  z1;
			if (!iCount) {
				for (int i = 0; i < 3; i++) pr[i] = Data_Array[i];   // first measure
			} else {  // if big difference then set the previous value
				for (int i = 0; i < 3; i++) if (fabs(Data_Array[i]-pr[i]) > ERRTHRESHOLD) Data_Array[i] = pr[i];
			}
			for (int i = 0; i < 3; i++) pr[i] = Data_Array[i];
			uFlag = true;
			k += 8;
		}
		if (!UseBGrndFlag)
			bgFlag = true;
		else {
			if ((D[k]==0x0D)&&(D[k+1]==0x0A)&&(D[k+2]==0x33)) {            // backgrnd sensor
				xbh = D[k+7];  xbl = D[k+8];
				xb = (xbh*256 + xbl)/150.0;
				ybh = D[k+5];  ybl = D[k+6];
				yb = (ybh*256 + ybl)/150.0;
				zbh = D[k+3]; zbl = D[k+4];
				zb = (zbh*256 + zbl)/150.0;

				Data_Array[6] =  xb;
				Data_Array[7] = -yb;
				Data_Array[8] =  zb;
				if (!iCount) {
					for (int i = 6; i < 9; i++) pr[i] = Data_Array[i];   // first measure
				} else {  // if big difference then set the previous value
					for (int i = 6; i < 9; i++) if (fabs(Data_Array[i]-pr[i]) > ERRTHRESHOLD) Data_Array[i] = pr[i];
				}
				for (int i = 6; i < 9; i++) pr[i] = Data_Array[i];
				bgFlag = true;
				k += 8;
			}
		}
		if ((uFlag && dFlag && bgFlag) || NoKMDFlag) {
			NoDataCount	  = 0;
			ProccessRecord();
			AddRecordToDTfile();
			uFlag	 = false;
			dFlag	 = false;
			bgFlag = false;
		}
		if ((D[k]==0x0D) && (D[k+1]==0x0A) && (D[k+2]=='$')) {            // $GPGGA,204730.00,6020.02484,N,03022.61658,E,1,09,1.03,89.2,M,15.9,M,,*6A  from internal GPS
			String	sGPS = "";
			double  lat, lng;
			for (int i = 0; i < 60; i++) {
				if (k + i < BytesRead)
					sGPS += D[k+i];
				else
					break;
			}
			if (DecodeGPS(sGPS, lat, lng)) {
				TrackForm->Series1->AddXY(lng, lat, "", clGreen);
				InternalGPSflag = true;
				ShowTrackButton->Enabled  = true;
				d_lat = lat;
				d_lng = lng;
      }
		}
		k++;
//	}
	} while (k < BytesRead-9);  // for (int k = 1; k < DATABUF-18; k++)
	ShowStatusBarInfo();
	ReadyFlag  = true;
}
//---------------------------------------------------------------------------
void TMainForm::ShowHour(bool bShow)
{
	if (bShow)
		Screen->Cursor = crHourGlass;
	 else
		Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------
void TMainForm::GPSResult(bool bShow)
{
	MainForm->RunGPSFlag = true;
	MainForm->ShowHour(false);
	MainForm->GPSLabel->Caption = MainForm->GPSComPort;
	if (RunGPSFlag) {
		dSumLat 		=		 0;
		dSumLng 		=    0;
		MaxLat			=  -90;
		MinLat			=	  90;
		MaxLng			=	-180;
		MinLng			=  180;
		EmptyStrCount = 0;
	}
	AbortFlag = false;
	ShowButtonStatus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::GPSButtonClick(TObject *Sender)
{
	if (GPSComPort == "")  {
		if (BthGPSname.Pos("COM") == 1)
			GPSComPort = BthGPSname;
		 else
			GPSComPort = GetCOMnum(BthGPSname);
	}
	if (GPSComPort == "") {
		ShowMessage("No GPS device");
	} else {
		ShowHour(true);
		GPSThread = new TGPS(false) ;
		GPSThread->FreeOnTerminate = true;
		GPSReadyFlag      = true;
	}
	Timer2->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormShortCut(TWMKey &Msg, bool &Handled)
{
	TWMKey	c;
	switch (Msg.CharCode) {
		case VK_ESCAPE: AbortFlag = true; Handled = true; break;
	default:
		CtrlFlag = (Msg.CharCode == 17);            // Ctrl key
		;
	}
	Application->ProcessMessages();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ShowTrackButtonClick(TObject *Sender)
{
	TrackForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetButtonClick(TObject *Sender)
{
	SForm->Show();
}
//---------------------------------------------------------------------------
void TMainForm::ShowWayButtonStatus()
{
	ButtonWay1->Caption = sWay.ToInt();      // 50;
	ButtonWay2->Caption = sWay.ToInt() - sWay.ToInt()%MarkerStep + MarkerStep;  // 100;
	ButtonWay3->Caption = sWay.ToInt() - sWay.ToInt()%MarkerStep + MarkerStep * 2;  // 150;
	ButtonWay1->Enabled = RunFlag;
	ButtonWay2->Enabled = RunFlag;
	ButtonWay3->Enabled = RunFlag;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SaveCommentFile(AnsiString s)
{
	FILE  * tf; 		// *.TXT file
	FastCommentFlag 	= true;
	CommentFlag = true;

	AnsiString FN = DataBaseDir + "\\" + OutputFileName+"_M"+IntToStr(C_Count++) + ".TXT";
	tf  			= fopen(FN.c_str(), "wt");       // writing comment file
	fprintf(tf, s.c_str());
	fclose(tf);
	ShowDataToPlot(iCount);
	AddRecordToDTfile();
}
//---------------------------------------------------------------------------
void TMainForm::RenewTotalDistance()
{
	fPrLat	= d_lat;
	fPrLong = d_lng;
	fTotalDistance0 = fTotalDistance;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DoButtonWay(AnsiString s)
{
	if (!RunFlag) return;

	Timer1->Enabled = false;
	sWay 			= s;
	if ((C_Count == 1) && (CommentForm->Memo_TextMetka->Text != ""))
		s = s + " m. " + CommentForm->Memo_TextMetka->Text;    // repeat first comment
	if (CommentForm->Edit_Depth->Text.Length()>0) {
		s = s + ". (Глубина: " + CommentForm->Edit_Depth->Text + ")";
	}
	RenewTotalDistance();
	SaveCommentFile(s);
	sWay 	 = IntToStr(sWay.ToInt() + MarkerStep);
	ShowWayButtonStatus();
	Application->ProcessMessages();
	Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::IzolMarkButtonClick(TObject *Sender)
{
	DoFastComment(0);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::KIPMarkButtonClick(TObject *Sender)
{
	DoFastComment(1);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CrossMarkButtonClick(TObject *Sender)
{
	DoFastComment(2);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RoadMarkButtonClick(TObject *Sender)
{
	DoFastComment(3);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TurnMarkButtonClick(TObject *Sender)
{
	DoFastComment(4);
	ikCount				= 0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::BegOpenTubeButtonClick(TObject *Sender)
{
	DoFastComment(6);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::EndOpenTubeButtonClick(TObject *Sender)
{
	DoFastComment(7);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TopArrowButtonClick(TObject *Sender)
{
	VizorPlot1->Axes->Left->Automatic = false;
	VizorPlot1->Axes->Left->Maximum += 10;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::BotArrowButtonClick(TObject *Sender)
{
	VizorPlot1->Axes->Left->Automatic = false;
	VizorPlot1->Axes->Left->Minimum -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ButtonWay1Click(TObject *Sender)
{
	DoButtonWay(ButtonWay1->Caption);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ButtonWay2Click(TObject *Sender)
{
	DoButtonWay(ButtonWay2->Caption);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ButtonWay3Click(TObject *Sender)
{
	DoButtonWay(ButtonWay3->Caption);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender)
{
	ShowButtonStatus();
}
//---------------------------------------------------------------------------
double __fastcall TMainForm::GetMax(double x, double y)
{
	double d;
	(x>y) ? d=x : d=y;
	return d;
}
//---------------------------------------------------------------------------
double __fastcall TMainForm::GetMin(double x, double y)
{
	double d;
	(x<y) ? d=x : d=y;
	return d;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_DepthBoxKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)
{
	TubeDepth = CB_DepthBox->Text.ToInt();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_DepthBoxCloseUp(TObject *Sender)
{
	TubeDepth = CB_DepthBox->Text.ToInt();
}
//---------------------------------------------------------------------------
void TMainForm::NoDataAlarm()
{
	Beep();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DoFastComment(int n)
{
//	if (!RunFlag && !NoKMDFlag) return;
	AnsiString s = "";

	if (fTotalDistance>0) s = FloatToStrF(fTotalDistance, ffFixed, 5, 0) + ". ";

	Timer1->Enabled = false;
	switch (n) {
		case 0: CommentForm->BadIzolFlag   = true; s += "Повреждение изоляции"; break;
		case 1: CommentForm->AnshlagFlag   = true; s += "КИП, аншлаг и пр."; break;
		case 2: CommentForm->CrossTubeFlag = true; s += "Пересечение"; break;
		case 3: CommentForm->CrossRoadFlag = true; s += "Дорога"; break;
		case 4: CommentForm->TurnFlag      = true; s += "Поворот"; break;
		case 5: CommentForm->TurnFlag      = true; s += "Финиш"; break;
		case 6: CommentForm->BegOpenTubeFlag = true; s += "Откр.труба начало";
						OpenTubeFlag = true;
						break;
		case 7: CommentForm->EndOpenTubeFlag = true; s += "Откр.труба конец";
						OpenTubeFlag = false;
						break;
	}
	SaveCommentFile(s);
	RenewTotalDistance();
	ShowButtonStatus();
	Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CommentButtonClick(TObject *Sender)
{
	if (!RunFlag && !PausedFlag && !NoKMDFlag) return;
	PausedFlag  = true;
	Timer1->Enabled = false;
	MetkaDoneFlag = false;
	CommentFlag = true;
	CommentForm->sTime 		= TimeToStr(Now());
	CommentForm->sLat 		= IntToStr(int(d_lat)) + "." + FloatToStrF((d_lat - int(d_lat))*100, ffFixed, 6, 3) + "N";
	CommentForm->sLong 		= IntToStr(int(d_lng)) + "." + FloatToStrF((d_lng - int(d_lng))*100, ffFixed, 6, 3) + "E";
	CommentForm->FN = DataBaseDir + "\\" + OutputFileName+"_M"+IntToStr(C_Count);
	CommentForm->MetkaNum = C_Count++;
	CommentForm->ShowModal();
	ShowDataToPlot(iCount);
	AddRecordToDTfile();
	RenewTotalDistance();
	Application->ProcessMessages();
	PausedFlag 			= false;
	if (CommentForm->TurnFlag) ikCount = 0;
	CommentForm->ResetFlags();
	Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetOutput(int iOutputType)
{
	Timer1->Enabled = false;
	SetIniVerticalAxis(iOutputType);
	switch (iOutputType) {
	 case 0:
		FastLineSeries1->Visible = false;
		FastLineSeries2->Visible = false;
		PointSeries1->Visible    = false;
		Series1->Visible = true;
		Series2->Visible = true;
		Series3->Visible = false;
		Series7->Visible = true;
		break;
	case 1:
		FastLineSeries1->Visible = true;
		FastLineSeries2->Visible = true;
		PointSeries1->Visible    = true;
		Series1->Visible = false;
		Series2->Visible = false;
		Series3->Visible = false;
		Series7->Visible = false;
		break;
	case 2:
		FastLineSeries1->Visible = true;
		FastLineSeries2->Visible = true;
		PointSeries1->Visible    = false;
		Series1->Visible = true;
		Series2->Visible = true;
		Series3->Visible = false;
		Series7->Visible = true;
		break;
	case 3:
		FastLineSeries1->Visible = false;
		FastLineSeries2->Visible = false;
		PointSeries1->Visible    = false;
		Series1->Visible = true;
		Series2->Visible = true;
		Series3->Visible = true;
		Series7->Visible = true;
		break;
	}
	Application->ProcessMessages();
	Timer1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CBox_TestFileClick(TObject *Sender)
{
	TestModeFlag = CBox_TestFile->Checked;
}
//---------------------------------------------------------------------------


