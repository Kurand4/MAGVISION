//---------------------------------------------------------------------------

#ifndef GPSUnitH
#define GPSUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class TGPS : public TThread
{
private:
	DWORD   BytesRead;
	String  m_lLastError;
	double	d_lat, d_long;        // текущие широта и долгота
	double	fSpeed, fKurs; 				// скорость и курс
	double  d_time;     					// текущие время и дата от GPS
	int 		EmptyStrCount;
	AnsiString  sComPort;
	HANDLE  GPSport;
	HANDLE  ComFile;
	TDCB 		lpDCB;
	TCommTimeouts lpCommTimeouts;
	int			GPSspeed;
	char    sGGA[255];
	double	fStartLat, fStartLong;
	void __fastcall ShowResult();
	void __fastcall ShowData();
	bool __fastcall StartGPS();
	void __fastcall StopGPS();
	bool 		DecodeGPS(String, double &, double &, double &);
	String  GetGPSstring();              // возвращает строку данных от GPS
	void 		AcceptGPSData();
	String 	LeadZero(int k, int dig);
protected:
	void __fastcall Execute();
public:
	__fastcall TGPS(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
