//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "PauseUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPauseForm *PauseForm;
//---------------------------------------------------------------------------
__fastcall TPauseForm::TPauseForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPauseForm::ContinueButtonClick(TObject *Sender)
{
	PauseResult = 0;
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TPauseForm::RestartButtonClick(TObject *Sender)
{
	PauseResult = 1;
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TPauseForm::EndButtonClick(TObject *Sender)
{
	PauseResult = 2;
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TPauseForm::FormActivate(TObject *Sender)
{
	PauseResult = 0;
}
//---------------------------------------------------------------------------
