//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
#include "KMDUnit.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TKMD::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TKMD::TKMD(bool CreateSuspended)	: TThread(CreateSuspended)
{
	RunKMDFlag = false;
	KMDport    = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TKMD::Execute()
{
	if (StartKMD()) {
		RunKMDFlag = true;
		Synchronize(ShowResult);
		AcceptKMDData();
		StopKMD();
  } else {
		MainForm->ShowHour(false);
		MainForm->KMDThread = NULL;
		ShowMessage("           Connection error " + m_lLastError);
		MainForm->RunFlag = false;
    MainForm->ShowButtonStatus();
	}
}
//---------------------------------------------------------------------------
void __fastcall TKMD::ShowResult()
{
	MainForm->KMDResult(RunKMDFlag);
}
//---------------------------------------------------------------------------
void __fastcall 	TKMD::SendAlarm()
{
	MainForm->NoDataAlarm();
}
//---------------------------------------------------------------------------
void __fastcall TKMD::ShowData()
{
	long k=0;
	if (MainForm->PausedFlag) return;
	while (!MainForm->ReadyFlag) {
		k++;
		if (k>99999999) return;
	}
	for (int i = 0; i < BytesRead; i++) MainForm->D[i] = buf[i];
	MainForm->ShowKMD(BytesRead);
}
//---------------------------------------------------------------------------
bool __fastcall TKMD::StartKMD()
{
	COMMTIMEOUTS  lpCommTimeouts;
	sComPort = "\\\\.\\" + MainForm->KMDComPort;
	Application->ProcessMessages();
	KMDport = CreateFile(sComPort.c_str(), GENERIC_READ | GENERIC_WRITE, 0,	NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	Sleep(250);
	m_lLastError = GetLastError();
	if(!GetCommState(KMDport, &lpDCB))	{
		m_lLastError = ::GetLastError();
		KMDport = NULL;
		sComPort= "";
		return false;
	}
	lpDCB.BaudRate = 115200;
	lpDCB.ByteSize = 8;
	lpDCB.Parity   = NOPARITY;
	lpDCB.StopBits = ONESTOPBIT;
	Sleep(180);

	if (!SetCommState(KMDport, &lpDCB)) {
		sComPort="";
		return false;
	}
	OpenDataDir();
	return true;
}
//---------------------------------------------------------------------------
void TKMD::OpenDataDir()
{
	TDateTime dtPresent = Now();
	DecodeDate(dtPresent, Year, Month, Day);
	sCurPath  = GetCurrentDir();
	sDataPath = sCurPath  + "\\DB\\" + LeadZero(Year-2000, 2) + LeadZero(Month,2) + LeadZero(Day,2);
	if(!DirectoryExists(sDataPath))
		MkDir(sDataPath);
}
//---------------------------------------------------------------------------
void TKMD::AcceptKMDData()
{
	FILE 	 *f;
	AnsiString s = sDataPath + "\\KMD.RAW";
	AnsiString s1;

	f  = fopen(s.c_str(), "ab+");
	fprintf(f,"=============================\n");
	s1 = TimeToStr(Time());
	fprintf(f,"%%START : %8s \n", s1);
	while (!Terminated) {
		ReadFile(KMDport, buf, sizeof(&buf), &BytesRead, NULL);
		fwrite(buf, BytesRead, 1, f);
		if (BytesRead) {
			Synchronize(ShowData);      // send buf to MainForm
			EmptyStrCount = 0;
		} else {
			EmptyStrCount++;
			if (EmptyStrCount > 10) {
				Synchronize(SendAlarm);
				EmptyStrCount = 0;
			}
		}
	}
	s1 = TimeToStr(Time());
	fprintf(f,"\n");
	fprintf(f,"%%FINISH: %8s \n", s1);
	fprintf(f,"=============================\n");
	fclose(f);
}
//---------------------------------------------------------------------------
void __fastcall TKMD::StopKMD()
{
	if (KMDport != NULL) {
		CloseHandle(KMDport);
		KMDport = NULL;
	}
}
//---------------------------------------------------------------------------
String TKMD::LeadZero(int k, int dig)
{
	AnsiString s;
	s=Trim(IntToStr(k));
	while (s.Length() < dig) s = "0" + s;
	return s;
}
//---------------------------------------------------------------------------
