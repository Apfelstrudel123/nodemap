#include "menubar.h"
#include "mainwindow.h"
#include "../io/io.h"

namespace UI
{
    Menubar::Menubar(QPlainTextEdit* _console, QObject* parent) : QObject{ parent }
    {
        console = _console;
        about_dlg = nullptr;
    }

    void Menubar::create_project()
    {

    }
    void Menubar::open_project()
    {
        console->appendPlainText("Opening project...");
        IO::ProjectData* data = IO::open_project();
        if (data != nullptr)
            console->appendPlainText(data->name);
        else
            console->appendPlainText("Open failed...");
    }
    void Menubar::save_project()
    {

    }
    void Menubar::exit()
    {
        QApplication::quit();
    }

    void Menubar::about()
    {
        console->appendPlainText("Opening about dialog...");
        if (about_dlg == nullptr)
            about_dlg = new AboutDialog();
        about_dlg->show();
        about_dlg->raise();
    }
}
