#include "event.h"

namespace seneca {

	Event::Event() : m_name(""), m_duration(0) {}

	Event::Event(const char* name, const std::chrono::nanoseconds& duration) : m_name(name), m_duration(duration) {};

	std::ostream& operator << (std::ostream& out, const Event& src) {
		static size_t i = 0;
		out << std::left << std::setw(2) << std::right << ++i <<": " << std::right << std::setw(40) << src.m_name << " -> " << std::right;
		
		if (g_settings.m_time_units == "seconds") 
			out << std::setw(2) << std::chrono::duration_cast<std::chrono::seconds>(src.m_duration).count() << " seconds" ;
		else if (g_settings.m_time_units == "milliseconds")
			out << std::setw(5) << std::chrono::duration_cast<std::chrono::milliseconds>(src.m_duration).count() << " milliseconds";
		else if (g_settings.m_time_units == "microseconds")
			out << std::setw(8) << std::chrono::duration_cast<std::chrono::microseconds>(src.m_duration).count() << " microseconds";
		else if (g_settings.m_time_units == "nanoseconds")
			out << std::setw(11) << src.m_duration.count() << " nanoseconds";

		out << std::endl;
		return out;
	}
}