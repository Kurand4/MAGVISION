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
	double	d_lat, d_long;        // текущие широта и долгота
	double	fSpeed, fKurs; 				// скорость и курс
	double  d_time;     					// текущие время и дата от GPS
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
	AnsiString  GetGPSstring();              // возвращает строку данных от GPS
	void 		AcceptGPSData();    // устанавливает текущие значения координат и скорости
protected:
	void __fastcall Execute();
public:
	void __fastcall ShowCoord();
	bool	RunGPSFlag;
	bool	StartFlag;
	bool 	StopFlag;   // флаг окончания, выставляемый из основного потока
	int		BadCoordCount;
	int		CoordCount;
	int		GPSCount;
	__fastcall GPSThread(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
