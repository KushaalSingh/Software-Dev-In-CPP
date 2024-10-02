#include "Logger.h"

namespace seneca {

	Logger::Logger() : m_events(nullptr), m_count(0) {}

	Logger::~Logger() {
		delete[] m_events;
		m_events = nullptr;
	}

	Logger::Logger(Logger&& src) noexcept : m_events(src.m_events), m_count(src.m_count) {
		src.m_events = nullptr;
		src.m_count = 0;
	}

	Logger& Logger::operator = (Logger&& src) noexcept {
		if (this != &src) {
			delete[] m_events;
			m_events = src.m_events;
			m_count = src.m_count;
			src.m_events = nullptr;
			src.m_count = 0;
		}
	}

	void Logger::addEvent(const Event& event) {
		Event* temp = new Event[m_count + 1];
		for (int i = 0; i < m_count; i++) temp[i] = m_events[i];
		temp[m_count] = event;
		delete[] m_events;
		m_events = temp;
		++m_count;
	}

	std::ostream& operator << (std::ostream& out, const Logger& src) {
		for (int i = 0; i < src.m_count; i++) out << src.m_events[i];
		return out;
	}

	uint Logger::size() const {
		return m_count;
	}
}