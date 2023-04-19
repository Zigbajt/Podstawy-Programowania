/***************************************************************
 * Name:      zad2App.cpp
 * Purpose:   Code for Application Class
 * Author:    Dawid Maciejski ()
 * Created:   2022-01-04
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
    	zad2Frame* Frame = new zad2Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
