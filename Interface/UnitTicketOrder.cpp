//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitSelectTable.h"
#include "UnitTicketOrder.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#include <map>
#include <cstdio>

// ������, ������, ����, ����������, ����, ���� ����, �����, ����
std::map <WideString, int> films, seances, seancesIDs, halls, cinemas, rows, placetypes, places, prices;

TFormTicketOrder *FormTicketOrder;
//---------------------------------------------------------------------------

__fastcall TFormTicketOrder::TFormTicketOrder(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormTicketOrder::FormClose(TObject *Sender, TCloseAction &Action)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TFormTicketOrder::ButtonBackClick(TObject *Sender)
{
	this->Hide();
	FormMain->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFormTicketOrder::FormCanResize(TObject *Sender, int &NewWidth, int &NewHeight,
          bool &Resize)
{
	int width = 800;
	if (NewWidth < width) {
		NewWidth = width;
	}
	int height = 500;
	if (NewHeight < height) {
		NewHeight = height;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormTicketOrder::FormResize(TObject *Sender)
{
	int width = 800;
	if (FormTicketOrder->Width < width) {
		FormTicketOrder->Width = width;
	}
	int height = 500;
	if (FormTicketOrder->Height < height) {
		FormTicketOrder->Height = height;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormTicketOrder::FormCreate(TObject *Sender)
{
	ADOConnectionDB->ConnectionString = getConnectionString();
	ADOConnectionDB->LoginPrompt = false;
	ADOConnectionDB->Connected = true;

	TADOQuery* Query = ADOQuerySelect;
	Query->Active = false;

	ComboBoxFilm->Enabled = true;

    // ������
	try
	{
		Query->SQL->Text = "SELECT [��], [��������] FROM [������]";
		Query->Active = true;
		while(!Query->Eof){
			int id = Query->FieldByName("��")->AsInteger;
			WideString name = Query->FieldByName("��������")->AsString;
			films[name] = id;
			ComboBoxFilm->AddItem(name, NULL);
			Query->Next();
		}
	}
    catch (Exception* e) {
		MessageBox(NULL, PChar(WideString(e->Message)),
			L"Exception", MB_OK|MB_ICONWARNING);
    }
	Query->SQL->Clear();

	LabelFilmsCnt->Caption = ComboBoxFilm->Items->Count;

	LabelHelper->Caption = "�������� ����� �� ������ ��� ������� ��� �� ������������";
}
//---------------------------------------------------------------------------

void __fastcall TFormTicketOrder::EditSearchFilmChange(TObject *Sender)
{
	TADOQuery* Query = ADOQuerySelect;
	Query->Active = false;

	WideString SearchFilm = "%" + EditSearchFilm->Text + "%";

	// ������
	films.clear();
	ComboBoxFilm->Clear();
	try
	{
		Query->SQL->Text = "SELECT [��], [��������] FROM [������] WHERE [��������] LIKE :SearchFilm";
		Query->Parameters->ParamByName("SearchFilm")->Value = SearchFilm;
		Query->Active = true;
		while(!Query->Eof){
			int id = Query->FieldByName("��")->AsInteger;
			WideString name = Query->FieldByName("��������")->AsString;
			films[name] = id;
			ComboBoxFilm->AddItem(name, NULL);
			Query->Next();
		}
	}
	catch (Exception* e) {
		MessageBox(NULL, PChar(WideString(e->Message)),
			L"Exception", MB_OK|MB_ICONWARNING);
	}
	Query->SQL->Clear();

	LabelFilmsCnt->Caption = ComboBoxFilm->Items->Count;

	LabelHelper->Caption = "�������� ����� �� ������ ��� ������� ��� �� ������������";

	ComboBoxSeance->Enabled = false;
	ComboBoxSeance->Clear();
	LabelSeanceCnt->Caption = "0";

	ComboBoxHall->Enabled = false;
	ComboBoxHall->Clear();
	LabelHallCnt->Caption = "0";

	ComboBoxCinema->Enabled = false;
	ComboBoxCinema->Clear();
	LabelCinemaCnt->Caption = "0";

	ComboBoxRow->Enabled = false;
	ComboBoxRow->Clear();
	LabelRowCnt->Caption = "0";

	ComboBoxPlace->Enabled = false;
	ComboBoxPlace->Clear();
	LabelPlaceCnt->Caption = "0";

	ComboBoxPlaceType->Enabled = false;
	ComboBoxPlaceType->Clear();
	LabelPlaceTypeCnt->Caption = "0";

	RichEditSalesReceipt->Lines->Clear();
	ButtonPrintSalesReceipt->Enabled = false;
	ButtonInsertTicket->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormTicketOrder::ComboBoxFilmChange(TObject *Sender)
{
	TADOQuery* Query = ADOQuerySelect;
	Query->Active = false;

	ComboBoxSeance->Enabled = false;
	ComboBoxSeance->Clear();
	LabelSeanceCnt->Caption = "0";

	ComboBoxHall->Enabled = false;
	ComboBoxHall->Clear();
	LabelHallCnt->Caption = "0";

	ComboBoxCinema->Enabled = false;
	ComboBoxCinema->Clear();
	LabelCinemaCnt->Caption = "0";

	ComboBoxRow->Enabled = false;
	ComboBoxRow->Clear();
	LabelRowCnt->Caption = "0";

	ComboBoxPlace->Enabled = false;
	ComboBoxPlace->Clear();
	LabelPlaceCnt->Caption = "0";

	ComboBoxPlaceType->Enabled = false;
	ComboBoxPlaceType->Clear();
	LabelPlaceTypeCnt->Caption = "0";

	RichEditSalesReceipt->Lines->Clear();
	ButtonPrintSalesReceipt->Enabled = false;
	ButtonInsertTicket->Enabled = false;

	int itemIndex = ComboBoxFilm->ItemIndex;
	if (itemIndex >= 0) {
		WideString SelectedFilm = ComboBoxFilm->Text;
		int SelectedFilmKey = films.find(SelectedFilm)->second;

		// ������
		try
		{
			Query->SQL->Text = "SELECT [��], [���], [����] FROM [���������� �������] WHERE [�����] = :SelectedFilmKey";
			Query->Parameters->ParamByName("SelectedFilmKey")->Value = SelectedFilmKey;
			Query->Active = true;
			while(!Query->Eof){
				int id_1 = Query->FieldByName("���")->AsInteger;
				int id_2 = Query->FieldByName("��")->AsInteger;
				WideString name = Query->FieldByName("����")->AsString;
				seances[name] = id_1;
				seancesIDs[name] = id_2;
				ComboBoxSeance->AddItem(name, NULL);
				Query->Next();
			}
		}
		catch (Exception* e) {
			MessageBox(NULL, PChar(WideString(e->Message)),
				L"Exception", MB_OK|MB_ICONWARNING);
		}
		Query->SQL->Clear();

		LabelSeanceCnt->Caption = ComboBoxSeance->Items->Count;

		LabelHelper->Caption = "�������� ����� �� ����������� ������";

		ComboBoxSeance->Enabled = true;
	} else {
		ComboBoxSeance->Enabled = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormTicketOrder::ComboBoxSeanceChange(TObject *Sender)
{
	TADOQuery* Query = ADOQuerySelect;
	Query->Active = false;

	ComboBoxHall->Enabled = false;
	ComboBoxHall->Clear();
	LabelHallCnt->Caption = "0";

	ComboBoxCinema->Enabled = false;
	ComboBoxCinema->Clear();
	LabelCinemaCnt->Caption = "0";

	ComboBoxRow->Enabled = false;
	ComboBoxRow->Clear();
	LabelRowCnt->Caption = "0";

	ComboBoxPlace->Enabled = false;
	ComboBoxPlace->Clear();
	LabelPlaceCnt->Caption = "0";

	ComboBoxPlaceType->Enabled = false;
	ComboBoxPlaceType->Clear();
	LabelPlaceTypeCnt->Caption = "0";

	RichEditSalesReceipt->Lines->Clear();
	ButtonPrintSalesReceipt->Enabled = false;
	ButtonInsertTicket->Enabled = false;

	int itemIndex = ComboBoxSeance->ItemIndex;
	if (itemIndex >= 0) {
		WideString SelectedSeance = ComboBoxSeance->Text;
		int SelectedSeanceKey = seances.find(SelectedSeance)->second;

		// ����
		try
		{
			Query->SQL->Text = "SELECT [���������], [������������] FROM [����] WHERE [��] = :SelectedSeanceKey";
			Query->Parameters->ParamByName("SelectedSeanceKey")->Value = SelectedSeanceKey;
			Query->Active = true;
			while(!Query->Eof){
				int id = Query->FieldByName("���������")->AsInteger;
				WideString name = Query->FieldByName("������������")->AsString;
				halls[name] = id;
				ComboBoxHall->AddItem(name, NULL);
				Query->Next();
			}
		}
		catch (Exception* e) {
			MessageBox(NULL, PChar(WideString(e->Message)),
				L"Exception", MB_OK|MB_ICONWARNING);
		}
		Query->SQL->Clear();

		LabelHallCnt->Caption = ComboBoxHall->Items->Count;

		LabelHelper->Caption = "�������� ��� �� ����������� ������";

		ComboBoxHall->Enabled = true;
	} else {
		ComboBoxHall->Enabled = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormTicketOrder::ComboBoxHallChange(TObject *Sender)
{
	TADOQuery* Query = ADOQuerySelect;
	Query->Active = false;

	ComboBoxCinema->Enabled = false;
	ComboBoxCinema->Clear();
	LabelCinemaCnt->Caption = "0";

	ComboBoxRow->Enabled = false;
	ComboBoxRow->Clear();
	LabelRowCnt->Caption = "0";

	ComboBoxPlace->Enabled = false;
	ComboBoxPlace->Clear();
	LabelPlaceCnt->Caption = "0";

	ComboBoxPlaceType->Enabled = false;
	ComboBoxPlaceType->Clear();
	LabelPlaceTypeCnt->Caption = "0";

	RichEditSalesReceipt->Lines->Clear();
	ButtonPrintSalesReceipt->Enabled = false;
	ButtonInsertTicket->Enabled = false;

	int itemIndex = ComboBoxHall->ItemIndex;
	if (itemIndex >= 0) {
		WideString SelectedHall = ComboBoxHall->Text;
		int SelectedHallKey = halls.find(SelectedHall)->second;

		// ����������
		try
		{
			Query->SQL->Text = "SELECT [��], [������������] FROM [����������] WHERE [��] = :SelectedHallKey";
			Query->Parameters->ParamByName("SelectedHallKey")->Value = SelectedHallKey;
			Query->Active = true;
			while(!Query->Eof){
				int id = Query->FieldByName("��")->AsInteger;
				WideString name = Query->FieldByName("������������")->AsString;
				cinemas[name] = id;
				ComboBoxCinema->AddItem(name, NULL);
				Query->Next();
			}
		}
		catch (Exception* e) {
			MessageBox(NULL, PChar(WideString(e->Message)),
				L"Exception", MB_OK|MB_ICONWARNING);
		}
		Query->SQL->Clear();

		LabelCinemaCnt->Caption = ComboBoxCinema->Items->Count;

		LabelHelper->Caption = "�������� ��������� �� ����������� ������";

		ComboBoxCinema->Enabled = true;
	} else {
		ComboBoxCinema->Enabled = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormTicketOrder::ComboBoxCinemaChange(TObject *Sender)
{
	TADOQuery* Query = ADOQuerySelect;
	Query->Active = false;

	ComboBoxRow->Enabled = false;
	ComboBoxRow->Clear();
	LabelRowCnt->Caption = "0";

	ComboBoxPlace->Enabled = false;
	ComboBoxPlace->Clear();
	LabelPlaceCnt->Caption = "0";

	ComboBoxPlaceType->Enabled = false;
	ComboBoxPlaceType->Clear();
	LabelPlaceTypeCnt->Caption = "0";

	RichEditSalesReceipt->Lines->Clear();
	ButtonPrintSalesReceipt->Enabled = false;
	ButtonInsertTicket->Enabled = false;

	int itemIndex = ComboBoxHall->ItemIndex;
	if (itemIndex >= 0) {
		WideString SelectedHall = ComboBoxHall->Text;
		int SelectedHallKey = halls.find(SelectedHall)->second;

		// ����
		try
		{
			Query->SQL->Text = "SELECT [��], [�����] FROM [����] WHERE [���] = :SelectedHallKey";
			Query->Parameters->ParamByName("SelectedHallKey")->Value = SelectedHallKey;
			Query->Active = true;
			while(!Query->Eof){
				int id = Query->FieldByName("��")->AsInteger;
				WideString name = Query->FieldByName("�����")->AsString;
				rows[name] = id;
				ComboBoxRow->AddItem(name, NULL);
				Query->Next();
			}
		}
		catch (Exception* e) {
			MessageBox(NULL, PChar(WideString(e->Message)),
				L"Exception", MB_OK|MB_ICONWARNING);
		}
		Query->SQL->Clear();

		LabelRowCnt->Caption = ComboBoxRow->Items->Count;

		LabelHelper->Caption = "�������� ��� �� ����������� ������";

		ComboBoxRow->Enabled = true;
	} else {
		ComboBoxRow->Enabled = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormTicketOrder::ComboBoxRowChange(TObject *Sender)
{
	TADOQuery* Query = ADOQuerySelect;
	Query->Active = false;

	ComboBoxPlace->Enabled = false;
	ComboBoxPlace->Clear();
	LabelPlaceCnt->Caption = "0";

	ComboBoxPlaceType->Enabled = false;
	ComboBoxPlaceType->Clear();
	LabelPlaceTypeCnt->Caption = "0";

	RichEditSalesReceipt->Lines->Clear();
	ButtonPrintSalesReceipt->Enabled = false;
	ButtonInsertTicket->Enabled = false;

	int itemIndex = ComboBoxRow->ItemIndex;
	if (itemIndex >= 0) {
		WideString SelectedRow = ComboBoxRow->Text;
		int SelectedRowKey = rows.find(SelectedRow)->second;

		// �����
		try
		{
			Query->SQL->Text = "SELECT [��], [��� �����], [����], [�����] FROM [�����] WHERE [���] = :SelectedRowKey";
			Query->Parameters->ParamByName("SelectedRowKey")->Value = SelectedRowKey;
			Query->Active = true;
			while(!Query->Eof){
				int id_1 = Query->FieldByName("��")->AsInteger;
				int id_2 = Query->FieldByName("��� �����")->AsInteger;
				int id_3 = Query->FieldByName("����")->AsInteger;
				WideString name = Query->FieldByName("�����")->AsString;
				places[name] = id_1;
				placetypes[name] = id_2;
				prices[name] = id_3;
				ComboBoxPlace->AddItem(name, NULL);
				Query->Next();
			}
		}
		catch (Exception* e) {
			MessageBox(NULL, PChar(WideString(e->Message)),
				L"Exception", MB_OK|MB_ICONWARNING);
		}
		Query->SQL->Clear();

		LabelPlaceCnt->Caption = ComboBoxPlace->Items->Count;

		LabelHelper->Caption = "�������� ����� �� ����������� ������";

		ComboBoxPlace->Enabled = true;
	} else {
		ComboBoxPlace->Enabled = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormTicketOrder::ComboBoxPlaceChange(TObject *Sender)
{
	TADOQuery* Query = ADOQuerySelect;
	Query->Active = false;

	ComboBoxPlaceType->Enabled = false;
	ComboBoxPlaceType->Clear();
	LabelPlaceTypeCnt->Caption = "0";

	RichEditSalesReceipt->Lines->Clear();
	ButtonPrintSalesReceipt->Enabled = false;
	ButtonInsertTicket->Enabled = false;

	int itemIndex = ComboBoxPlace->ItemIndex;
	if (itemIndex >= 0) {
		WideString SelectedPlace = ComboBoxPlace->Text;
		int SelectedPlaceTypeKey = placetypes.find(SelectedPlace)->second;

		// ���� ����
		try
		{
			Query->SQL->Text = "SELECT [������������] FROM [���� ����] WHERE [��] = :SelectedPlaceTypeKey";
			Query->Parameters->ParamByName("SelectedPlaceTypeKey")->Value = SelectedPlaceTypeKey;
			Query->Active = true;
			while(!Query->Eof){
				WideString name = Query->FieldByName("������������")->AsString;

				ComboBoxPlaceType->AddItem(name, NULL);
				Query->Next();
			}
		}
		catch (Exception* e) {
			MessageBox(NULL, PChar(WideString(e->Message)),
				L"Exception", MB_OK|MB_ICONWARNING);
		}
		Query->SQL->Clear();

		LabelPlaceTypeCnt->Caption = ComboBoxPlaceType->Items->Count;

		LabelHelper->Caption = "�������� ��� ����� �� ����������� ������";

		ComboBoxPlaceType->Enabled = true;
	} else {
		ComboBoxPlaceType->Enabled = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormTicketOrder::ComboBoxPlaceTypeChange(TObject *Sender)
{
	int itemIndex = ComboBoxPlace->ItemIndex;
	if (itemIndex >= 0) {
		WideString place = ComboBoxPlace->Text;
		int price = prices.find(place)->second;

		LabelHelper->Caption = "���� ������ ����������: " + IntToStr(price) + " ���.";

		// ������ ������
		TVarRec vr[1];
		WideString s;
		RichEditSalesReceipt->Lines->Clear();
		RichEditSalesReceipt->Lines->Add(" ------------------------------------- ");

		s = ComboBoxFilm->Text;
		vr[0] = s;
		s = Format("| �����: %28.28s |", vr, 1);
		RichEditSalesReceipt->Lines->Add(s);

		s = ComboBoxCinema->Text;
		vr[0] = s;
		s = Format("| ���������: %24.24s |", vr, 1);
		RichEditSalesReceipt->Lines->Add(s);

		s = ComboBoxSeance->Text;
		vr[0] = s;
		s = Format("| �����: %28.28s |", vr, 1);
		RichEditSalesReceipt->Lines->Add(s);

		s = ComboBoxHall->Text;
		vr[0] = s;
		s = Format("| ���: %30.30s |", vr, 1);
		RichEditSalesReceipt->Lines->Add(s);

		s = ComboBoxRow->Text;
		vr[0] = s;
		s = Format("| ���: %30.30s |", vr, 1);
		RichEditSalesReceipt->Lines->Add(s);

		s = ComboBoxPlace->Text;
		vr[0] = s;
		s = Format("| �����: %28.28s |", vr, 1);
		RichEditSalesReceipt->Lines->Add(s);

		s = ComboBoxPlaceType->Text;
		vr[0] = s;
		s = Format("| ��� �����: %24.24s |", vr, 1);
		RichEditSalesReceipt->Lines->Add(s);

		s = IntToStr(price);
		vr[0] = s;
		s = Format("| ����: %29.29s |", vr, 1);
		RichEditSalesReceipt->Lines->Add(s);

		RichEditSalesReceipt->Lines->Add(" -------- ������� �� �������! -------- ");

		ComboBoxPlaceType->Enabled = true;
		ButtonPrintSalesReceipt->Enabled = true;
		ButtonInsertTicket->Enabled = true;
	} else {
		ComboBoxPlaceType->Enabled = false;
		ButtonPrintSalesReceipt->Enabled = false;
		ButtonInsertTicket->Enabled = false;
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormTicketOrder::ButtonPrintSalesReceiptClick(TObject *Sender)
{
	if (PrintDialogSalesReceipt->Execute()) {
		RichEditSalesReceipt->Print("��������");
	}
}
//---------------------------------------------------------------------------



void __fastcall TFormTicketOrder::ButtonInsertTicketClick(TObject *Sender)
{
	TADOQuery* Query = ADOQuerySelect;
	Query->Active = false;

	// ���� ����
	try
	{
		WideString seanceStr = ComboBoxSeance->Text;
		int seance = seancesIDs.find(seanceStr)->second;
		WideString placeStr = ComboBoxPlace->Text;
		int place = places.find(placeStr)->second;
		Query->SQL->Text = "INSERT INTO [������� �������] ( [�����], [�����] ) VALUES ( :seance, :place )";
		Query->Parameters->ParamByName("seance")->Value = seance;
		Query->Parameters->ParamByName("place")->Value = place;
		Query->ExecSQL();
		Application->MessageBox(L"������ ��������� � ����. �� �������� ����������� �������� ��� �������.", L"������ ���������!", MB_OK);
	}
	catch (Exception* e) {
		MessageBox(NULL, PChar(WideString(e->Message)),
			L"Exception", MB_OK|MB_ICONWARNING);
	}
	Query->SQL->Clear();
}
//---------------------------------------------------------------------------

