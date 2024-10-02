#ifndef SENECA_SETTINGS_H
#define SENECA_SETTINGS_H

#include <iostream>
#include <string>

namespace seneca {
	
	struct Settings {
		bool m_show_all;
		bool m_verbose;
		std::string m_time_units;
	};

	extern Settings g_settings;
}

#endif