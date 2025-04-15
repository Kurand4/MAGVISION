//---------------------------------------------------------------------------

#ifndef PauseUnitH
#define PauseUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TPauseForm : public TForm
{
__published:	// IDE-managed Components
	TButton *ContinueButton;
	TButton *RestartButton;
	TButton *EndButton;
	void __fastcall ContinueButtonClick(TObject *Sender);
	void __fastcall RestartButtonClick(TObject *Sender);
	void __fastcall EndButtonClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	int	PauseResult;
	__fastcall TPauseForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPauseForm *PauseForm;
//---------------------------------------------------------------------------
#endif
