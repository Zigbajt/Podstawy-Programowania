/***************************************************************
 * Name:      zad2Main.h
 * Purpose:   Defines Application Frame
 * Author:    Dawid Maciejski ()
 * Created:   2022-01-04
 * Copyright: Dawid Maciejski ()
 * License:
 **************************************************************/

#ifndef ZAD2MAIN_H
#define ZAD2MAIN_H

//(*Headers(zad2Frame)
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/frame.h>
#include <wx/listbox.h>
#include <wx/menu.h>
#include <wx/radiobut.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
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
        void OnButton1Click(wxCommandEvent& event);
        void OnComboBox1Selected(wxCommandEvent& event);
        void OnListBox1Select(wxCommandEvent& event);
        void OnRadioButton1Select(wxCommandEvent& event);
        //*)

        //(*Identifiers(zad2Frame)
        static const long ID_BUTTON1;
        static const long ID_COMBOBOX1;
        static const long ID_LISTBOX1;
        static const long ID_RADIOBUTTON1;
        static const long ID_STATICTEXT1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(zad2Frame)
        wxButton* Button1;
        wxComboBox* ComboBox1;
        wxListBox* ListBox1;
        wxRadioButton* RadioButton1;
        wxStaticText* StaticText1;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // ZAD2MAIN_H
