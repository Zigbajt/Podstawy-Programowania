/***************************************************************
 * Name:      zad1App.cpp
 * Purpose:   Code for Application Class
 * Author:    Dawid Maciejski ()
 * Created:   2021-12-16
 * Copyright: Dawid Maciejski ()
 * License:
 **************************************************************/

#include "zad1App.h"

//(*AppHeaders
#include "zad1Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(zad1App);

bool zad1App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	zad1Frame* Frame = new zad1Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
