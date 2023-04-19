/***************************************************************
 * Name:      zad2Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    Dawid Maciejski ()
 * Created:   2022-01-04
 * Copyright: Dawid Maciejski ()
 * License:
 **************************************************************/

#include "zad2Main.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(zad2Frame)
#include <wx/font.h>
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

//(*IdInit(zad2Frame)
const long zad2Frame::ID_BUTTON1 = wxNewId();
const long zad2Frame::ID_COMBOBOX1 = wxNewId();
const long zad2Frame::ID_LISTBOX1 = wxNewId();
const long zad2Frame::ID_RADIOBUTTON1 = wxNewId();
const long zad2Frame::ID_STATICTEXT1 = wxNewId();
const long zad2Frame::idMenuQuit = wxNewId();
const long zad2Frame::idMenuAbout = wxNewId();
const long zad2Frame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(zad2Frame,wxFrame)
    //(*EventTable(zad2Frame)
    //*)
END_EVENT_TABLE()

zad2Frame::zad2Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(zad2Frame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(400,500));
    Button1 = new wxButton(this, ID_BUTTON1, _("Przycisk"), wxPoint(100,100), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    ComboBox1 = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxPoint(100,150), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
    ComboBox1->Append(_("Ala ma kota"));
    ComboBox1->Append(_("Kot ma Ale"));
    ListBox1 = new wxListBox(this, ID_LISTBOX1, wxPoint(100,200), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
    ListBox1->Append(_("Komunikat"));
    RadioButton1 = new wxRadioButton(this, ID_RADIOBUTTON1, _("Label"), wxPoint(100,290), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, wxEmptyString, wxPoint(50,350), wxSize(300,60), 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Tahoma"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
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

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&zad2Frame::OnButton1Click);
    Connect(ID_COMBOBOX1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&zad2Frame::OnComboBox1Selected);
    Connect(ID_LISTBOX1,wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,(wxObjectEventFunction)&zad2Frame::OnListBox1Select);
    Connect(ID_RADIOBUTTON1,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&zad2Frame::OnRadioButton1Select);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&zad2Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&zad2Frame::OnAbout);
    //*)

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&zad2Frame::OnButton1Click);
    Connect(ID_COMBOBOX1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&zad2Frame::OnComboBox1Selected);
    Connect(ID_LISTBOX1,wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,(wxObjectEventFunction)&zad2Frame::OnListBox1Select);
    Connect(ID_RADIOBUTTON1,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&zad2Frame::OnRadioButton1Select);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&zad2Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&zad2Frame::OnAbout);
}

zad2Frame::~zad2Frame()
{
    //(*Destroy(zad2Frame)
    //*)
}

void zad2Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void zad2Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void zad2Frame::OnButton1Click(wxCommandEvent& event)
{
    StaticText1->SetLabel("EVT_BUTTON");
}

void zad2Frame::OnComboBox1Selected(wxCommandEvent& event)
{
StaticText1->SetLabel(ComboBox1->GetValue());
}

void zad2Frame::OnListBox1Select(wxCommandEvent& event)
{
   wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("KOMUNIKAT TO JA"));
}

void zad2Frame::OnRadioButton1Select(wxCommandEvent& event)
{
     StaticText1->SetLabel("Zaznaczyles mnie");
}
