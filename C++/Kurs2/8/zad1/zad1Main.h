/***************************************************************
 * Name:      zad1Main.h
 * Purpose:   Defines Application Frame
 * Author:    Dawid Maciejski ()
 * Created:   2021-12-09
 * Copyright: Dawid Maciejski ()
 * License:
 **************************************************************/

#ifndef ZAD1MAIN_H
#define ZAD1MAIN_H

//(*Headers(zad1Frame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
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
        void OnClose(wxCloseEvent& event);
        //*)

        //(*Identifiers(zad1Frame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(zad1Frame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // ZAD1MAIN_H
