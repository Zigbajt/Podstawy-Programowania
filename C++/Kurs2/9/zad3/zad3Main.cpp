/***************************************************************
 * Name:      zad3Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    Dawid Maciejski ()
 * Created:   2021-12-16
 * Copyright: Dawid Maciejski ()
 * License:
 **************************************************************/

#include "zad3Main.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(zad3Frame)
#include <wx/font.h>
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

//(*IdInit(zad3Frame)
const long zad3Frame::ID_STATICTEXT1 = wxNewId();
const long zad3Frame::ID_STATICTEXT2 = wxNewId();
const long zad3Frame::ID_STATICTEXT3 = wxNewId();
const long zad3Frame::ID_STATICTEXT4 = wxNewId();
const long zad3Frame::ID_TEXTCTRL1 = wxNewId();
const long zad3Frame::ID_TEXTCTRL2 = wxNewId();
const long zad3Frame::ID_SPINCTRL1 = wxNewId();
const long zad3Frame::ID_STATICTEXT5 = wxNewId();
const long zad3Frame::ID_SPINBUTTON1 = wxNewId();
const long zad3Frame::ID_TEXTCTRL3 = wxNewId();
const long zad3Frame::ID_STATICTEXT6 = wxNewId();
const long zad3Frame::ID_STATICTEXT7 = wxNewId();
const long zad3Frame::ID_CHOICE1 = wxNewId();
const long zad3Frame::ID_TEXTCTRL4 = wxNewId();
const long zad3Frame::ID_BUTTON1 = wxNewId();
const long zad3Frame::ID_TEXTCTRL5 = wxNewId();
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

    Create(parent, id, _("Zadanie3"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(600,800));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_3DLIGHT));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Imie"), wxPoint(50,100), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Tahoma"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Nzwisko"), wxPoint(300,100), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    wxFont StaticText2Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Tahoma"),wxFONTENCODING_DEFAULT);
    StaticText2->SetFont(StaticText2Font);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Wiek"), wxPoint(50,150), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    wxFont StaticText3Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Tahoma"),wxFONTENCODING_DEFAULT);
    StaticText3->SetFont(StaticText3Font);
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Wprowadz Studenta"), wxPoint(152,16), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    wxFont StaticText4Font(18,wxFONTFAMILY_SWISS,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Tahoma"),wxFONTENCODING_DEFAULT);
    StaticText4->SetFont(StaticText4Font);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(110,100), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl1->SetMaxLength(100);
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(400,100), wxSize(150,30), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextCtrl2->SetMaxLength(100);
    SpinCtrl1 = new wxSpinCtrl(this, ID_SPINCTRL1, _T("0"), wxPoint(110,150), wxSize(132,30), 0, 0, 100, 0, _T("ID_SPINCTRL1"));
    SpinCtrl1->SetValue(_T("0"));
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Rok Studiow"), wxPoint(288,152), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    wxFont StaticText5Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Tahoma"),wxFONTENCODING_DEFAULT);
    StaticText5->SetFont(StaticText5Font);
    SpinButton1 = new wxSpinButton(this, ID_SPINBUTTON1, wxPoint(368,248), wxSize(32,42), wxSP_VERTICAL|wxSP_ARROW_KEYS, _T("ID_SPINBUTTON1"));
    SpinButton1->SetRange(1, 100000);
    TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(264,256), wxSize(90,30), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    TextCtrl3->SetMaxLength(5);
    StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Gr. Dziekanska"), wxPoint(96,208), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    wxFont StaticText6Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Tahoma"),wxFONTENCODING_DEFAULT);
    StaticText6->SetFont(StaticText6Font);
    StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Nr. Indeksu"), wxPoint(128,256), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    wxFont StaticText7Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Tahoma"),wxFONTENCODING_DEFAULT);
    StaticText7->SetFont(StaticText7Font);
    Choice1 = new wxChoice(this, ID_CHOICE1, wxPoint(432,152), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    Choice1->Append(_("1"));
    Choice1->Append(_("2"));
    Choice1->Append(_("3"));
    Choice1->Append(_("4"));
    Choice1->Append(_("5"));
    TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(264,208), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    Button1 = new wxButton(this, ID_BUTTON1, _("Wykonaj"), wxPoint(240,312), wxSize(136,56), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    wxFont Button1Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Tahoma"),wxFONTENCODING_DEFAULT);
    Button1->SetFont(Button1Font);
    TextCtrl5 = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxPoint(24,384), wxSize(536,200), wxTE_PROCESS_ENTER|wxTE_PROCESS_TAB, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    TextCtrl5->SetMaxLength(1000);
    TextCtrl5->Disable();
    TextCtrl5->SetFocus();
    TextCtrl5->Hide();
    wxFont TextCtrl5Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Tahoma"),wxFONTENCODING_DEFAULT);
    TextCtrl5->SetFont(TextCtrl5Font);
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

    Connect(ID_SPINBUTTON1,wxEVT_SCROLL_THUMBTRACK,(wxObjectEventFunction)&zad3Frame::OnSpinButton1Change);
    Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&zad3Frame::OnTextCtrl3Text);
    Connect(ID_TEXTCTRL4,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&zad3Frame::OnTextCtrl4Text);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&zad3Frame::OnButton1Click);
    Connect(ID_TEXTCTRL5,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&zad3Frame::OnTextCtrl5Text);
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

void zad3Frame::OnSpinButton1Change(wxSpinEvent& event)
{
    wxString w1=wxT("");
    w1<<SpinButton1->GetValue();
    TextCtrl3->SetValue(w1);
}

void zad3Frame::OnButton1Click(wxCommandEvent& event)
{
    int x;
    wxString w1=wxT("");
    wxString w2=wxT("");
    x=SpinCtrl1->GetValue();
    w2<<(x);
    w1<<"Imie: "+TextCtrl1->GetValue()+" Nazwisko: "+TextCtrl2->GetValue()+" Wiek: "+w2+" Rok Studiow: "+Choice1->GetStringSelection()+" Grupa Dziekanska: "+TextCtrl4->GetValue()+" Nr Indeksu: "+TextCtrl3->GetValue();
    TextCtrl5->Show();
    TextCtrl5->SetValue(w1);
}

void zad3Frame::OnTextCtrl3Text(wxCommandEvent& event)
{

    //int w1=0;
    //w1=TextCtrl1->GetValue().To;

    //SpinButton1->setValue(w1);
}

void zad3Frame::OnTextCtrl5Text(wxCommandEvent& event)
{
}

void zad3Frame::OnTextCtrl4Text(wxCommandEvent& event)
{
}
