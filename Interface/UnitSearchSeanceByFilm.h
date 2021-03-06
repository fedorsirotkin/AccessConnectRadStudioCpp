//---------------------------------------------------------------------------

#ifndef UnitSearchSeanceByFilmH
#define UnitSearchSeanceByFilmH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormSearchSeanceByFilm : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonBack;
	TDBGrid *DBGrid1;
	TDBGrid *DBGrid2;
	TDBNavigator *DBNavigator1;
	TDBNavigator *DBNavigator2;
	TADOConnection *ADOConnectionDB;
	TADOTable *ADOTableSeance;
	TDataSource *DataSourceSeance;
	TADOTable *ADOTableFilms;
	TDataSource *DataSourceFilms;
	TLabel *Label1;
	TEdit *EditFilmName;
	TAutoIncField *ADOTableFilms��;
	TWideStringField *ADOTableFilms��������;
	TIntegerField *ADOTableFilms����������;
	TIntegerField *ADOTableFilms������������;
	TWideStringField *ADOTableFilms��������;
	TIntegerField *ADOTableFilms�������;
	TIntegerField *ADOTableFilms������������;
	TIntegerField *ADOTableFilms��������;
	TIntegerField *ADOTableFilms�������������������;
	TAutoIncField *ADOTableSeance��;
	TIntegerField *ADOTableSeance�����;
	TDateTimeField *ADOTableSeance����;
	TIntegerField *ADOTableSeance���;
	void __fastcall ButtonBackClick(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall FormCanResize(TObject *Sender, int &NewWidth, int &NewHeight, bool &Resize);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall EditFilmNameChange(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TFormSearchSeanceByFilm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSearchSeanceByFilm *FormSearchSeanceByFilm;
//---------------------------------------------------------------------------
#endif
