/***************************************************************
 * Name:      zad2Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    Dawid Maciejski ()
 * Created:   2021-12-09
 * Copyright: Dawid Maciejski ()
 * License:
 **************************************************************/

#include "zad2Main.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(zad2Frame)
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

//(*IdInit(zad2Frame)
const long zad2Frame::ID_TEXTCTRL3 = wxNewId();
const long zad2Frame::ID_TEXTCTRL4 = wxNewId();
const long zad2Frame::ID_TEXTCTRL5 = wxNewId();
const long zad2Frame::ID_TEXTCTRL6 = wxNewId();
const long zad2Frame::ID_STATICTEXT1 = wxNewId();
const long zad2Frame::ID_STATICTEXT2 = wxNewId();
const long zad2Frame::ID_STATICTEXT3 = wxNewId();
const long zad2Frame::ID_STATICTEXT4 = wxNewId();
const long zad2Frame::ID_STATICTEXT5 = wxNewId();
const long zad2Frame::ID_STATICTEXT6 = wxNewId();
const long zad2Frame::ID_BUTTON1 = wxNewId();
const long zad2Frame::ID_TEXTCTRL1 = wxNewId();
const long zad2Frame::ID_TEXTCTRL2 = wxNewId();
const long zad2Frame::ID_MENUITEM1 = wxNewId();
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
    SetClientSize(wxSize(420,530));
    Move(wxPoint(-1,-1));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, _("0"), wxPoint(248,200), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    wxFont TextCtrl3Font(12,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Century"),wxFONTENCODING_DEFAULT);
    TextCtrl3->SetFont(TextCtrl3Font);
    TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, _("0"), wxPoint(248,248), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    wxFont TextCtrl4Font(12,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Century"),wxFONTENCODING_DEFAULT);
    TextCtrl4->SetFont(TextCtrl4Font);
    TextCtrl5 = new wxTextCtrl(this, ID_TEXTCTRL5, _("0"), wxPoint(248,296), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    wxFont TextCtrl5Font(12,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Century"),wxFONTENCODING_DEFAULT);
    TextCtrl5->SetFont(TextCtrl5Font);
    TextCtrl6 = new wxTextCtrl(this, ID_TEXTCTRL6, _("0"), wxPoint(248,344), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    wxFont TextCtrl6Font(12,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Century"),wxFONTENCODING_DEFAULT);
    TextCtrl6->SetFont(TextCtrl6Font);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("DODAWANIE :"), wxPoint(56,248), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Century"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("ODEJMOWANIE :"), wxPoint(16,200), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    wxFont StaticText2Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Century"),wxFONTENCODING_DEFAULT);
    StaticText2->SetFont(StaticText2Font);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("MNOZENIE :"), wxPoint(72,344), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    wxFont StaticText3Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Century"),wxFONTENCODING_DEFAULT);
    StaticText3->SetFont(StaticText3Font);
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("DZIELENIE :"), wxPoint(72,296), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    wxFont StaticText4Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Century"),wxFONTENCODING_DEFAULT);
    StaticText4->SetFont(StaticText4Font);
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("X"), wxPoint(110,50), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    wxFont StaticText5Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Century"),wxFONTENCODING_DEFAULT);
    StaticText5->SetFont(StaticText5Font);
    StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Y"), wxPoint(280,50), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    wxFont StaticText6Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Century"),wxFONTENCODING_DEFAULT);
    StaticText6->SetFont(StaticText6Font);
    Button1 = new wxButton(this, ID_BUTTON1, _("Oblicz"), wxPoint(110,395), wxSize(200,50), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    wxFont Button1Font(16,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Century"),wxFONTENCODING_DEFAULT);
    Button1->SetFont(Button1Font);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(70,95), wxSize(100,50), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    wxFont TextCtrl1Font(12,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Century"),wxFONTENCODING_DEFAULT);
    TextCtrl1->SetFont(TextCtrl1Font);
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(240,95), wxSize(100,50), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    wxFont TextCtrl2Font(12,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Century"),wxFONTENCODING_DEFAULT);
    TextCtrl2->SetFont(TextCtrl2Font);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
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

    Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&zad2Frame::OnTextCtrl3Text);
    Connect(ID_TEXTCTRL4,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&zad2Frame::OnTextCtrl4Text);
    Connect(ID_TEXTCTRL5,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&zad2Frame::OnTextCtrl5Text);
    Connect(ID_TEXTCTRL6,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&zad2Frame::OnTextCtrl6Text);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&zad2Frame::OnButton1Click);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&zad2Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&zad2Frame::OnAbout);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&zad2Frame::OnClose);
    //*)
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

void zad2Frame::OnClose(wxCloseEvent& event)
{
    Close();
}

void zad2Frame::OnButton1Click(wxCommandEvent& event)
{
    double x=0;
    double y=0;
    wxString w1=wxT("");
    wxString w2=wxT("");
    wxString w3=wxT("");
    wxString w4=wxT("");
    if(TextCtrl1->GetValue().ToDouble((&x)) && TextCtrl2->GetValue().ToDouble((&y)))
    {
        w1<<(x-y);
        TextCtrl3->SetValue(w1);
        w2<<(x+y);
        TextCtrl4->SetValue(w2);
        w3<<(x/y);
        if(y==0){
            TextCtrl5->SetValue("ERROR");
        }else{
            TextCtrl5->SetValue(w3);
        }
        w4<<(x*y);
        TextCtrl6->SetValue(w4);
    }
}

void zad2Frame::OnTextCtrl1Text(wxCommandEvent& event)
{
}

void zad2Frame::OnTextCtrl3Text(wxCommandEvent& event)
{
}

void zad2Frame::OnTextCtrl4Text(wxCommandEvent& event)
{
}

void zad2Frame::OnTextCtrl5Text(wxCommandEvent& event)
{
}

void zad2Frame::OnTextCtrl6Text(wxCommandEvent& event)
{
}
