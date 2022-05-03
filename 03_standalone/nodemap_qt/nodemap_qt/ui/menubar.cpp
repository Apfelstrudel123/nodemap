#include "menubar.h"
#include "mainwindow.h"
#include "../io/io.h"

namespace UI
{
    Menubar::Menubar(QPlainTextEdit* _console, QObject* parent) : QObject{ parent }
    {
        console = _console;
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

    }
}
