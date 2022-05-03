#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>

namespace UI
{
    MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
    {
        ui->setupUi(this);

        QHBoxLayout* layout = new QHBoxLayout(ui->widget);

        QWidget* sidebar = new QWidget();
        sidebar->setFixedWidth(60);
        layout->addWidget(sidebar);

        QWidget* work_column = new QWidget();
        layout->addWidget(work_column);
        QVBoxLayout* work_layout = new QVBoxLayout(work_column);

        QWidget* node_view = new QWidget();
        node_view->setMinimumHeight(100);
        node_view->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        work_layout->addWidget(node_view);

        console = new QPlainTextEdit("Console:");
        console->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        work_layout->addWidget(console);

        menubar = new Menubar(console);
        create_menubar();
    }

    MainWindow::~MainWindow()
    {
        delete ui;
    }

    void MainWindow::create_menubar()
    {
        create_menu("File", create_file_actions());
        create_menu("Edit", create_edit_actions());
        create_menu("View", create_view_actions());
        create_menu("Tools", create_tools_actions());
        create_menu("Help", create_help_actions());
    }

    void MainWindow::create_menu(const QString& title, QList<QAction*> actions)
    {
        QMenu* menu = ui->menubar->addMenu(title);
        create_menu_actions(menu, actions);
    }

    void MainWindow::create_menu_actions(QMenu* menu, QList<QAction*> actions)
    {
        menu->addActions(actions);
    }

    QList<QAction*> MainWindow::create_file_actions()
    {
        QList<QAction*> actions;
        actions.push_back(create_separator());
        actions.push_back(create_action("New Project...", menubar, SLOT(create_project()), "Ctrl+N"));
        actions.push_back(create_action("Open Project...", menubar, SLOT(open_project()), "Ctrl+O"));
        actions.push_back(create_action("Save Project", menubar, SLOT(save_project()), "Ctrl+S"));
        actions.push_back(create_action("Save Project as...", menubar, SLOT(exit())));
        actions.push_back(create_separator());
        actions.push_back(create_action("Exit", menubar, SLOT(exit()), "Ctrl+Q"));
        return actions;
    }

    QList<QAction*> MainWindow::create_edit_actions()
    {
        QList<QAction*> actions;
        actions.push_back(create_action("Undo", menubar, SLOT(exit()), "Ctrl+Z"));
        actions.push_back(create_separator());
        return actions;
    }

    QList<QAction*> MainWindow::create_view_actions()
    {
        QList<QAction*> actions;
        actions.push_back(create_action("Notes", menubar, SLOT(exit()), "Ctrl+Shift+N"));
        actions.push_back(create_separator());
        return actions;
    }

    QList<QAction*> MainWindow::create_tools_actions()
    {
        QList<QAction*> actions;
        actions.push_back(create_action("Do some...", menubar, SLOT(exit()), "Ctrl+Shift+B"));
        actions.push_back(create_separator());
        return actions;
    }

    QList<QAction*> MainWindow::create_help_actions()
    {
        QList<QAction*> actions;
        actions.push_back(create_action("About", menubar, SLOT(about())));
        actions.push_back(create_separator());
        return actions;
    }

    QAction* MainWindow::create_action(const QString& name, const QObject* receiver, const char* callback, const QString& key)
    {
        QAction* action = new QAction(name);
        connect(action, SIGNAL(triggered()), receiver, callback);
        if (key != nullptr)
            action->setShortcut(key);
        return action;
    }
    QAction* MainWindow::create_separator()
    {
        QAction* s = new QAction();
        s->setSeparator(true);
        return s;
    }
}
