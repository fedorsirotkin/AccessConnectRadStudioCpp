//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitSearchSeanceByFilm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#include "UnitSelectTable.h"

TFormSearchSeanceByFilm *FormSearchSeanceByFilm;
//---------------------------------------------------------------------------
__fastcall TFormSearchSeanceByFilm::TFormSearchSeanceByFilm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormSearchSeanceByFilm::ButtonBackClick(TObject *Sender)
{
	this->Hide();
	FormMain->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFormSearchSeanceByFilm::FormResize(TObject *Sender)
{
	int width = 800;
	if (FormMain->Width < width) {
		FormMain->Width = width;
	}
	int height = 600;
	if (FormMain->Height < height) {
		FormMain->Height = height;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormSearchSeanceByFilm::FormCanResize(TObject *Sender, int &NewWidth,
          int &NewHeight, bool &Resize)
{
	int width = 800;
	if (NewWidth < width) {
		NewWidth = width;
	}
	int height = 600;
	if (NewHeight < height) {
		NewHeight = height;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormSearchSeanceByFilm::FormClose(TObject *Sender, TCloseAction &Action)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TFormSearchSeanceByFilm::EditFilmNameChange(TObject *Sender)
{
	FormSearchSeanceByFilm->ADOTableFilms->Locate("��������", EditFilmName->Text, TLocateOptions() << TLocateOption::loPartialKey);
}
//---------------------------------------------------------------------------

void __fastcall TFormSearchSeanceByFilm::FormCreate(TObject *Sender)
{
	ADOConnectionDB->ConnectionString = getConnectionString();
	ADOConnectionDB->LoginPrompt = false;
	ADOConnectionDB->Connected = true;

	ADOTableFilms->Active = true;
	ADOTableSeance->Active = true;
}
//---------------------------------------------------------------------------

