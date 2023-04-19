/***************************************************************
 * Name:      zad1Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    Dawid Maciejski ()
 * Created:   2022-01-04
 * Copyright: Dawid Maciejski ()
 * License:
 **************************************************************/

#include "zad1Main.h"
#include <wx/msgdlg.h>
#include <wx/event.h>

//(*InternalHeaders(zad1Frame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(zad1Frame)
const long zad1Frame::ID_TEXTCTRL1 = wxNewId();
const long zad1Frame::ID_TEXTCTRL2 = wxNewId();
const long zad1Frame::ID_STATICTEXT1 = wxNewId();
const long zad1Frame::ID_STATICTEXT2 = wxNewId();
const long zad1Frame::idMenuQuit = wxNewId();
const long zad1Frame::idMenuAbout = wxNewId();
const long zad1Frame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(zad1Frame,wxFrame)
    //(*EventTable(zad1Frame)
    //*)

    EVT_BUTTON(wxID_EXIT,  zad1Frame::OnQuit)
    EVT_LEFT_UP(OnRightUp)
    EVT_RIGHT_UP(OnLeftUp)
    EVT_MOTION(OnMouseMove)
END_EVENT_TABLE()




void handlerFuncName( wxMouseEvent & event){

}

zad1Frame::zad1Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(zad1Frame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(32,56), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(200,56), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, wxEmptyString, wxPoint(64,104), wxSize(32,21), 0, _T("ID_STATICTEXT1"));
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, wxEmptyString, wxPoint(200,104), wxSize(64,21), 0, _T("ID_STATICTEXT2"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&zad1Frame::OnTextCtrl1Text);
    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&zad1Frame::OnTextCtrl2Text);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&zad1Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&zad1Frame::OnAbout);
    Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&zad1Frame::OnLeftUp);
    Connect(wxEVT_RIGHT_UP,(wxObjectEventFunction)&zad1Frame::OnRightUp);
    Connect(wxEVT_MOTION,(wxObjectEventFunction)&zad1Frame::OnMouseMove);
    //*)
}


zad1Frame::~zad1Frame()
{
    //(*Destroy(zad1Frame)
    //*)
}

void zad1Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void zad1Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}





void zad1Frame::OnLeftUp(wxMouseEvent& event)
{
StaticText1->SetLabel("klikniecie prawej myszki");
}

void zad1Frame::OnRightUp(wxMouseEvent& event)
{
StaticText2->SetLabel("klikniecie lewej myszki");

}

void zad1Frame::OnMouseMove(wxMouseEvent& event)
{
const wxPoint pozycja = wxGetMousePosition();
int myszx = pozycja.x;
int myszy = pozycja.y;
wxString x = wxString::Format(wxT("X: %i"),myszx);
wxString y = wxString::Format(wxT("Y: %i"),myszy);
TextCtrl1->SetLabel(x);
TextCtrl2->SetLabel(y);
}

void zad1Frame::OnTextCtrl2Text(wxCommandEvent& event)
{
}

void zad1Frame::OnTextCtrl1Text(wxCommandEvent& event)
{
}
