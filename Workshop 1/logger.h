#ifndef SENECA_LOGGER_H
#define SENECA_LOGGER_H

#include "Event.h"

namespace seneca {

	typedef uint32_t uint;

	class Logger {
		Event* m_events;
		uint m_count;

	public:
		Logger(Logger& src) = delete;
		Logger& operator = (Logger& src) = delete;
		
		Logger();
		~Logger();
		Logger(Logger&& src) noexcept;
		Logger& operator = (Logger&& src) noexcept;
		void addEvent(const Event& event);

		uint size() const;

		friend std::ostream& operator << (std::ostream& out, const Logger& src);
	};
}

#endif 