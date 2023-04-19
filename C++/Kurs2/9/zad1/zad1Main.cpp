/***************************************************************
 * Name:      zad1Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    Dawid Maciejski ()
 * Created:   2021-12-16
 * Copyright: Dawid Maciejski ()
 * License:
 **************************************************************/

#include "zad1Main.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(zad1Frame)
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/settings.h>
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
const long zad1Frame::ID_BITMAPBUTTON1 = wxNewId();
const long zad1Frame::idMenuQuit = wxNewId();
const long zad1Frame::idMenuAbout = wxNewId();
const long zad1Frame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(zad1Frame,wxFrame)
    //(*EventTable(zad1Frame)
    //*)
END_EVENT_TABLE()

zad1Frame::zad1Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(zad1Frame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(400,500));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));
    BitmapButton1 = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("C:\\Users\\Dawid\\Pictures\\Blokady\\tapeciarnia.pl-84557_kobieta_fale_gory.jpg"))), wxPoint(110,32), wxSize(184,64), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    Button1 = new wxButton(this, wxID_ADD, wxEmptyString, wxPoint(70,120), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_ADD"));
    Button2 = new wxButton(this, wxID_APPLY, wxEmptyString, wxPoint(70,160), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_APPLY"));
    Button3 = new wxButton(this, wxID_BOLD, wxEmptyString, wxPoint(70,200), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_BOLD"));
    Button4 = new wxButton(this, wxID_CANCEL, wxEmptyString, wxPoint(70,240), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CANCEL"));
    Button5 = new wxButton(this, wxID_CLEAR, wxEmptyString, wxPoint(70,280), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CLEAR"));
    Button6 = new wxButton(this, wxID_CUT, wxEmptyString, wxPoint(240,200), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CUT"));
    Button7 = new wxButton(this, wxID_REPLACE, wxEmptyString, wxPoint(152,328), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_REPLACE"));
    Button8 = new wxButton(this, wxID_CLOSE, wxEmptyString, wxPoint(240,120), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CLOSE"));
    Button9 = new wxButton(this, wxID_COPY, wxEmptyString, wxPoint(240,160), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_COPY"));
    Button10 = new wxButton(this, wxID_DELETE, wxEmptyString, wxPoint(240,240), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_DELETE"));
    Button11 = new wxButton(this, wxID_FIND, wxEmptyString, wxPoint(240,280), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_FIND"));
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

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&zad1Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&zad1Frame::OnAbout);
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

void zad1Frame::OnButton1Click(wxCommandEvent& event)
{
}
