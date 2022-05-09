#include "sidebar.h"

namespace UI
{
	Sidebar::Sidebar(QWidget* parent) : QToolBar(parent)
	{
		ui = new Ui::Sidebar();
		ui->setupUi(this);
	}

	Sidebar::~Sidebar()
	{
		delete ui;
	}
}
