#include "aboutdialog.h"

namespace UI
{
	AboutDialog::AboutDialog(QWidget* parent) : QWidget(parent)
	{
		ui = new Ui::AboutDialog();
		ui->setupUi(this);
		this->setWindowFlags(Qt::Dialog);
	}

	AboutDialog::~AboutDialog()
	{
		delete ui;
	}
}
