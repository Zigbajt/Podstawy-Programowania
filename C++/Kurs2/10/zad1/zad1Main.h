/***************************************************************
 * Name:      zad1Main.h
 * Purpose:   Defines Application Frame
 * Author:    Dawid Maciejski ()
 * Created:   2022-01-04
 * Copyright: Dawid Maciejski ()
 * License:
 **************************************************************/

#ifndef ZAD1MAIN_H
#define ZAD1MAIN_H

//(*Headers(zad1Frame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

class zad1Frame: public wxFrame
{
    public:

        zad1Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~zad1Frame();

    private:

        //(*Handlers(zad1Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnLeftUp(wxMouseEvent& event);
        void OnRightUp(wxMouseEvent& event);
        void OnMouseMove(wxMouseEvent& event);
        void OnTextCtrl2Text(wxCommandEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        //*)

        //(*Identifiers(zad1Frame)
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(zad1Frame)
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl2;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // ZAD1MAIN_H
