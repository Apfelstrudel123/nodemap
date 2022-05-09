#pragma once
#include <QWidget>
#include "ui_console.h"
namespace Ui
{ class Console; }

namespace UI
{
	class Console : public QWidget, public Ui::Console
	{
		Q_OBJECT

	public:
		Console(QWidget* parent = Q_NULLPTR);
		~Console();

		static void write(const QString& text, const QColor& color = Qt::GlobalColor::white);
		static QTextBrowser* Text;
	private:
		void resizeEvent(QResizeEvent* event);

	signals:
		void resized();
	};
}
