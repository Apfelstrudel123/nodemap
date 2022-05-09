#include "settings.h"

namespace Settings
{
	QSettings* settings;
	void init()
	{
		settings = new QSettings();
	}

	QVariant get_setting(QString code)
	{
		return settings->value(code);
	}

	void set_setting(QString code, QVariant value)
	{
		settings->setValue(code, value);
	}
}
