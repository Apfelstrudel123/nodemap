#include "console.h"

namespace UI
{
	QTextBrowser* Console::Text = nullptr;
	Console::Console(QWidget* parent) : QWidget(parent)
	{
		setupUi(this);
		Text = text;
		text->clear();
		text->append("Program start:");
	}

	Console::~Console()
	{
	}

	void Console::write(const QString& text, const QColor& color)
	{
		Text->setTextColor(color);
		Text->append(text);
	}

	void Console::resizeEvent(QResizeEvent* event)
	{
		emit resized();
	}
}
