//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Chart.hpp"
#include "Series.hpp"
#include "TeEngine.hpp"
#include "TeeProcs.hpp"
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TOpenDialog *OpenDialog1;
	TPanel *Panel1;
	TLabel *Label1;
	TLabel *Label2;
	TListBox *COMListBox;
	TButton *CloseButton;
	TRadioGroup *RadioGroup_XAxes;
	TRadioGroup *RG_MarkerStep;
	TComboBox *CB_StartBox;
	TPanel *Panel2;
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox3;
	TComboBox *CBox_KMDUSB;
	TRadioGroup *RG_KMDUSB;
	TButton *KMDUSBButton;
	TCheckBox *CheckBox_KMDUSB;
	TGroupBox *GroupBox4;
	TComboBox *CBox_KMDBth;
	TRadioGroup *RG_KMDBth;
	TButton *KMDBthButton;
	TCheckBox *CheckBox_KMDBth;
	TMemo *KMDMemo;
	TPanel *Panel3;
	TGroupBox *GroupBox2;
	TMemo *GPSMemo;
	TGroupBox *GroupBox5;
	TComboBox *CBox_GPSBth;
	TRadioGroup *RG_GPSBth;
	TButton *GPSBthButton;
	TCheckBox *CheckBox_GPSBth;
	TGroupBox *GroupBox6;
	TComboBox *CBox_GPSUSB;
	TRadioGroup *RG_GPSUSB;
	TButton *GPSUSBButton;
	TCheckBox *CheckBox_GPSUSB;
	TPanel *Panel4;
	TGroupBox *GroupBox7;
	TLabel *LabelLat;
	TLabel *LabelLng;
	TChart *Chart1;
	TFastLineSeries *Series1;
	TFastLineSeries *Series2;
	TButton *ButtonSelectFragment;
	TCheckBox *CB_FragmSearch;
	TSplitter *Splitter1;
	TSplitter *Splitter2;
	TSplitter *Splitter3;
	TTimer *Timer1;
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
