#ifndef SENECA_TIMEMONITOR_H
#define SENECA_TIMEMONITOR_H

#include "event.h"

namespace seneca {

	class TimeMonitor {
		std::chrono::steady_clock::time_point m_startTime;
		std::string m_eventName;
	public:
		void startEvent(const char* name);
		Event stopEvent();
	};

}

#endif 