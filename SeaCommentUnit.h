//---------------------------------------------------------------------------

#ifndef SeaCommentUnitH
#define SeaCommentUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TSeaCommentForm : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo_TextMetka;
	TEdit *Edit_Depth;
	TButton *OKButton;
	TButton *CancelButton;
	TLabel *Label1;
	TLabel *Label2;
	TButton *ButtonKbrd;
	void __fastcall CancelButtonClick(TObject *Sender);
	void __fastcall OKButtonClick(TObject *Sender);
	void __fastcall ButtonKbrdClick(TObject *Sender);
private:	// User declarations
	FILE  * tf; 		// *.TXT file
	AnsiString FN;
public:		// User declarations
	float  ROVDepth;
	void __fastcall Init(AnsiString DataBaseDir, AnsiString OutputFileName, int M_Count);
	__fastcall TSeaCommentForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSeaCommentForm *SeaCommentForm;
//---------------------------------------------------------------------------
#endif
