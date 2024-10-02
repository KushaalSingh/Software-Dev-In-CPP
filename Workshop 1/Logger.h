#ifndef SENECA_LOGGER_H
#define SENECA_LOGGER_H

#include "Event.h"

namespace seneca {

	typedef uint32_t uint;

	class Logger {
		Event* m_events;
		uint m_numEvents;

	public:
		Logger(Logger& src) = delete;
		Logger(Logger&& src) = delete;
		
		Logger();
		~Logger();
		Logger& operator = (Logger& src);
		Logger& operator = (Logger&& src);
		void addEvent(const Event& event);

		friend std::ostream& operator << (std::ostream& out, const Logger& src);
	};
}

#endif 