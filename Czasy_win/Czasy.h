//---------------------------------------------------------------------------

#ifndef CzasyH
#define CzasyH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TRadioButton *Past;
        TRadioButton *Present;
        TGroupBox *GroupBox2;
        TRadioButton *Simple;
        TRadioButton *Continuous;
        TRadioButton *Perfect;
        TRadioButton *Future;
        TRadioButton *PerfectC;
        TButton *Generuj;
        TEdit *zdanie;
        TLabel *result;
        TRadioButton *PerfectP;
        TRadioButton *InThePast;
        TLabel *Label1;
        void __fastcall PastClick(TObject *Sender);
        void __fastcall PresentClick(TObject *Sender);
        void __fastcall FutureClick(TObject *Sender);
        void __fastcall SimpleClick(TObject *Sender);
        void __fastcall ContinuousClick(TObject *Sender);
        void __fastcall PerfectClick(TObject *Sender);
        void __fastcall PerfectCClick(TObject *Sender);
        void __fastcall GenerujClick(TObject *Sender);
        void __fastcall InThePastClick(TObject *Sender);
        void __fastcall PerfectPClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
