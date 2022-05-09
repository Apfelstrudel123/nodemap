#pragma once
#include "ui_mainwindow.h"
#include <QtWidgets/QMainWindow>
#include <QSplitter>
#include "titlebar.h"
#include "sidebar.h"
#include "console.h"
#include "inspector.h"
#include "../io/io.h"

QT_BEGIN_NAMESPACE
namespace UI
{
    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        MainWindow(QWidget *parent = Q_NULLPTR);
        ~MainWindow();

    public slots:
        void open_project();
        void save_project();

    private:
        Ui::MainWindow* ui;
        Titlebar* titlebar;
        Sidebar* sidebar;
        Console* console;
        Inspector* inspector;

        QSplitter* work_splitter;

        QWidget* view;
        QSplitter* view_splitter;

        IO::ProjectData* project;

        void create_menubar();
        void create_menu(const QString& title, QList<QAction*> actions);
        QList<QAction*> create_file_actions();
        QList<QAction*> create_edit_actions();
        QList<QAction*> create_view_actions();
        QList<QAction*> create_tools_actions();
        QList<QAction*> create_help_actions();
        QAction* create_action(const QString& name, const QObject* receiver = nullptr, const char* callback = nullptr, const QString& key = nullptr);
        QAction* create_separator();
    };
}
QT_END_NAMESPACE
