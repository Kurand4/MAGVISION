//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
#include "GPSUnit.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TGPS::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TGPS::TGPS(bool CreateSuspended) : TThread(CreateSuspended)
{
	GPSport = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TGPS::Execute()
{
	if (StartGPS()) {
		Synchronize(ShowResult);
		AcceptGPSData();
		StopGPS();
  } else {
		MainForm->ShowHour(false);
		ShowMessage("Ошибка подключения GPS " + m_lLastError);
	}
}
//---------------------------------------------------------------------------
void __fastcall TGPS::ShowResult()
{
	MainForm->GPSResult(true);
}
//---------------------------------------------------------------------------
void __fastcall TGPS::ShowData()
{
	if (sGGA == "") return;
	if (!MainForm->GPSReadyFlag) return;
	for (int i = 0; i < BytesRead; i++) MainForm->G[i] = sGGA[i];
	MainForm->ShowGPS(BytesRead);
}
//---------------------------------------------------------------------------
bool __fastcall TGPS::StartGPS()
{
	GPSspeed = MainForm->GPSspeed;
	sComPort = "\\\\.\\" + MainForm->GPSComPort;
	Application->ProcessMessages();
	GPSport = CreateFile(sComPort.c_str(), GENERIC_READ | GENERIC_WRITE, 0,	NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	Sleep(250);
	m_lLastError = GetLastError();
	if(!GetCommState(GPSport, &lpDCB))	{
		m_lLastError = ::GetLastError();
		GPSport = 0;
		sComPort="";
		return false;
	}
	lpDCB.BaudRate = GPSspeed;
	lpDCB.ByteSize = 8;
	lpDCB.Parity   = NOPARITY;
	lpDCB.StopBits = ONESTOPBIT;
	Sleep(222);
	if (!SetCommState(GPSport, &lpDCB)) {
		sComPort="";
		return false;
	}
	return true;
}
//---------------------------------------------------------------------------
void TGPS::AcceptGPSData()   	// устанавливает текущие значения координат и скорости
{
	FILE 		*f;
	String 	s = "";
	unsigned short 	n = 0;
	DWORD 	ln;
	DWORD 	k;
	char 	  buf[256];

	Word 		Year, Month, Day, Hour, Min, Sec, MSec;
	TDateTime dtPresent = Now();
	DecodeDate(dtPresent, Year, Month, Day);
	AnsiString sDataPath = GetCurrentDir()  + "\\DB\\" + LeadZero(Year-2000, 2) + LeadZero(Month,2) + LeadZero(Day,2);
	if(!DirectoryExists(sDataPath)) MkDir(sDataPath);
	AnsiString fname = sDataPath + "\\GPS.RAW";;

	AnsiString 	s1 = "", s2 = "";
	String	dt, t, lat, lng;
	f  = fopen(fname.c_str(), "wb");

	while (!Terminated) {
//		sGGA = "" ;
		ReadFile(GPSport, buf, sizeof(&buf), &BytesRead, NULL);
		if (BytesRead) {
			fwrite(buf, BytesRead, 1, f);
			s  = (String)buf;
			n  = s.Pos("$GPGGA");
			if (n==0)
				n = s.Pos("$GNGGA");
			if (n==0)
				n = s.Pos("$GPRMC");                                                                                                                                                                                                                                                                                                                                    ;
			if (n > 0) {
				s = s.SubString(n, 77);
				k  = 1;
				ln = s.Length();
				n  = s.Pos("@");
				if ((ln > 31) && (n == 0)) {
					do {
						sGGA[k] = s[k];
						k++;
						if (k == ln) break;
					} while ((s[k] != '\r') || (s[k+1] != '\n'));
				} else continue;
			} else continue;
			Synchronize(ShowData);     // send sGGA to MainForm
		}
	}
	fclose(f);
}
//---------------------------------------------------------------------------
void __fastcall TGPS::StopGPS()
{
	if (GPSport != NULL) {
		CloseHandle(GPSport);
		GPSport = NULL;
	}
}
//---------------------------------------------------------------------------
String TGPS::LeadZero(int k, int dig)
{
	AnsiString s;
	s=Trim(IntToStr(k));
	while (s.Length() < dig) s = "0" + s;
	return s;
}
//---------------------------------------------------------------------------
