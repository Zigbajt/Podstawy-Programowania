/***************************************************************
 * Name:      zad2Main.h
 * Purpose:   Defines Application Frame
 * Author:    Dawid Maciejski ()
 * Created:   2021-12-16
 * Copyright: Dawid Maciejski ()
 * License:
 **************************************************************/

#ifndef ZAD2MAIN_H
#define ZAD2MAIN_H

//(*Headers(zad2Frame)
#include <wx/button.h>
#include <wx/checklst.h>
#include <wx/combobox.h>
#include <wx/frame.h>
#include <wx/listbox.h>
#include <wx/menu.h>
#include <wx/radiobox.h>
#include <wx/radiobut.h>
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
        void OnRadioBox1Select(wxCommandEvent& event);
        void OnComboBox1Selected(wxCommandEvent& event);
        void OnRadioButton1Select(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(zad2Frame)
        static const long ID_COMBOBOX1;
        static const long ID_LISTBOX1;
        static const long ID_CHECKLISTBOX1;
        static const long ID_RADIOBUTTON1;
        static const long ID_RADIOBUTTON2;
        static const long ID_RADIOBOX1;
        static const long ID_BUTTON1;
        static const long ID_TEXTCTRL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(zad2Frame)
        wxButton* Button1;
        wxCheckListBox* CheckListBox1;
        wxComboBox* ComboBox1;
        wxListBox* ListBox1;
        wxRadioBox* RadioBox1;
        wxRadioButton* RadioButton1;
        wxRadioButton* RadioButton2;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // ZAD2MAIN_H
