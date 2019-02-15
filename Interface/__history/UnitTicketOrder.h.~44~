//---------------------------------------------------------------------------

#ifndef UnitTicketOrderH
#define UnitTicketOrderH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DBCtrls.hpp>
//---------------------------------------------------------------------------
class TFormTicketOrder : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonBack;
	TLabel *LabelTitle;
	TEdit *EditSearchFilm;
	TComboBox *ComboBoxFilm;
	TLabel *LabelFilm;
	TGroupBox *GroupBoxSalesReceipt;
	TButton *ButtonPrintSalesReceipt;
	TLabel *LabelFoundFilms;
	TLabel *LabelFilmsCnt;
	TComboBox *ComboBoxSeance;
	TLabel *LabelSeance;
	TLabel *Label3;
	TLabel *LabelSeanceCnt;
	TComboBox *ComboBoxHall;
	TLabel *LabelHall;
	TLabel *LabelFoundHall;
	TLabel *LabelHallCnt;
	TComboBox *ComboBoxCinema;
	TLabel *LabelCinema;
	TLabel *Label7;
	TLabel *LabelCinemaCnt;
	TComboBox *ComboBoxRow;
	TLabel *LabelRow;
	TLabel *LabelFoundRow;
	TLabel *LabelRowCnt;
	TComboBox *ComboBoxPlaceType;
	TLabel *LabelPlaceType;
	TLabel *LabelFoundPlaceType;
	TLabel *LabelPlaceTypeCnt;
	TComboBox *ComboBoxPlace;
	TLabel *LabelPlace;
	TLabel *LabelFoundPlace;
	TLabel *LabelPlaceCnt;
	TButton *ButtonInsertTicket;
	TADOConnection *ADOConnectionDB;
	TDataSource *DataSourceQuerySelect;
	TADOQuery *ADOQuerySelect;
	TADOQuery *ADOQueryInsert;
	TDataSource *DataSourceQueryInsert;
	TLabel *LabelHelper;
	TPrintDialog *PrintDialogSalesReceipt;
	TRichEdit *RichEditSalesReceipt;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ButtonBackClick(TObject *Sender);
	void __fastcall FormCanResize(TObject *Sender, int &NewWidth, int &NewHeight, bool &Resize);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ComboBoxFilmChange(TObject *Sender);
	void __fastcall EditSearchFilmChange(TObject *Sender);
	void __fastcall ComboBoxCinemaChange(TObject *Sender);
	void __fastcall ComboBoxRowChange(TObject *Sender);
	void __fastcall ComboBoxPlaceTypeChange(TObject *Sender);
	void __fastcall ComboBoxPlaceChange(TObject *Sender);
	void __fastcall ComboBoxSeanceChange(TObject *Sender);
	void __fastcall ComboBoxHallChange(TObject *Sender);
	void __fastcall ButtonPrintSalesReceiptClick(TObject *Sender);
	void __fastcall ButtonInsertTicketClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TFormTicketOrder(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormTicketOrder *FormTicketOrder;
//---------------------------------------------------------------------------
#endif
