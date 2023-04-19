/***************************************************************
 * Name:      zad2App.cpp
 * Purpose:   Code for Application Class
 * Author:    Dawid Maciejski ()
 * Created:   2021-12-03
 * Copyright: Dawid Maciejski ()
 * License:
 **************************************************************/

#include "zad2App.h"

//(*AppHeaders
#include "zad2Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(zad2App);

bool zad2App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	zad2Dialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
