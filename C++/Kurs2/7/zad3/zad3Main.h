/***************************************************************
 * Name:      zad3Main.h
 * Purpose:   Defines Application Frame
 * Author:    Dawid Maciejski ()
 * Created:   2021-12-03
 * Copyright: Dawid Maciejski ()
 * License:
 **************************************************************/

#ifndef ZAD3MAIN_H
#define ZAD3MAIN_H

//(*Headers(zad3Frame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
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
        //*)

        //(*Identifiers(zad3Frame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(zad3Frame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // ZAD3MAIN_H
