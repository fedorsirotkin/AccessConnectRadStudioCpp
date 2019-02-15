//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitSelectTable.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#include "UnitTicketOrder.h"
#include "UnitSearchSeanceByFilm.h"
#include "UnitGraphByTicket.h"

WideString getConnectionString()
{
	// ������ �����������
	WideString ConnectionString = "Provider=MSDASQL.1;Password=\"\";Persist Security Info=True;Data Source=CinemaNetwork;Extended Properties=\"DSN=CinemaNetwork;DBQ=E:\\VCS\\BitBucket\\accessconnectradstudiocpp\\DBase\\CinemaNetwork.accdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;\"";
	return ConnectionString;
}

// ������������ ������ � ��
const int CNT_TABLES =  14;
WideString tables[CNT_TABLES] = {
	"�����",
	"����� ������",
	"����",
	"������������",
	"����������",
	"�����",
	"������� �������",
	"������ �������",
	"���������� �������",
	"���������",
	"����",
	"������ ������������",
	"���� ����",
	"������"
};

TFormMain *FormMain;
//---------------------------------------------------------------------------

__fastcall TFormMain::TFormMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::FormCreate(TObject *Sender)
{
	ADOConnectionDB->ConnectionString = getConnectionString();
	ADOConnectionDB->LoginPrompt = false;
	ADOConnectionDB->Connected = true;

	ADOTableHalls->Active = true;
	ADOTableFilmCompanies->Active = true;
	ADOTableCinemas->Active = true;
	ADOTablePlaces->Active = true;
	ADOTableTicketSelling->Active = true;
	ADOTableMovieRental->Active = true;
	ADOTableSessionSchedule->Active = true;
	ADOTableDirectors->Active = true;
	ADOTableRows->Active = true;
	ADOTableCountriesProduction->Active = true;
	ADOTableTypesPlaces->Active = true;
	ADOTableFilms->Active = true;
	ADOTableGenres->Active = true;
	ADOTableFilmGenres->Active = true;

	DBGridGenres->ReadOnly = true;
	DBGridFilmGenres->ReadOnly = true;
	DBGridHalls->ReadOnly = true;
	DBGridFilmCompanies->ReadOnly = true;
	DBGridCinemas->ReadOnly = true;
	DBGridPlaces->ReadOnly = true;
	DBGridTicketSelling->ReadOnly = true;
	DBGridMovieRental->ReadOnly = true;
	DBGridSessionSchedule->ReadOnly = true;
	DBGridDirectors->ReadOnly = true;
	DBGridRows->ReadOnly = true;
	DBGridCountriesProduction->ReadOnly = true;
	DBGridTypesPlaces->ReadOnly = true;
	DBGridFilms->ReadOnly = true;

	// ����� - Genres
	const int CNT_FIELDS_GENRES = 1;
	WideString fieldsGenres[] = {
		"������������"
	};
	for (int i = 0; i < CNT_FIELDS_GENRES; i++) {
		ComboBoxGenres->AddItem(fieldsGenres[i], NULL);
	}

	// ����� ������ - FilmGenres
	const int CNT_FIELDS_FILM_GENRES = 2;
	WideString fieldsFilmGenres[] = {
		"����",
		"�����"
	};
	for (int i = 0; i < CNT_FIELDS_FILM_GENRES; i++) {
		ComboBoxFilmGenres->AddItem(fieldsFilmGenres[i], NULL);
	}

	// ���� - Halls
	const int CNT_FIELDS_HALLS = 4;
	WideString fieldsHalls[] = {
		"������������",
		"���������",
		"�����������",
		"���������"
	};
	for (int i = 0; i < CNT_FIELDS_HALLS; i++) {
		ComboBoxHalls->AddItem(fieldsHalls[i], NULL);
	}

	// ������������ - FilmCompanies
	const int CNT_FIELDS_FILM_COMPANIES = 1;
	WideString fieldsFilmCompanies[] = {
		"������������"
	};
	for (int i = 0; i < CNT_FIELDS_FILM_COMPANIES; i++) {
		ComboBoxFilmCompanies->AddItem(fieldsFilmCompanies[i], NULL);
	}

	// ���������� - Cinemas
	const int CNT_FIELDS_CINEMAS = 5;
	WideString fieldsCinemas[] = {
		"������������",
		"�����",
		"�������",
		"����",
		"�����������"
	};
	for (int i = 0; i < CNT_FIELDS_CINEMAS; i++) {
		ComboBoxCinemas->AddItem(fieldsCinemas[i], NULL);
	}

	// ����� - Places
	const int CNT_FIELDS_PLACES = 4;
	WideString fieldsPlaces[] = {
		"�����",
		"���",
		"��� �����",
		"����"
	};
	for (int i = 0; i < CNT_FIELDS_PLACES; i++) {
		ComboBoxPlaces->AddItem(fieldsPlaces[i], NULL);
	}

	// ������� ������� - TicketSelling
	const int CNT_FIELDS_TICKETS_SELLING = 2;
	WideString fieldsTicketSelling[] = {
		"�����",
		"�����"
	};
	for (int i = 0; i < CNT_FIELDS_TICKETS_SELLING; i++) {
		ComboBoxTicketSelling->AddItem(fieldsTicketSelling[i], NULL);
	}

	// ������ ������� - MovieRental
	const int CNT_FIELDS_MOVIE_RENTAI = 3;
	WideString fieldsMovieRental[] = {
		"����� � ������",
		"������ � �������",
		"�����"
	};
	for (int i = 0; i < CNT_FIELDS_MOVIE_RENTAI; i++) {
		ComboBoxMovieRental->AddItem(fieldsMovieRental[i], NULL);
	}

	// ���������� ������� - SessionSchedule
	const int CNT_FIELDS_SESSION_SECHEDULE = 3;
	WideString fieldsSessionSchedule[] = {
		"�����",
		"����",
		"���"
	};
	for (int i = 0; i < CNT_FIELDS_SESSION_SECHEDULE; i++) {
		ComboBoxSessionSchedule->AddItem(fieldsSessionSchedule[i], NULL);
	}

	// ��������� - Directors
	const int CNT_FIELDS_DIRECTORS = 1;
	WideString fieldsDirectors[] = {
		"������������"
	};
	for (int i = 0; i < CNT_FIELDS_DIRECTORS; i++) {
		ComboBoxDirectors->AddItem(fieldsDirectors[i], NULL);
	}

	// ���� - Rows
	const int CNT_FIELDS_ROWS = 2;
	WideString fieldsRows[] = {
		"�����",
		"���"
	};
	for (int i = 0; i < CNT_FIELDS_ROWS; i++) {
		ComboBoxRows->AddItem(fieldsRows[i], NULL);
	}

	// ������ ������������ - CountriesProduction
	const int CNT_FIELDS_COUNTRIES_PRODUCTION = 1;
	WideString fieldsCountriesProduction[] = {
		"������������"
	};
	for (int i = 0; i < CNT_FIELDS_COUNTRIES_PRODUCTION; i++) {
		ComboBoxCountriesProduction->AddItem(fieldsCountriesProduction[i], NULL);
	}

	// ���� ���� - TypesPlaces
	const int CNT_FIELDS_TYPES_PLACES = 1;
	WideString fieldsTypesPlaces[] = {
		"������������"
	};
	for (int i = 0; i < CNT_FIELDS_TYPES_PLACES; i++) {
		ComboBoxTypesPlaces->AddItem(fieldsTypesPlaces[i], NULL);
	}

	// ������ - Films
	const int CNT_FIELDS_FILMS = 8;
	WideString fieldsFilms[] = {
		"��������",
		"��� �������",
		"������������",
		"��������",
		"�������",
		"������������",
		"��������",
		"������ �������������"
	};
	for (int i = 0; i < CNT_FIELDS_FILMS; i++) {
		ComboBoxFilms->AddItem(fieldsFilms[i], NULL);
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormMain::CheckBoxReadOnlyClick(TObject *Sender)
{
	DBGridGenres->ReadOnly = true;
	DBGridFilmGenres->ReadOnly = true;
	DBGridHalls->ReadOnly = true;
	DBGridFilmCompanies->ReadOnly = true;
	DBGridCinemas->ReadOnly = true;
	DBGridPlaces->ReadOnly = true;
	DBGridTicketSelling->ReadOnly = true;
	DBGridMovieRental->ReadOnly = true;
	DBGridSessionSchedule->ReadOnly = true;
	DBGridDirectors->ReadOnly = true;
	DBGridRows->ReadOnly = true;
	DBGridCountriesProduction->ReadOnly = true;
	DBGridTypesPlaces->ReadOnly = true;
	DBGridFilms->ReadOnly = true;
	if (CheckBoxReadOnly->Checked) {
		DBGridGenres->ReadOnly = false;
		DBGridFilmGenres->ReadOnly = false;
		DBGridHalls->ReadOnly = false;
		DBGridFilmCompanies->ReadOnly = false;
		DBGridCinemas->ReadOnly = false;
		DBGridPlaces->ReadOnly = false;
		DBGridTicketSelling->ReadOnly = false;
		DBGridMovieRental->ReadOnly = false;
		DBGridSessionSchedule->ReadOnly = false;
		DBGridDirectors->ReadOnly = false;
		DBGridRows->ReadOnly = false;
		DBGridCountriesProduction->ReadOnly = false;
		DBGridTypesPlaces->ReadOnly = false;
		DBGridFilms->ReadOnly = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::NAboutAuthorClick(TObject *Sender)
{
	Application->MessageBox(L"����, ����\n������� ������ 16-����-1 \n�������� Ը���", L"�� ������", MB_OK);
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::NAboutProgramClick(TObject *Sender)
{
	Application->MessageBox(L"��������� \"���� �����������\", ������ 1.0.0\n��������� ����� Microsoft Access � C++\\CLI Embarcadero RAD Studio \n������������ ����������� ��������� � �� ��� ������ VCL Forms", L"� ���������", MB_OK);
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::FormCanResize(TObject *Sender, int &NewWidth, int &NewHeight,
          bool &Resize)
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

void __fastcall TFormMain::FormResize(TObject *Sender)
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

void __fastcall TFormMain::NSearchByFilmClick(TObject *Sender)
{
	this->Hide();
	FormSearchSeanceByFilm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::NBuildGraphClick(TObject *Sender)
{
	this->Hide();
	FormGraphByTicketSales->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::NTicketOrderClick(TObject *Sender)
{
	this->Hide();
	FormTicketOrder->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::BitBtnExitProgramClick(TObject *Sender)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ComboBoxGenresChange(TObject *Sender)
{
	WideString GenresField = ComboBoxGenres->Text;
	if (GenresField != "") {
		if (RadioButtonGenresAsc->Checked) {
			ADOTableGenres->Sort = GenresField + " ASC";
		}
		if (RadioButtonGenresDesc->Checked) {
			ADOTableGenres->Sort = GenresField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RadioButtonGenresAscClick(TObject *Sender)
{
	WideString GenresField = ComboBoxGenres->Text;
	if (GenresField != "") {
		if (RadioButtonGenresAsc->Checked) {
			ADOTableGenres->Sort = GenresField + " ASC";
		}
		if (RadioButtonGenresDesc->Checked) {
			ADOTableGenres->Sort = GenresField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RadioButtonGenresDescClick(TObject *Sender)
{
	WideString GenresField = ComboBoxGenres->Text;
	if (GenresField != "") {
		if (RadioButtonGenresAsc->Checked) {
			ADOTableGenres->Sort = GenresField + " ASC";
		}
		if (RadioButtonGenresDesc->Checked) {
			ADOTableGenres->Sort = GenresField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ComboBoxFilmGenresChange(TObject *Sender)
{
	WideString FilmGenresField = ComboBoxFilmGenres->Text;
	if (FilmGenresField != "") {
		if (RadioButtonFilmGenresAsc->Checked) {
			ADOTableFilmGenres->Sort = FilmGenresField + " ASC";
		}
		if (RadioButtonFilmGenresDesc->Checked) {
			ADOTableFilmGenres->Sort = FilmGenresField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RadioButtonFilmGenresAscClick(TObject *Sender)
{
	WideString FilmGenresField = ComboBoxFilmGenres->Text;
	if (FilmGenresField != "") {
		if (RadioButtonFilmGenresAsc->Checked) {
			ADOTableFilmGenres->Sort = FilmGenresField + " ASC";
		}
		if (RadioButtonFilmGenresDesc->Checked) {
			ADOTableFilmGenres->Sort = FilmGenresField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormMain::RadioButtonFilmGenresDescClick(TObject *Sender)
{
	WideString FilmGenresField = ComboBoxFilmGenres->Text;
	if (FilmGenresField != "") {
		if (RadioButtonFilmGenresAsc->Checked) {
			ADOTableFilmGenres->Sort = FilmGenresField + " ASC";
		}
		if (RadioButtonFilmGenresDesc->Checked) {
			ADOTableFilmGenres->Sort = FilmGenresField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ComboBoxHallsChange(TObject *Sender)
{
	WideString HallsField = ComboBoxHalls->Text;
	if (HallsField != "") {
		if (RadioButtonHallsAsc->Checked) {
			ADOTableHalls->Sort = HallsField + " ASC";
		}
		if (RadioButtonHallsDesc->Checked) {
			ADOTableHalls->Sort = HallsField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RadioButtonHallsAscClick(TObject *Sender)
{
	WideString HallsField = ComboBoxHalls->Text;
	if (HallsField != "") {
		if (RadioButtonHallsAsc->Checked) {
			ADOTableHalls->Sort = HallsField + " ASC";
		}
		if (RadioButtonHallsDesc->Checked) {
			ADOTableHalls->Sort = HallsField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RadioButtonHallsDescClick(TObject *Sender)
{
	WideString HallsField = ComboBoxHalls->Text;
	if (HallsField != "") {
		if (RadioButtonHallsAsc->Checked) {
			ADOTableHalls->Sort = HallsField + " ASC";
		}
		if (RadioButtonHallsDesc->Checked) {
			ADOTableHalls->Sort = HallsField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ComboBoxFilmCompaniesChange(TObject *Sender)
{
	WideString FilmCompaniesField = ComboBoxFilmCompanies->Text;
	if (FilmCompaniesField != "") {
		if (RadioButtonFilmCompaniesAsc->Checked) {
			ADOTableFilmCompanies->Sort = FilmCompaniesField + " ASC";
		}
		if (RadioButtonFilmCompaniesDesc->Checked) {
			ADOTableFilmCompanies->Sort = FilmCompaniesField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RadioButtonFilmCompaniesAscClick(TObject *Sender)
{
	WideString FilmCompaniesField = ComboBoxFilmCompanies->Text;
	if (FilmCompaniesField != "") {
		if (RadioButtonFilmCompaniesAsc->Checked) {
			ADOTableFilmCompanies->Sort = FilmCompaniesField + " ASC";
		}
		if (RadioButtonFilmCompaniesDesc->Checked) {
			ADOTableFilmCompanies->Sort = FilmCompaniesField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RadioButtonFilmCompaniesDescClick(TObject *Sender)
{
	WideString FilmCompaniesField = ComboBoxFilmCompanies->Text;
	if (FilmCompaniesField != "") {
		if (RadioButtonFilmCompaniesAsc->Checked) {
			ADOTableFilmCompanies->Sort = FilmCompaniesField + " ASC";
		}
		if (RadioButtonFilmCompaniesDesc->Checked) {
			ADOTableFilmCompanies->Sort = FilmCompaniesField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ComboBoxCinemasChange(TObject *Sender)
{
	WideString CinemasField = ComboBoxCinemas->Text;
	if (CinemasField != "") {
		if (RadioButtonCinemasAsc->Checked) {
			ADOTableCinemas->Sort = CinemasField + " ASC";
		}
		if (RadioButtonCinemasDesc->Checked) {
			ADOTableCinemas->Sort = CinemasField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RadioButtonCinemasAscClick(TObject *Sender)
{
	WideString CinemasField = ComboBoxCinemas->Text;
	if (CinemasField != "") {
		if (RadioButtonCinemasAsc->Checked) {
			ADOTableCinemas->Sort = CinemasField + " ASC";
		}
		if (RadioButtonCinemasDesc->Checked) {
			ADOTableCinemas->Sort = CinemasField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RadioButtonCinemasDescClick(TObject *Sender)
{
	WideString CinemasField = ComboBoxCinemas->Text;
	if (CinemasField != "") {
		if (RadioButtonCinemasAsc->Checked) {
			ADOTableCinemas->Sort = CinemasField + " ASC";
		}
		if (RadioButtonCinemasDesc->Checked) {
			ADOTableCinemas->Sort = CinemasField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ComboBoxPlacesChange(TObject *Sender)
{
	WideString PlacesField = ComboBoxPlaces->Text;
	if (PlacesField != "") {
		if (RadioButtonPlacesAsc->Checked) {
			ADOTablePlaces->Sort = "[" + PlacesField + "] ASC";
		}
		if (RadioButtonPlacesDesc->Checked) {
			ADOTablePlaces->Sort = "[" + PlacesField + "] DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RadioButtonPlacesAscClick(TObject *Sender)
{
	WideString PlacesField = ComboBoxPlaces->Text;
	if (PlacesField != "") {
		if (RadioButtonPlacesAsc->Checked) {
			ADOTablePlaces->Sort = "[" + PlacesField + "] ASC";
		}
		if (RadioButtonPlacesDesc->Checked) {
			ADOTablePlaces->Sort = "[" + PlacesField + "] DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RadioButtonPlacesDescClick(TObject *Sender)
{
	WideString PlacesField = ComboBoxPlaces->Text;
	if (PlacesField != "") {
		if (RadioButtonPlacesAsc->Checked) {
			ADOTablePlaces->Sort = "[" + PlacesField + "] ASC";
		}
		if (RadioButtonPlacesDesc->Checked) {
			ADOTablePlaces->Sort = "[" + PlacesField + "] DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ComboBoxTicketSellingChange(TObject *Sender)
{
	WideString TicketSellingField = ComboBoxTicketSelling->Text;
	if (TicketSellingField != "") {
		if (RadioButtonTicketSellingAsc->Checked) {
			ADOTableTicketSelling->Sort = TicketSellingField + " ASC";
		}
		if (RadioButtonTicketSellingDesc->Checked) {
			ADOTableTicketSelling->Sort = TicketSellingField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RadioButtonTicketSellingAscClick(TObject *Sender)
{
	WideString TicketSellingField = ComboBoxTicketSelling->Text;
	if (TicketSellingField != "") {
		if (RadioButtonTicketSellingAsc->Checked) {
			ADOTableTicketSelling->Sort = TicketSellingField + " ASC";
		}
		if (RadioButtonTicketSellingDesc->Checked) {
			ADOTableTicketSelling->Sort = TicketSellingField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RadioButtonTicketSellingDescClick(TObject *Sender)
{
	WideString TicketSellingField = ComboBoxTicketSelling->Text;
	if (TicketSellingField != "") {
		if (RadioButtonTicketSellingAsc->Checked) {
			ADOTableTicketSelling->Sort = TicketSellingField + " ASC";
		}
		if (RadioButtonTicketSellingDesc->Checked) {
			ADOTableTicketSelling->Sort = TicketSellingField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ComboBoxMovieRentalChange(TObject *Sender)
{
	WideString MovieRentalField = ComboBoxMovieRental->Text;
	if (MovieRentalField != "") {
		if (RadioButtonMovieRentalAsc->Checked) {
			ADOTableMovieRental->Sort = "[" + MovieRentalField + "] ASC";
		}
		if (RadioButtonMovieRentalDesc->Checked) {
			ADOTableMovieRental->Sort = "[" + MovieRentalField + "] DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RadioButtonMovieRentalAscClick(TObject *Sender)
{
	WideString MovieRentalField = ComboBoxMovieRental->Text;
	if (MovieRentalField != "") {
		if (RadioButtonMovieRentalAsc->Checked) {
			ADOTableMovieRental->Sort = "[" + MovieRentalField + "] ASC";
		}
		if (RadioButtonMovieRentalDesc->Checked) {
			ADOTableMovieRental->Sort = "[" + MovieRentalField + "] DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RadioButtonMovieRentalDescClick(TObject *Sender)
{
	WideString MovieRentalField = ComboBoxMovieRental->Text;
	if (MovieRentalField != "") {
		if (RadioButtonMovieRentalAsc->Checked) {
			ADOTableMovieRental->Sort = "[" + MovieRentalField + "] ASC";
		}
		if (RadioButtonMovieRentalDesc->Checked) {
			ADOTableMovieRental->Sort = "[" + MovieRentalField + "] DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ComboBoxSessionScheduleChange(TObject *Sender)
{
	WideString SessionScheduleField = ComboBoxSessionSchedule->Text;
	if (SessionScheduleField != "") {
		if (RadioButtonSessionScheduleAsc->Checked) {
			ADOTableSessionSchedule->Sort = SessionScheduleField + " ASC";
		}
		if (RadioButtonSessionScheduleDesc->Checked) {
			ADOTableSessionSchedule->Sort = SessionScheduleField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RadioButtonSessionScheduleAscClick(TObject *Sender)
{
	WideString SessionScheduleField = ComboBoxSessionSchedule->Text;
	if (SessionScheduleField != "") {
		if (RadioButtonSessionScheduleAsc->Checked) {
			ADOTableSessionSchedule->Sort = SessionScheduleField + " ASC";
		}
		if (RadioButtonSessionScheduleDesc->Checked) {
			ADOTableSessionSchedule->Sort = SessionScheduleField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RadioButtonSessionScheduleDescClick(TObject *Sender)
{
	WideString SessionScheduleField = ComboBoxSessionSchedule->Text;
	if (SessionScheduleField != "") {
		if (RadioButtonSessionScheduleAsc->Checked) {
			ADOTableSessionSchedule->Sort = SessionScheduleField + " ASC";
		}
		if (RadioButtonSessionScheduleDesc->Checked) {
			ADOTableSessionSchedule->Sort = SessionScheduleField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ComboBoxDirectorsChange(TObject *Sender)
{
	WideString DirectorsField = ComboBoxDirectors->Text;
	if (DirectorsField != "") {
		if (RadioButtonDirectorsAsc->Checked) {
			ADOTableDirectors->Sort = DirectorsField + " ASC";
		}
		if (RadioButtonDirectorsDesc->Checked) {
			ADOTableDirectors->Sort = DirectorsField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RadioButtonDirectorsAscClick(TObject *Sender)
{
	WideString DirectorsField = ComboBoxDirectors->Text;
	if (DirectorsField != "") {
		if (RadioButtonDirectorsAsc->Checked) {
			ADOTableDirectors->Sort = DirectorsField + " ASC";
		}
		if (RadioButtonDirectorsDesc->Checked) {
			ADOTableDirectors->Sort = DirectorsField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RadioButtonDirectorsDescClick(TObject *Sender)
{
	WideString DirectorsField = ComboBoxDirectors->Text;
	if (DirectorsField != "") {
		if (RadioButtonDirectorsAsc->Checked) {
			ADOTableDirectors->Sort = DirectorsField + " ASC";
		}
		if (RadioButtonDirectorsDesc->Checked) {
			ADOTableDirectors->Sort = DirectorsField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ComboBoxRowsChange(TObject *Sender)
{
	WideString RowsField = ComboBoxRows->Text;
	if (RowsField != "") {
		if (RadioButtonRowsAsc->Checked) {
			ADOTableRows->Sort = RowsField + " ASC";
		}
		if (RadioButtonRowsDesc->Checked) {
			ADOTableRows->Sort = RowsField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RadioButtonRowsAscClick(TObject *Sender)
{
	WideString RowsField = ComboBoxRows->Text;
	if (RowsField != "") {
		if (RadioButtonRowsAsc->Checked) {
			ADOTableRows->Sort = RowsField + " ASC";
		}
		if (RadioButtonRowsDesc->Checked) {
			ADOTableRows->Sort = RowsField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RadioButtonRowsDescClick(TObject *Sender)
{
	WideString RowsField = ComboBoxRows->Text;
	if (RowsField != "") {
		if (RadioButtonRowsAsc->Checked) {
			ADOTableRows->Sort = RowsField + " ASC";
		}
		if (RadioButtonRowsDesc->Checked) {
			ADOTableRows->Sort = RowsField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ComboBoxCountriesProductionChange(TObject *Sender)
{
	WideString CountriesProductionField = ComboBoxCountriesProduction->Text;
	if (CountriesProductionField != "") {
		if (RadioButtonCountriesProductionAsc->Checked) {
			ADOTableCountriesProduction->Sort = CountriesProductionField + " ASC";
		}
		if (RadioButtonCountriesProductionDesc->Checked) {
			ADOTableCountriesProduction->Sort = CountriesProductionField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RadioButtonCountriesProductionAscClick(TObject *Sender)

{
	WideString CountriesProductionField = ComboBoxCountriesProduction->Text;
	if (CountriesProductionField != "") {
		if (RadioButtonCountriesProductionAsc->Checked) {
			ADOTableCountriesProduction->Sort = CountriesProductionField + " ASC";
		}
		if (RadioButtonCountriesProductionDesc->Checked) {
			ADOTableCountriesProduction->Sort = CountriesProductionField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RadioButtonCountriesProductionDescClick(TObject *Sender)

{
	WideString CountriesProductionField = ComboBoxCountriesProduction->Text;
	if (CountriesProductionField != "") {
		if (RadioButtonCountriesProductionAsc->Checked) {
			ADOTableCountriesProduction->Sort = CountriesProductionField + " ASC";
		}
		if (RadioButtonCountriesProductionDesc->Checked) {
			ADOTableCountriesProduction->Sort = CountriesProductionField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ComboBoxTypesPlacesChange(TObject *Sender)
{
	WideString TypesPlacesField = ComboBoxTypesPlaces->Text;
	if (TypesPlacesField != "") {
		if (RadioButtonTypesPlacesAsc->Checked) {
			ADOTableTypesPlaces->Sort = TypesPlacesField + " ASC";
		}
		if (RadioButtonTypesPlacesDesc->Checked) {
			ADOTableTypesPlaces->Sort = TypesPlacesField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RadioButtonTypesPlacesAscClick(TObject *Sender)
{
	WideString TypesPlacesField = ComboBoxTypesPlaces->Text;
	if (TypesPlacesField != "") {
		if (RadioButtonTypesPlacesAsc->Checked) {
			ADOTableTypesPlaces->Sort = TypesPlacesField + " ASC";
		}
		if (RadioButtonTypesPlacesDesc->Checked) {
			ADOTableTypesPlaces->Sort = TypesPlacesField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RadioButtonTypesPlacesDescClick(TObject *Sender)
{
	WideString TypesPlacesField = ComboBoxTypesPlaces->Text;
	if (TypesPlacesField != "") {
		if (RadioButtonTypesPlacesAsc->Checked) {
			ADOTableTypesPlaces->Sort = TypesPlacesField + " ASC";
		}
		if (RadioButtonTypesPlacesDesc->Checked) {
			ADOTableTypesPlaces->Sort = TypesPlacesField + " DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ComboBoxFilmsChange(TObject *Sender)
{
	WideString FilmsField = ComboBoxFilms->Text;
	if (FilmsField != "") {
		if (RadioButtonFilmsAsc->Checked) {
			ADOTableFilms->Sort = "[" + FilmsField + "] ASC";
		}
		if (RadioButtonFilmsDesc->Checked) {
			ADOTableFilms->Sort = "[" + FilmsField + "] DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RadioButtonFilmsAscClick(TObject *Sender)
{
	WideString FilmsField = ComboBoxFilms->Text;
	if (FilmsField != "") {
		if (RadioButtonFilmsAsc->Checked) {
			ADOTableFilms->Sort = "[" + FilmsField + "] ASC";
		}
		if (RadioButtonFilmsDesc->Checked) {
			ADOTableFilms->Sort = "[" + FilmsField + "] DESC";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RadioButtonFilmsDescClick(TObject *Sender)
{
	WideString FilmsField = ComboBoxFilms->Text;
	if (FilmsField != "") {
		if (RadioButtonFilmsAsc->Checked) {
			ADOTableFilms->Sort = "[" + FilmsField + "] ASC";
		}
		if (RadioButtonFilmsDesc->Checked) {
			ADOTableFilms->Sort = "[" + FilmsField + "] DESC";
		}
	}
}
//---------------------------------------------------------------------------

