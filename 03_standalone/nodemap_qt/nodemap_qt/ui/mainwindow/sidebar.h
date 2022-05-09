#pragma once
#include "ui_sidebar.h"
#include <QToolBar>
namespace Ui
{ class Sidebar; };

namespace UI
{
	class Sidebar : public QToolBar
	{
		Q_OBJECT

	public:
		Sidebar(QWidget* parent = Q_NULLPTR);
		~Sidebar();

	private:
		Ui::Sidebar* ui;
	};
}
