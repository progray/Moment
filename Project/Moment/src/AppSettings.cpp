/* Copyright (c) 2012 Research In Motion Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "AppSettings.hpp"

#include <QSettings>

namespace
{
const QString httpsSettings = QLatin1String("usehttps");
}

/**
 * AppSettings::isUsingHttps()
 * Check Apps QSettings for key httpsSettings and return
 *
 * return httpsSettings value
 */
QString AppSettings::getValueFor(const QString &objectName,
		const QString &defaultValue) {
	QSettings settings;

// If no value has been saved, return the default value.
	if (settings.value(objectName).isNull()) {
		return defaultValue;
	}

// Otherwise, return the value stored in the settings object.
	return settings.value(objectName).toString();
}

void AppSettings::saveValueFor(const QString &objectName,
		const QString &inputValue) {
// A new value is saved to the application settings object.
	QSettings settings;
	settings.setValue(objectName, QVariant(inputValue));
}