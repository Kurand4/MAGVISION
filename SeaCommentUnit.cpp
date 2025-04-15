//---------------------------------------------------------------------------
#include <stdio.h>
#include <vcl.h>
#pragma hdrstop

#include "SeaCommentUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSeaCommentForm *SeaCommentForm;
//---------------------------------------------------------------------------
__fastcall TSeaCommentForm::TSeaCommentForm(TComponent* Owner) : TForm(Owner) { }
//---------------------------------------------------------------------------
void __fastcall TSeaCommentForm::CancelButtonClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TSeaCommentForm::Init(AnsiString DataBaseDir, AnsiString OutputFileName, int M_Count)
{
	FN = DataBaseDir + "\\" + OutputFileName+"_M"+IntToStr(M_Count) + ".TXT";
}
//---------------------------------------------------------------------------
void __fastcall TSeaCommentForm::OKButtonClick(TObject *Sender)
{
	AnsiString s = "; ROVDepth: " + Edit_Depth->Text;
	Memo_TextMetka->Lines->SaveToFile(FN);

	tf = fopen(FN.c_str(), "a+");
	fprintf(tf, s.c_str());
	fclose(tf);
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TSeaCommentForm::ButtonKbrdClick(TObject *Sender)
{
	ShellExecute(0, "open", "c:\\windows\\WinSxS\\amd64_microsoft-windows-osk_31bf3856ad364e35_10.0.18362.449_none_0098d787eb84df09\\osk.exe", NULL, NULL, SW_SHOW);
}
//---------------------------------------------------------------------------

