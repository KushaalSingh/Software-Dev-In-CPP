#include "Event.h"

namespace seneca {

	Event::Event() : m_name(""), m_duration(0) {}

	Event::Event(const char* name, const std::chrono::nanoseconds& duration) : m_name(name), m_duration(duration) {};

	std::ostream& operator << (std::ostream& out, const Event& src) {
		static size_t i = 0;
		out << std::left << std::setw(2) << std::right << ++i <<": " << std::right << std::setw(40) << src.m_name << " -> ";

		/*if (g_settings.m_time_units == "seconds") out << std::setw(2);
		else if (g_settings.m_time_units == "milliseconds") out << std::setw(5);
		else if (g_settings.m_time_units == "microseconds") out << std::setw(8);
		else if (g_settings.m_time_units == "nanoseconds") out << std::setw(11);*/
		
		out << std::right << std::setw(11) << src.m_duration.count() << " " << g_settings.m_time_units << std::endl;

		return out;
	}
}