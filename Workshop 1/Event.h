#ifndef SENECA_EVENT_MODULE
#define SENECA_EVENT_MODULE

#include <iomanip>
#include <chrono>
#include "Settings.h"

namespace seneca {
	
	class Event {
		std::string m_name;
		std::chrono::nanoseconds m_duration;

	public:
		Event();
		Event(const char* name, const std::chrono::nanoseconds& duration);

		friend std::ostream& operator << (std::ostream& out, const Event& src);
	};
}

#endif