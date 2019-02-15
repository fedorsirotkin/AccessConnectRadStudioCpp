//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>

//---------------------------------------------------------------------------
USEFORM("UnitSearchSeanceByFilm.cpp", FormSearchSeanceByFilm);
USEFORM("UnitSelectTable.cpp", FormMain);
USEFORM("UnitGraphByTicket.cpp", FormGraphByTicketSales);
USEFORM("UnitTicketOrder.cpp", FormTicketOrder);

//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TFormMain), &FormMain);
		Application->CreateForm(__classid(TFormSearchSeanceByFilm), &FormSearchSeanceByFilm);
		Application->CreateForm(__classid(TFormGraphByTicketSales), &FormGraphByTicketSales);
		Application->CreateForm(__classid(TFormTicketOrder), &FormTicketOrder);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
