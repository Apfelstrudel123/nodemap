#pragma once
#include <QSettings>

namespace Settings
{
	void init();

	QVariant get_setting(QString code);

	void set_setting(QString code, QVariant value);
}
