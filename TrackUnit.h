//---------------------------------------------------------------------------

#ifndef TrackUnitH
#define TrackUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Chart.hpp"
#include "DBChart.hpp"
#include "Series.hpp"
#include "TeEngine.hpp"
#include "TeeProcs.hpp"
#include <ExtCtrls.hpp>

#define LATSTEP   0.0005
//---------------------------------------------------------------------------
class TTrackForm : public TForm
{
__published:	// IDE-managed Components
	TSplitter *Splitter1;
	TPanel *Panel1;
	TSplitter *Splitter2;
	TPanel *Panel2;
	TButton *CloseButton;
	TChart *Chart_Track;
	TPointSeries *Series_Track;
	TPointSeries *FirstPointSeries;
	TPointSeries *MarkerSeries;
	TGroupBox *GroupBox5;
	TLabel *Label3;
	TLabel *Label_totSpeed;
	TLabel *Label_Way1;
	TLabel *Label9;
	TGroupBox *GroupBox6;
	TLabel *L_CoordCount;
	TLabel *L_BadCoordCount;
	TLabel *Label_curTime;
	TLabel *Label_runTime;
	TLabel *Label_curSpeed;
	TLabel *Label2;
	TPointSeries *Series1;
	void __fastcall CloseButtonClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	void 	 ShowTimeInfo(double d_lng, double d_lat);
	void 	 ShowSpeedInfo(double d_lng, double d_lat);
	void 		ClearTrack();
	void 	 SetIniCoordAxis(double d_long, double d_lat);
	void 	 SetCoordAxis(double d_long, double d_lat);
	__fastcall TTrackForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTrackForm *TrackForm;
//---------------------------------------------------------------------------
#endif
