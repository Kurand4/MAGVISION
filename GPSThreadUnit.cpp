//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
#include "GPSThreadUnit.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall GPSThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall GPSThread::GPSThread(bool CreateSuspended)
	: TThread(CreateSuspended)
{
	GPSport 			= 0;
	RunGPSFlag 		= false;
	BadCoordCount	=	0;
	GPSCount			= 0;
}
//---------------------------------------------------------------------------
void __fastcall GPSThread::Execute()
{
	if (StartGPS()) {
		Synchronize(ShowResult);
		AcceptGPSData();
		StopGPS();
	}
}
//---------------------------------------------------------------------------
void __fastcall GPSThread::ShowStartData()
{
	MainForm->RunGPSFlag = true;
	MainForm->fStartLat  	= d_lat;
	MainForm->fStartLong 	= d_long;
	MainForm->L_StartLng->Caption = FloatToStrF(d_long, ffFixed, 9, 6);
	MainForm->L_StartLat->Caption = FloatToStrF(d_lat, ffFixed, 9, 6);
}
//---------------------------------------------------------------------------
void __fastcall GPSThread::ShowCurrentData()
{
	MainForm->RunGPSFlag = true;
	MainForm->d_lat  	= d_lat;
	MainForm->d_long 	= d_long;
	MainForm->fSpeed 	= fSpeed;
	MainForm->fKurs 	= fKurs;
}
//---------------------------------------------------------------------------
void __fastcall GPSThread::ShowResult()
{
	MainForm->GPSLabel->Caption = MainForm->GPSComPort;
	MainForm->RunGPSFlag = true;
}
//---------------------------------------------------------------------------
bool __fastcall GPSThread::StartGPS()
{
	TDCB		Comm_DCB;
	if (GPSport != 0) return true;

	AnsiString	s;
	int i;
		sComPort = "\\\\.\\" + MainForm->GPSComPort;
		GPSport = CreateFile(sComPort.c_str(), GENERIC_READ | GENERIC_WRITE, 0,	NULL, OPEN_EXISTING, 0, NULL);
		m_lLastError = GetLastError();
		if (!m_lLastError) MainForm->GPSLabel->Caption = MainForm->GPSComPort;
	if(!GetCommState(GPSport, &lpDCB))	{
		m_lLastError = ::GetLastError();
		GPSport = 0;
		sComPort="";
		return false;
	}
	GetCommTimeouts(GPSport, &lpCommTimeouts);
	if (MainForm->GPSComName == "USBSER") {
		lpDCB.BaudRate = 115200;
	} else {
		lpDCB.BaudRate = 4800;
	}
	lpDCB.ByteSize = 8;
	lpDCB.Parity   = NOPARITY;
	lpDCB.StopBits = ONESTOPBIT;
	if (!SetCommState(GPSport, &lpDCB)) sComPort="";
	if (!SetCommTimeouts(GPSport, &lpCommTimeouts)) sComPort="";
	StopFlag	 = false;
	Sleep(1000);
	return true;
}
//---------------------------------------------------------------------------
void __fastcall GPSThread::StopGPS()
{
	MainForm->GPSLabel->Caption = "_____";
}
//---------------------------------------------------------------------------
void __fastcall GPSThread::ShowCoord()
{
}
//---------------------------------------------------------------------------
bool GPSThread::DecodeGPS(AnsiString s0, double &d_time,  double &lat, double &lng)
{
// time        lat      long     speed(not) course  date
// 043941.000,A,6020.0178,N,03022.6208,E,0.12,53.13,130609,,*37
	AnsiString s, t, d;
	double s_lat, s_lng;
	double hour, min, sek, dsek;
	int n = 0;
	try {
		s = "";
		while (s0[++n] != ',') s += s0[n];  // time
//		t 	= s.SubString(1, 2)+":"+s.SubString(3,2)+":"+s.SubString(5,2);
		hour 		= StrToFloat(s.SubString(1,2));
		min  		= StrToFloat(s.SubString(3,2));
		sek  		= StrToFloat(s.SubString(5,2));
		dsek 		= StrToFloat(s.SubString(8,3));
		d_time 	= hour + min/60 + sek/3600 + dsek/3600000;

		while (s0[++n] != ',');   // pass "A,"

		s = "";
		while (s0[++n] != ',') s += s0[n];  // latitude
		lat  = StrToInt(s.SubString(1, 2))+StrToFloat(s.SubString(3,2)+"."+s.SubString(6,4))/60;
		while (s0[++n] != ',');   // pass "N,"
		if (s0[n-1] != 'N') lat = -lat;

		s = "";
		while (s0[++n] != ',') s += s0[n];  // longitude
		lng  = StrToInt(s.SubString(1, 3))+StrToFloat(s.SubString(4,2)+"."+s.SubString(7,4))/60;
		while (s0[++n] != ',');   // pass "E,"
		if (s0[n-1] != 'E') lng = -lng;

		s = "";
		while (s0[++n] != ',' && n < s0.Length()) s += s0[n];   //    speed
		if (s.Length()>2) fSpeed = StrToFloat(s) * 1852.0 / 3600.0;

		s = "";
		while (s0[++n] != ',' && n < s0.Length()) s += s0[n];   //    course
		if (s.Length()>2) fKurs = StrToFloat(s);
	} catch (...) {
		return false;
	}
	return true;
}
//---------------------------------------------------------------------------
AnsiString GPSThread::GetGPSstring()           		// returns data string from GPS
{
	char 	buf[512];
	DWORD   BytesRead;
	AnsiString 	s = "";
	unsigned short 	n = 0;

	ReadFile(GPSport, buf, sizeof(&buf), &BytesRead, NULL);
	if (BytesRead)
	while (n < BytesRead-60) {
		n++;
		if (buf[n] == '$') {
//			for (int i = 0; i < 7; i++) s += buf[i+n];
//			n += 7;
//			if ((s == "$GPRMC,") || (s == "$GNRMC,")) {
			if ((buf[n+1]=='G') && ((buf[n+2]=='N') || (buf[n+2]=='P')) && (buf[n+3]=='R') && (buf[n+4]=='M') && (buf[n+5]=='C')) {
			  n += 7;
				s = "";
				for (int i = 0; i < 60; i++) s += buf[i+n];
				break;
			} else {
				s = "";
			}
		}
	}
	return s;
}
//---------------------------------------------------------------------------
void GPSThread::AcceptGPSData()   	// set current values of coordinates and speed
{
	AnsiString 	s = "";
	AnsiString	dt, t, lat, lng;

	Sleep(1000);
	while (!StopFlag) {
//		Sleep(100);
		s = GetGPSstring();
		if (s.Length()>50) {
			try {
				if (DecodeGPS(s, d_time, d_lat, d_long)) {
					if (StartFlag) {
						StartFlag = false;
						RunGPSFlag = true;
						MainForm->fPrLat = d_lat;
						MainForm->fPrLong = d_long;
						Synchronize(&ShowStartData);
					}
					if (fSpeed < 0.3) fSpeed = 0;
//					MainForm->fSpeed = fSpeed;
//					MainForm->fKurs	 = fKurs;
//					MainForm->d_lat  = d_lat;
//					MainForm->d_long = d_long;
					Synchronize(&ShowCurrentData);
					if ((MainForm->fStartLat==0) || (MainForm->fStartLong==0)) { //  first reference to GPS
						if (d_lat && d_long) {
							MainForm->fPrLat = d_lat;
							MainForm->fPrLong = d_long;
							Synchronize(&ShowStartData);
						}
					}
					GPSCount++;
					if (GPSCount % 20) {
//						MainForm->CoordCount++;
						MainForm->NoGPSDataFlag = false;
					}
				} else {
					++BadCoordCount;
					MainForm->BadCoordCount++;
					if (BadCoordCount > MAXBADCOORD) {
						MainForm->NoGPSDataFlag = true;
					}
				}
			} catch (...) {
			}
		}
	}
	if (GPSport != 0)	CloseHandle(GPSport);
	GPSport = 0;
}
//---------------------------------------------------------------------------
