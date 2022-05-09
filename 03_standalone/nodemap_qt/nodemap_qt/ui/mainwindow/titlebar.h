#pragma once
#include <QMenuBar>
#include <QApplication>
#include "ui_titlebar.h"
#include "../dialogs/aboutdialog.h"

namespace UI
{
    class Titlebar : public QWidget, public Ui::Titlebar
    {
        Q_OBJECT

    public:
        Titlebar(QWidget* parent = Q_NULLPTR);
        ~Titlebar();
        
    public slots:
        //File menu
        void create_project();
        void exit();
        //Help menu
        void about();

    private:
        AboutDialog* about_dlg;
    };
}
