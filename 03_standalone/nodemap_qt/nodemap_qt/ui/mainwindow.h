#pragma once

#include <QtWidgets/QMainWindow>
#include <QPlainTextEdit>
#include "ui_mainwindow.h"
#include "menubar.h"

QT_BEGIN_NAMESPACE
namespace UI
{
    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        MainWindow(QWidget *parent = Q_NULLPTR);
        ~MainWindow();

        QPlainTextEdit* console;

    private:
        Ui::MainWindow* ui;
        Menubar* menubar;

        void create_menubar();
        void create_menu(const QString& title, QList<QAction*> actions);
        void create_menu_actions(QMenu* menu, QList<QAction*> actions);
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
