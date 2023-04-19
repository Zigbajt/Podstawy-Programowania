/***************************************************************
 * Name:      zad3App.cpp
 * Purpose:   Code for Application Class
 * Author:    Dawid Maciejski ()
 * Created:   2021-12-03
 * Copyright: Dawid Maciejski ()
 * License:
 **************************************************************/

#include "zad3App.h"

//(*AppHeaders
#include "zad3Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(zad3App);

bool zad3App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	zad3Frame* Frame = new zad3Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
