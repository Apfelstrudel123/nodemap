#pragma once
#include <QWidget>
#include "ui_inspector.h"

namespace UI
{
	class Inspector : public QWidget, public Ui::Inspector
	{
		Q_OBJECT

	public:
		Inspector(QWidget* parent = Q_NULLPTR);
		~Inspector();
	};
}
