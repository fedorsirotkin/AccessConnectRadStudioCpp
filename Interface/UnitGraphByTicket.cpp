//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitGraphByTicket.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#include "UnitSelectTable.h"

TFormGraphByTicketSales *FormGraphByTicketSales;
//---------------------------------------------------------------------------
__fastcall TFormGraphByTicketSales::TFormGraphByTicketSales(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormGraphByTicketSales::Button1Click(TObject *Sender)
{
	this->Hide();
    FormMain->Show();
}
//---------------------------------------------------------------------------


void __fastcall TFormGraphByTicketSales::FormCanResize(TObject *Sender, int &NewWidth,
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

void __fastcall TFormGraphByTicketSales::FormResize(TObject *Sender)
{
	int width = 800;
	if (FormMain->Width < width) {
		FormMain->Width = width;
	}
	int height = 600;
	if (FormMain->Height < height) {
		FormMain->Height = height;
	}

	// ����� ��������� � �������
	int cntColTbl = DBGridTicketSelling->Columns->Count;
	for (int i = 0; i < cntColTbl; i++) {
		// ������ ������� / ����� ��������� � �������
		DBGridTicketSelling->Columns->Items[i]->Width = ( DBGridTicketSelling->ClientWidth - 20 ) / cntColTbl;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormGraphByTicketSales::FormClose(TObject *Sender, TCloseAction &Action)

{
	Application->Terminate();
}
//---------------------------------------------------------------------------


void __fastcall TFormGraphByTicketSales::FormShow(TObject *Sender)
{
	// ����� ��������� � �������
	int cntColTbl = DBGridTicketSelling->Columns->Count;
	for (int i = 0; i < cntColTbl; i++) {
		// ������ ������� / ����� ��������� � �������
		DBGridTicketSelling->Columns->Items[i]->Width = ( DBGridTicketSelling->ClientWidth - 20 ) / cntColTbl;
	}
	ADOQueryTicketSelling->Active = false;
	ADOQueryTicketSelling->Active = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormGraphByTicketSales::FormCreate(TObject *Sender)
{
	ADOConnectionDB->ConnectionString = getConnectionString();
	ADOConnectionDB->LoginPrompt = false;
	ADOConnectionDB->Connected = true;

	ADOQueryTicketSelling->Active = true;
}
//---------------------------------------------------------------------------

