//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CommentUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCommentForm *CommentForm;
//---------------------------------------------------------------------------
__fastcall TCommentForm::TCommentForm(TComponent* Owner) : TForm(Owner) { }
//---------------------------------------------------------------------------
void __fastcall TCommentForm::CloseButtonClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::AddLetter(AnsiString s)
{
	if (!DepthActive) {
		ComStr += s;
		Memo_TextMetka->Text = ComStr;
	} else if (s != "") {
		DepthComStr += s;
		Edit_Depth->Text = DepthComStr;
	}
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::ResetFlags()
{
	BadIzolFlag = false;
	CBox_BadIzol->Checked = false;
	AnshlagFlag = false;
	CBox_CrossTube->Checked = false;
	CrossTubeFlag = false;
	CBox_Anshlag->Checked = false;
	CrossRoadFlag = false;
	CBox_CrossRoad->Checked = false;
	TurnFlag = false;
	CBox_Turn->Checked = false;
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::FormActivate(TObject *Sender)
{
	LE_MarkerFile->Text = FN;
	LE_MetkaNum->Text 	= MetkaNum;
	LE_Time->Text				=	sTime;
	LE_Lat->Text				=	sLat;
	LE_Long->Text				=	sLong;
	Memo_TextMetka->Lines->Clear();
	Memo_TextMetka->Focused();
	DepthActive = false;
	ShowButtonStatus();
	ComStr = "";
	if (MetkaNum == 1) Edit_Depth->Text = "";
	ResetFlags();
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::FormClose(TObject *Sender, TCloseAction &Action)
{
  AnsiString s;
	if (BadIzolFlag) {
		AddLetter(". Повреждение изоляции");
	}
	if (AnshlagFlag) {
		AddLetter(". КИП, аншлаг и пр.");
	}
	if (CrossTubeFlag) {
		AddLetter(". Пересечение");
	}
	if (CrossRoadFlag) {
		AddLetter(". Дорога");
	}
	if (TurnFlag) {
		AddLetter(". Поворот");
	}
	if (Edit_Depth->Text.Length()>0) {
		s = Memo_TextMetka->Text + ". (Глубина: " + Edit_Depth->Text + ")";
		Memo_TextMetka->Text = s;
	//	fDepth = DepthComStr.ToDouble();
	}
	if (Memo_TextMetka->Lines->Text.Length()>0)	Memo_TextMetka->Lines->SaveToFile(FN + ".TXT");
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::Button34Click(TObject *Sender)
{
	AddLetter("1");
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::Button35Click(TObject *Sender)
{
	AddLetter("2");
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::Button36Click(TObject *Sender)
{
	AddLetter("3");
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::Button38Click(TObject *Sender)
{
	AddLetter("4");
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::Button37Click(TObject *Sender)
{
	AddLetter("5");
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::Button43Click(TObject *Sender)
{
	AddLetter("6");
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::Button42Click(TObject *Sender)
{
	AddLetter("7");
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::Button41Click(TObject *Sender)
{
	AddLetter("8");
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::Button40Click(TObject *Sender)
{
	AddLetter("9");
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::Button39Click(TObject *Sender)
{
	AddLetter("0");
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::Button45Click(TObject *Sender)
{
	AddLetter("-");
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::Button44Click(TObject *Sender)
{
	AddLetter("+");
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::Button1Click(TObject *Sender)
{
	AddLetter("й");
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::Button5Click(TObject *Sender)
{
	AddLetter("ц");
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::Button6Click(TObject *Sender)
{
	AddLetter("у");
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::Button7Click(TObject *Sender)
{
	AddLetter("к");
}
//---------------------------------------------------------------------------

void __fastcall TCommentForm::Button8Click(TObject *Sender)
{
	AddLetter("е");
}
//---------------------------------------------------------------------------

void __fastcall TCommentForm::Button9Click(TObject *Sender)
{
	AddLetter("н");
}
//---------------------------------------------------------------------------

void __fastcall TCommentForm::Button10Click(TObject *Sender)
{
	AddLetter("г");
}
//---------------------------------------------------------------------------

void __fastcall TCommentForm::Button11Click(TObject *Sender)
{
	AddLetter("ш");
}
//---------------------------------------------------------------------------

void __fastcall TCommentForm::Button12Click(TObject *Sender)
{
	AddLetter("щ");
}
//---------------------------------------------------------------------------

void __fastcall TCommentForm::Button13Click(TObject *Sender)
{
	AddLetter("з");
}
//---------------------------------------------------------------------------

void __fastcall TCommentForm::Button14Click(TObject *Sender)
{
	AddLetter("х");
}
//---------------------------------------------------------------------------

void __fastcall TCommentForm::Button15Click(TObject *Sender)
{
	AddLetter("ъ");
}
//---------------------------------------------------------------------------

void __fastcall TCommentForm::Button18Click(TObject *Sender)
{
	AddLetter("ф");
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::Button16Click(TObject *Sender)
{
	AddLetter("ы");
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::Button17Click(TObject *Sender)
{
	AddLetter("в");
}
//---------------------------------------------------------------------------

void __fastcall TCommentForm::Button2Click(TObject *Sender)
{
	AddLetter("а");
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::Button19Click(TObject *Sender)
{
	AddLetter("п");
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::Button20Click(TObject *Sender)
{
	AddLetter("р");
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::Button21Click(TObject *Sender)
{
	AddLetter("о");
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::Button22Click(TObject *Sender)
{
	AddLetter("л");
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::Button23Click(TObject *Sender)
{
	AddLetter("д");
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::Button24Click(TObject *Sender)
{
	AddLetter("ж");
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::Button25Click(TObject *Sender)
{
	AddLetter("э");
}
//---------------------------------------------------------------------------

void __fastcall TCommentForm::Button3Click(TObject *Sender)
{
	AddLetter("я");
}
//---------------------------------------------------------------------------

void __fastcall TCommentForm::Button4Click(TObject *Sender)
{
	AddLetter("ч");
}
//---------------------------------------------------------------------------

void __fastcall TCommentForm::Button26Click(TObject *Sender)
{
	AddLetter("с");
}
//---------------------------------------------------------------------------

void __fastcall TCommentForm::Button27Click(TObject *Sender)
{
	AddLetter("м");
}
//---------------------------------------------------------------------------

void __fastcall TCommentForm::Button28Click(TObject *Sender)
{
	AddLetter("и");
}
//---------------------------------------------------------------------------

void __fastcall TCommentForm::Button29Click(TObject *Sender)
{
	AddLetter("т");
}
//---------------------------------------------------------------------------

void __fastcall TCommentForm::Button30Click(TObject *Sender)
{
	AddLetter("ь");
}
//---------------------------------------------------------------------------

void __fastcall TCommentForm::Button31Click(TObject *Sender)
{
	AddLetter("б");
}
//---------------------------------------------------------------------------

void __fastcall TCommentForm::Button32Click(TObject *Sender)
{
	AddLetter("ю");
}
//---------------------------------------------------------------------------

void __fastcall TCommentForm::Button47Click(TObject *Sender)
{
	AddLetter(".");
}
//---------------------------------------------------------------------------

void __fastcall TCommentForm::Button48Click(TObject *Sender)
{
	AddLetter(",");
}
//---------------------------------------------------------------------------

void __fastcall TCommentForm::Button33Click(TObject *Sender)
{
	AddLetter(" ");
}
//---------------------------------------------------------------------------

void __fastcall TCommentForm::Button46Click(TObject *Sender)
{
	if (!DepthActive) {
		ComStr = ComStr.SubString(1, ComStr.Length()-1);
		Memo_TextMetka->Text = ComStr;
	} else {
		DepthComStr = DepthComStr.SubString(1, DepthComStr.Length()-1);
		Edit_Depth->Text = DepthComStr;
	}
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::CBox_BadIzolClick(TObject *Sender)
{
	BadIzolFlag = CBox_BadIzol->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::CBox_AnshlagClick(TObject *Sender)
{
	AnshlagFlag = CBox_Anshlag->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::CBox_CrossTubeClick(TObject *Sender)
{
	CrossTubeFlag = CBox_CrossTube->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::CBox_CrossRoadClick(TObject *Sender)
{
	CrossRoadFlag = CBox_CrossRoad->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::CBox_TurnClick(TObject *Sender)
{
	TurnFlag = CBox_Turn->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::Edit_DepthClick(TObject *Sender)
{
	Edit_Depth->Text = "";
	DepthComStr = "";
	DepthActive = true;
	ShowButtonStatus();
}
//---------------------------------------------------------------------------
void __fastcall TCommentForm::Memo_TextMetkaClick(TObject *Sender)
{
	DepthActive = false;
	ShowButtonStatus();
}
//---------------------------------------------------------------------------
void TCommentForm::ShowButtonStatus()
{
	Button1->Enabled = !DepthActive;
	Button5->Enabled = !DepthActive;
	Button6->Enabled = !DepthActive;
	Button7->Enabled = !DepthActive;
	Button8->Enabled = !DepthActive;
	Button9->Enabled = !DepthActive;
	Button10->Enabled = !DepthActive;
	Button11->Enabled = !DepthActive;
	Button12->Enabled = !DepthActive;
	Button13->Enabled = !DepthActive;
	Button14->Enabled = !DepthActive;
	Button15->Enabled = !DepthActive;
	Button16->Enabled = !DepthActive;
	Button17->Enabled = !DepthActive;
	Button18->Enabled = !DepthActive;
	Button19->Enabled = !DepthActive;
	Button20->Enabled = !DepthActive;
	Button21->Enabled = !DepthActive;
	Button22->Enabled = !DepthActive;
	Button23->Enabled = !DepthActive;
	Button24->Enabled = !DepthActive;
	Button25->Enabled = !DepthActive;
	Button26->Enabled = !DepthActive;
	Button27->Enabled = !DepthActive;
	Button28->Enabled = !DepthActive;
	Button29->Enabled = !DepthActive;
	Button2->Enabled = !DepthActive;
	Button3->Enabled = !DepthActive;
	Button4->Enabled = !DepthActive;
	Button30->Enabled = !DepthActive;
	Button31->Enabled = !DepthActive;
	Button32->Enabled = !DepthActive;
	Button33->Enabled = !DepthActive;
	Button48->Enabled = !DepthActive;
	Application->ProcessMessages();
}
//---------------------------------------------------------------------------


