#include "titlebar.h"
#include "mainwindow.h"
#include "io.h"
#include "console.h"

namespace UI
{
    Titlebar::Titlebar(QWidget* parent) : QWidget(parent)
    {
        setupUi(this);
        about_dlg = nullptr;
    }

    Titlebar::~Titlebar()
    {
    }

    void Titlebar::create_project()
    {
        Console::write("Creating project...");
    }
    void Titlebar::exit()
    {
        QApplication::quit();
    }

    void Titlebar::about()
    {
        Console::write("Opening about dialog...");
        if (about_dlg == nullptr)
            about_dlg = new AboutDialog();
        about_dlg->show();
        about_dlg->raise();
    }
}
