//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Form_1.h"
#include "Form_2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
   // MainForm->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::ItemMenu2Click(TObject *Sender)
{
	Form2->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FirstBTNClick(TObject *Sender)
{
	Form2->ShowModal();
}
//---------------------------------------------------------------------------




