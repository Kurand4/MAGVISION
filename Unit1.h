//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
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
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TCheckBox *CheckBox_UseGPS;
	TGroupBox *GroupBox4;
	TLabel *L_StartLat;
	TLabel *L_StartLng;
	TLabel *LabelGPS;
	TLabel *GPSLabel;
	TLabel *L_SatNum;
	TLabel *Label7;
	TGroupBox *GroupBox5;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *Edit_Way;
	TEdit *Edit_Way1;
	TGroupBox *GroupBox7;
	TLabel *Label_dLng;
	TLabel *Label_dLat;
	TLabel *Label8;
	TLabel *Label12;
	TGroupBox *GroupBox6;
	TLabel *L_CoordCount;
	TLabel *L_BadCoordCount;
	TPanel *Panel3;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *StaticText_Plot1;
	TLabel *StaticText_Plot2;
	TLabel *StaticText_PlotN;
	TLabel *Label6;
	TSplitter *Splitter1;
	TPanel *Panel2;
	TSplitter *Splitter2;
	TPanel *Panel4;
	TButton *GPSButton;
	TButton *RunButton;
	TPanel *Panel5;
	TSplitter *Splitter3;
	TPanel *Panel6;
	TDBChart *VizorPlot1;
	TFastLineSeries *Series1;
	TFastLineSeries *Series2;
	TFastLineSeries *Series3;
	TPointSeries *Series7;
	TFastLineSeries *Series4;
	TGroupBox *GroupBox8;
	TButton *ButtonWay1;
	TButton *ButtonWay2;
	TButton *ButtonWay3;
	TButton *PauseButton;
	TButton *CloseButton;
	TButton *Button1;
	TBitBtn *BitBtn1;
	TGroupBox *GroupBox1;
	TButton *MarkerButton;
	TButton *CommentButton;
	TButton *Button2;
	TBitBtn *BitBtn2;
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
