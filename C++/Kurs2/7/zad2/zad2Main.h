/***************************************************************
 * Name:      zad2Main.h
 * Purpose:   Defines Application Frame
 * Author:    Dawid Maciejski ()
 * Created:   2021-12-03
 * Copyright: Dawid Maciejski ()
 * License:
 **************************************************************/

#ifndef ZAD2MAIN_H
#define ZAD2MAIN_H

//(*Headers(zad2Dialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/stattext.h>
//*)

class zad2Dialog: public wxDialog
{
    public:

        zad2Dialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~zad2Dialog();

    private:

        //(*Handlers(zad2Dialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(zad2Dialog)
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON1;
        static const long ID_STATICLINE1;
        static const long ID_BUTTON2;
        //*)

        //(*Declarations(zad2Dialog)
        wxBoxSizer* BoxSizer1;
        wxBoxSizer* BoxSizer2;
        wxButton* Button1;
        wxButton* Button2;
        wxStaticLine* StaticLine1;
        wxStaticText* StaticText1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // ZAD2MAIN_H
