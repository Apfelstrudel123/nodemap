#pragma once
#include <QObject>
#include <QPlainTextEdit>
#include <QApplication>
#include "aboutdialog.h"

namespace UI
{
    class Menubar : public QObject
    {
        Q_OBJECT
    public:
        explicit Menubar(QPlainTextEdit* _console, QObject* parent = nullptr);

    signals:

    public slots:
        //File menu
        void create_project();
        void open_project();
        void save_project();
        void exit();

        //Help menu
        void about();

    private:
        QPlainTextEdit* console;
        AboutDialog* about_dlg;
    };
}
