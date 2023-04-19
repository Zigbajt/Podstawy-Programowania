/***************************************************************
 * Name:      zad2Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    Dawid Maciejski ()
 * Created:   2021-12-16
 * Copyright: Dawid Maciejski ()
 * License:
 **************************************************************/

#include "zad2Main.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(zad2Frame)
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
const long zad2Frame::ID_COMBOBOX1 = wxNewId();
const long zad2Frame::ID_LISTBOX1 = wxNewId();
const long zad2Frame::ID_CHECKLISTBOX1 = wxNewId();
const long zad2Frame::ID_RADIOBUTTON1 = wxNewId();
const long zad2Frame::ID_RADIOBUTTON2 = wxNewId();
const long zad2Frame::ID_RADIOBOX1 = wxNewId();
const long zad2Frame::ID_BUTTON1 = wxNewId();
const long zad2Frame::ID_TEXTCTRL1 = wxNewId();
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
    SetClientSize(wxSize(400,800));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWFRAME));
    ComboBox1 = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxPoint(30,30), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
    ComboBox1->SetSelection( ComboBox1->Append(_("1")) );
    ComboBox1->Append(_("2"));
    ComboBox1->Append(_("3"));
    ComboBox1->Append(_("4"));
    ComboBox1->Append(_("5"));
    ListBox1 = new wxListBox(this, ID_LISTBOX1, wxPoint(30,80), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
    ListBox1->SetSelection( ListBox1->Append(_("Wybierz 1")) );
    ListBox1->Append(_("Wybierz 2"));
    ListBox1->Append(_("Wybierz 3"));
    ListBox1->Append(_("Wybierz 4"));
    ListBox1->Append(_("Wybierz 5"));
    CheckListBox1 = new wxCheckListBox(this, ID_CHECKLISTBOX1, wxPoint(30,160), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHECKLISTBOX1"));
    CheckListBox1->Append(_("1U"));
    CheckListBox1->Append(_("2Y"));
    CheckListBox1->Append(_("3B"));
    CheckListBox1->Append(_("4O"));
    CheckListBox1->Append(_("5P"));
    RadioButton1 = new wxRadioButton(this, ID_RADIOBUTTON1, _("Wybierz X"), wxPoint(80,260), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
    RadioButton1->SetValue(true);
    RadioButton2 = new wxRadioButton(this, ID_RADIOBUTTON2, _("Wybierz Y"), wxPoint(240,260), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
    wxString __wxRadioBoxChoices_1[5] =
    {
    	_("1A"),
    	_("2B"),
    	_("3C"),
    	_("4D"),
    	_("5E")
    };
    RadioBox1 = new wxRadioBox(this, ID_RADIOBOX1, _("Wybierz"), wxPoint(250,30), wxDefaultSize, 5, __wxRadioBoxChoices_1, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX1"));
    RadioBox1->SetSelection(0);
    Button1 = new wxButton(this, ID_BUTTON1, _("Wykonaj"), wxPoint(150,320), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(40,368), wxSize(320,200), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl1->Disable();
    TextCtrl1->Hide();
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
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&zad2Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&zad2Frame::OnAbout);
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

void zad2Frame::OnRadioBox1Select(wxCommandEvent& event)
{

}

void zad2Frame::OnComboBox1Selected(wxCommandEvent& event)
{

}

void zad2Frame::OnRadioButton1Select(wxCommandEvent& event)
{
}

void zad2Frame::OnButton1Click(wxCommandEvent& event)
{
    int x=0,y=0,z=0;
    wxString w1=wxT("");
    wxString w2=wxT("");
    w1<<ComboBox1->GetStringSelection()+"  "+CheckListBox1->GetString(x)+"  "+ListBox1->GetString(y)+" "+RadioBox1->GetString(z)+" ";
        TextCtrl1->Show();

    TextCtrl1->SetValue(w1);
}
