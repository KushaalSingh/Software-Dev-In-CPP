#include "timeMonitor.h"

namespace seneca {

	void TimeMonitor::startEvent(const char* name) {
		m_startTime = std::chrono::steady_clock::now();
		m_eventName = name;
	}

	Event TimeMonitor::stopEvent() {
		auto now = std::chrono::steady_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(now - m_startTime);
		return Event(m_eventName.c_str(), duration);
	}
}