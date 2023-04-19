/***************************************************************
 * Name:      zad3Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    Dawid Maciejski ()
 * Created:   2021-12-03
 * Copyright: Dawid Maciejski ()
 * License:
 **************************************************************/

#include "zad3Main.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(zad3Frame)
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

//(*IdInit(zad3Frame)
const long zad3Frame::idMenuQuit = wxNewId();
const long zad3Frame::idMenuAbout = wxNewId();
const long zad3Frame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(zad3Frame,wxFrame)
    //(*EventTable(zad3Frame)
    //*)
END_EVENT_TABLE()

zad3Frame::zad3Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(zad3Frame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, _("Mój Program - Dawid Maciejski 2ID14A"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(200,200));
    Move(wxPoint(50,50));
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

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&zad3Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&zad3Frame::OnAbout);
    //*)
}

zad3Frame::~zad3Frame()
{
    //(*Destroy(zad3Frame)
    //*)
}

void zad3Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void zad3Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
