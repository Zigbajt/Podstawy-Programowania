/***************************************************************
 * Name:      zad3Main.h
 * Purpose:   Defines Application Frame
 * Author:    Dawid Maciejski ()
 * Created:   2021-12-16
 * Copyright: Dawid Maciejski ()
 * License:
 **************************************************************/

#ifndef ZAD3MAIN_H
#define ZAD3MAIN_H

//(*Headers(zad3Frame)
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/spinbutt.h>
#include <wx/spinctrl.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

class zad3Frame: public wxFrame
{
    public:

        zad3Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~zad3Frame();

    private:

        //(*Handlers(zad3Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        void OnSpinButton1Change(wxSpinEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnTextCtrl3Text(wxCommandEvent& event);
        void OnTextCtrl5Text(wxCommandEvent& event);
        void OnTextCtrl4Text(wxCommandEvent& event);
        //*)

        //(*Identifiers(zad3Frame)
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT4;
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_SPINCTRL1;
        static const long ID_STATICTEXT5;
        static const long ID_SPINBUTTON1;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT6;
        static const long ID_STATICTEXT7;
        static const long ID_CHOICE1;
        static const long ID_TEXTCTRL4;
        static const long ID_BUTTON1;
        static const long ID_TEXTCTRL5;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(zad3Frame)
        wxButton* Button1;
        wxChoice* Choice1;
        wxSpinButton* SpinButton1;
        wxSpinCtrl* SpinCtrl1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText6;
        wxStaticText* StaticText7;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl3;
        wxTextCtrl* TextCtrl4;
        wxTextCtrl* TextCtrl5;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // ZAD3MAIN_H
