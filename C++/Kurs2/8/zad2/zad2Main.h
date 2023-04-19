/***************************************************************
 * Name:      zad2Main.h
 * Purpose:   Defines Application Frame
 * Author:    Dawid Maciejski ()
 * Created:   2021-12-09
 * Copyright: Dawid Maciejski ()
 * License:
 **************************************************************/

#ifndef ZAD2MAIN_H
#define ZAD2MAIN_H

//(*Headers(zad2Frame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

class zad2Frame: public wxFrame
{
    public:

        zad2Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~zad2Frame();

    private:

        //(*Handlers(zad2Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnTextCtrl2Text(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        void OnTextCtrl3Text(wxCommandEvent& event);
        void OnTextCtrl4Text(wxCommandEvent& event);
        void OnTextCtrl5Text(wxCommandEvent& event);
        void OnTextCtrl6Text(wxCommandEvent& event);
        //*)

        //(*Identifiers(zad2Frame)
        static const long ID_TEXTCTRL3;
        static const long ID_TEXTCTRL4;
        static const long ID_TEXTCTRL5;
        static const long ID_TEXTCTRL6;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT6;
        static const long ID_BUTTON1;
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_MENUITEM1;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(zad2Frame)
        wxButton* Button1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText6;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl3;
        wxTextCtrl* TextCtrl4;
        wxTextCtrl* TextCtrl5;
        wxTextCtrl* TextCtrl6;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // ZAD2MAIN_H
