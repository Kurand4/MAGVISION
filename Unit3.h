//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TSplitter *Splitter1;
	TPanel *Panel2;
	TSplitter *Splitter2;
	TPanel *Panel3;
	TPanel *Panel4;
	TButton *RunButton;
	TButton *PauseButton;
	TButton *CloseButton;
	TButton *ShowTrackButton;
	TGroupBox *GroupBox1;
	TButton *MarkerButton;
	TButton *CommentButton;
	TButton *IzolMarkButton;
	TButton *KIPMarkButton;
	TButton *CrossMarkButton;
	TButton *RoadMarkButton;
	TButton *TurnMarkButton;
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
