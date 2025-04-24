//---------------------------------------------------------------------------

#ifndef CommentUnitH
#define CommentUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TCommentForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TMemo *Memo_TextMetka;
	TButton *CloseButton;
	TLabeledEdit *LE_MarkerFile;
	TLabeledEdit *LE_MetkaNum;
	TLabeledEdit *LE_Time;
	TLabeledEdit *LE_Lat;
	TLabeledEdit *LE_Long;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	TButton *Button11;
	TButton *Button12;
	TButton *Button13;
	TButton *Button14;
	TButton *Button15;
	TButton *Button16;
	TButton *Button17;
	TButton *Button18;
	TButton *Button19;
	TButton *Button20;
	TButton *Button21;
	TButton *Button22;
	TButton *Button23;
	TButton *Button24;
	TButton *Button25;
	TButton *Button26;
	TButton *Button27;
	TButton *Button28;
	TButton *Button29;
	TButton *Button30;
	TButton *Button31;
	TButton *Button32;
	TButton *Button33;
	TButton *Button34;
	TButton *Button35;
	TButton *Button36;
	TButton *Button37;
	TButton *Button38;
	TButton *Button39;
	TButton *Button40;
	TButton *Button41;
	TButton *Button42;
	TButton *Button43;
	TButton *Button44;
	TButton *Button45;
	TButton *Button46;
	TButton *Button47;
	TButton *Button48;
	TEdit *Edit_Depth;
	TGroupBox *GroupBox1;
	TCheckBox *CBox_BadIzol;
	TCheckBox *CBox_CrossTube;
	TCheckBox *CBox_Anshlag;
	TCheckBox *CBox_CrossRoad;
	TCheckBox *CBox_Turn;
	void __fastcall CloseButtonClick(TObject *Sender);
	void __fastcall Button34Click(TObject *Sender);
	void __fastcall Button35Click(TObject *Sender);
	void __fastcall Button36Click(TObject *Sender);
	void __fastcall Button38Click(TObject *Sender);
	void __fastcall Button37Click(TObject *Sender);
	void __fastcall Button43Click(TObject *Sender);
	void __fastcall Button42Click(TObject *Sender);
	void __fastcall Button41Click(TObject *Sender);
	void __fastcall Button40Click(TObject *Sender);
	void __fastcall Button39Click(TObject *Sender);
	void __fastcall Button45Click(TObject *Sender);
	void __fastcall Button44Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall Button13Click(TObject *Sender);
	void __fastcall Button14Click(TObject *Sender);
	void __fastcall Button15Click(TObject *Sender);
	void __fastcall Button18Click(TObject *Sender);
	void __fastcall Button16Click(TObject *Sender);
	void __fastcall Button17Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button19Click(TObject *Sender);
	void __fastcall Button20Click(TObject *Sender);
	void __fastcall Button21Click(TObject *Sender);
	void __fastcall Button22Click(TObject *Sender);
	void __fastcall Button24Click(TObject *Sender);
	void __fastcall Button23Click(TObject *Sender);
	void __fastcall Button25Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button26Click(TObject *Sender);
	void __fastcall Button27Click(TObject *Sender);
	void __fastcall Button28Click(TObject *Sender);
	void __fastcall Button29Click(TObject *Sender);
	void __fastcall Button30Click(TObject *Sender);
	void __fastcall Button31Click(TObject *Sender);
	void __fastcall Button32Click(TObject *Sender);
	void __fastcall Button47Click(TObject *Sender);
	void __fastcall Button48Click(TObject *Sender);
	void __fastcall Button33Click(TObject *Sender);
	void __fastcall Button46Click(TObject *Sender);
	void __fastcall CBox_BadIzolClick(TObject *Sender);
	void __fastcall CBox_AnshlagClick(TObject *Sender);
	void __fastcall CBox_CrossTubeClick(TObject *Sender);
	void __fastcall CBox_CrossRoadClick(TObject *Sender);
	void __fastcall Edit_DepthClick(TObject *Sender);
	void __fastcall Memo_TextMetkaClick(TObject *Sender);
	void __fastcall CBox_TurnClick(TObject *Sender);
private:	// User declarations
	bool 		CtrlFlag;      			 	// флаг комментария
	bool		DepthActive;      		// depth entering
	AnsiString	ComStr, DepthComStr;			//	comment string
	char	c;
	void 		ShowButtonStatus();
	void __fastcall AddLetter(AnsiString s);
public:		// User declarations
	AnsiString 	FN;
	AnsiString	sLat, sLong, sTime;
	bool 		BadIzolFlag;      		// Повреждение изоляции
	bool 		AnshlagFlag;
	bool 	  CrossTubeFlag;
	bool 		CrossRoadFlag;
	bool 		TurnFlag;
	bool 		BegOpenTubeFlag, EndOpenTubeFlag;
	int			MetkaNum;
	float		fDepth;
	void __fastcall ResetFlags();
	__fastcall TCommentForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCommentForm *CommentForm;
//---------------------------------------------------------------------------
#endif
