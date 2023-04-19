/***************************************************************
 * Name:      zad1App.cpp
 * Purpose:   Code for Application Class
 * Author:    Dawid Maciejski ()
 * Created:   2021-12-09
 * Copyright: Dawid Maciejski ()
 * License:
 **************************************************************/

#include "zad1App.h"

//(*AppHeaders
#include "zad1Main.h"
#include <wx/image.h>
//*)
/*
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
*/
class Window:public wxFrame{
public:
    //Window(wxWindow * parent,wxWindowID id, const wxString & title,const wxPoint & pos = wxDefaultPosition,const wxSize & size = wxDefaultSize,long style = wxDEFAULT_FRAME_STYLE,const wxString & name = wxFrameNameStr);
    Window();
};

class MojaApp : public wxApp {
public:
bool OnInit() {
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	//Window* Frame = new Window(0);      //Zwraca blad podczas kompilacji
    	zad1Frame* Frame = new zad1Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    return wxsOK;
}
};
IMPLEMENT_APP(MojaApp);
