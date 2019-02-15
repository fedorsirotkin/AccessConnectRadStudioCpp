//---------------------------------------------------------------------------

#ifndef Form_1H
#define Form_1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TADOConnection *ADOConnectionFilmLibrary;
	TADOTable *ADOTable2;
	TDataSource *DataSource2;
	TDBGrid *DBGridCinemas;
	TDBEdit *DBEdit1;
	TADOQuery *ADOQuery1;
	TBitBtn *FirstBTN;
	TMainMenu *MainMenu1;
	TMenuItem *ItemMenu1;
	TMenuItem *ItemMenu2;
	TMenuItem *N111;
	TMenuItem *N211;
	TADOQuery *ADOQuery2;
	TDBGrid *DBGrid1;
	TADOTable *ADOTable1;
	TDataSource *DataSource1;
	TDBNavigator *DBNavigator1;
	TEdit *Edit1;
	TGroupBox *GroupBox1;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	void __fastcall ItemMenu2Click(TObject *Sender);
	void __fastcall FirstBTNClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
