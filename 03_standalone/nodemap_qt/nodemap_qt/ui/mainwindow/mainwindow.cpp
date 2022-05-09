#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScreen>
#include "../settings/settings.h"

namespace UI
{
    MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
        this->showMaximized();
        console = new Console();

        Settings::init();
        project = new IO::ProjectData();
        //Menubar
        titlebar = new Titlebar();
        create_menubar();
        //Sidebar
        sidebar = new Sidebar(this);
        //Node view
        QWidget* node_view = new QWidget();
        node_view->setMinimumHeight(50);
        node_view->setStyleSheet("background-color: rgb(150,150,150);");
        //Main View
        view = new QWidget();
        //View splitter
        view_splitter = new QSplitter(Qt::Orientation::Vertical);
        view_splitter->addWidget(node_view);
        view_splitter->addWidget(console);
        QVBoxLayout* view_layout = new QVBoxLayout(view);
        view_layout->setContentsMargins(0, 0, 0, 0);
        view_layout->addWidget(view_splitter);
        
        connect(console, SIGNAL(resized()), this, SLOT(save_view()));
        //Inspector
        inspector = new Inspector();
        //Workspace
        work_splitter = new QSplitter(Qt::Orientation::Horizontal);
        work_splitter->setContentsMargins(0, 0, 0, 0);
        work_splitter->addWidget(view);
        work_splitter->addWidget(inspector);
        //Main Layout
        QHBoxLayout* main_layout = new QHBoxLayout(ui->widget);
        main_layout->setMenuBar(titlebar);
        main_layout->setContentsMargins(0, 0, 0, 0);
        main_layout->setSpacing(5);
        main_layout->addWidget(sidebar);
        main_layout->addWidget(work_splitter);
        
        //Set console and node view height ratio
        float r = Settings::get_setting("work_view_ratio").toFloat();
        int height = view->screen()->availableGeometry().height();
        QList sizes = { int(height * r), int(height * (1-r)) };
        view_splitter->setSizes(sizes);
    }

    MainWindow::~MainWindow()
    {
        delete ui;
    }

    void MainWindow::create_menubar()
    {
        create_menu("&File", create_file_actions());
        create_menu("&Edit", create_edit_actions());
        create_menu("&View", create_view_actions());
        create_menu("&Tools", create_tools_actions());
        create_menu("&Help", create_help_actions());
    }

    void MainWindow::create_menu(const QString& title, QList<QAction*> actions)
    {
        QMenu* menu = titlebar->menus->addMenu(title);
        //titlebar->btn_minimize->setIcon(QApplication::style()->standardIcon(QStyle::StandardPixmap::SP_TitleBarMinButton));
        //titlebar->btn_maximize->setIcon(QApplication::style()->standardIcon(QStyle::StandardPixmap::SP_TitleBarMaxButton));
        //titlebar->btn_close->setIcon(QApplication::style()->standardIcon(QStyle::StandardPixmap::SP_TitleBarCloseButton));
        menu->addActions(actions);
    }

    QList<QAction*> MainWindow::create_file_actions()
    {
        QList<QAction*> actions;
        actions.push_back(create_separator());
        actions.push_back(create_action("New Project...", titlebar, SLOT(create_project()), "Ctrl+N"));
        actions.push_back(create_action("Open Project...", this, SLOT(open_project()), "Ctrl+O"));
        actions.push_back(create_action("Save Project", this, SLOT(save_project()), "Ctrl+S"));
        actions.push_back(create_action("Save Project as...", titlebar, SLOT(exit())));
        actions.push_back(create_separator());
        actions.push_back(create_action("Exit", titlebar, SLOT(exit()), "Alt+F4"));
        return actions;
    }

    QList<QAction*> MainWindow::create_edit_actions()
    {
        QList<QAction*> actions;
        actions.push_back(create_action("Undo", titlebar, SLOT(exit()), "Ctrl+Z"));
        actions.push_back(create_separator());
        return actions;
    }

    QList<QAction*> MainWindow::create_view_actions()
    {
        QList<QAction*> actions;
        actions.push_back(create_action("Notes", titlebar, SLOT(exit()), "Ctrl+Shift+N"));
        actions.push_back(create_separator());
        return actions;
    }

    QList<QAction*> MainWindow::create_tools_actions()
    {
        QList<QAction*> actions;
        actions.push_back(create_action("Do some...", titlebar, SLOT(exit()), "Ctrl+Shift+B"));
        actions.push_back(create_separator());
        return actions;
    }

    QList<QAction*> MainWindow::create_help_actions()
    {
        QList<QAction*> actions;
        actions.push_back(create_action("About", titlebar, SLOT(about())));
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

    void MainWindow::open_project()
    {
        Console::write("Opening project...");
        project = IO::open_project();
        if (project)
            Console::write("Opened Project at " + project->path);
        else
            Console::write("Couldn't open project...", Qt::GlobalColor::red);
    }
    void MainWindow::save_project()
    {
        IO::save_project(project);
    }
}
