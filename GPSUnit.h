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
	double	d_lat, d_long;        // ������� ������ � �������
	double	fSpeed, fKurs; 				// �������� � ����
	double  d_time;     					// ������� ����� � ���� �� GPS
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
	String  GetGPSstring();              // ���������� ������ ������ �� GPS
	void 		AcceptGPSData();
	String 	LeadZero(int k, int dig);
protected:
	void __fastcall Execute();
public:
	__fastcall TGPS(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
