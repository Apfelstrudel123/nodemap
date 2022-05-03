#pragma once
#include "ui_aboutdialog.h"
#include <QWidget>

namespace UI
{
	class AboutDialog : public QWidget
	{
		Q_OBJECT

	public:
		AboutDialog(QWidget* parent = Q_NULLPTR);
		~AboutDialog();

	private:
		Ui::AboutDialog* ui;
	};
}
