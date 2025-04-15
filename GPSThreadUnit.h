//---------------------------------------------------------------------------

#ifndef GPSThreadUnitH
#define GPSThreadUnitH

#define MAXBADCOORD 100

//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class GPSThread : public TThread
{
private:
	int		  m_lLastError;
	double	d_lat, d_long;        // ������� ������ � �������
	double	fSpeed, fKurs; 				// �������� � ����
	double  d_time;     					// ������� ����� � ���� �� GPS
	AnsiString  sComPort;
	HANDLE  GPSport;
	HANDLE  ComFile;
	TDCB 		lpDCB;
	TCommTimeouts lpCommTimeouts;
	void __fastcall ShowStartData();
	void __fastcall ShowCurrentData();
	void __fastcall ShowResult();
	bool __fastcall StartGPS();
	void __fastcall StopGPS();
	bool 		DecodeGPS(AnsiString, double &, double &, double &);
	AnsiString  GetGPSstring();              // ���������� ������ ������ �� GPS
	void 		AcceptGPSData();    // ������������� ������� �������� ��������� � ��������
protected:
	void __fastcall Execute();
public:
	void __fastcall ShowCoord();
	bool	RunGPSFlag;
	bool	StartFlag;
	bool 	StopFlag;   // ���� ���������, ������������ �� ��������� ������
	int		BadCoordCount;
	int		CoordCount;
	int		GPSCount;
	__fastcall GPSThread(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
