// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#include "Station.h"

namespace seneca {

	size_t Station::m_widthField { 0 };
	uint Station::id_generator { 0 };

	Station::Station(const std::string& record) : m_ID(0), m_itemName(""), m_description(""), m_serialNumber(0), m_stockQunatity(0) {
		Utilities U;
		bool more = true;
		size_t pos = 0;

		m_ID = ++id_generator;

		m_itemName = U.extractToken(record, pos, more);
		m_serialNumber = std::stoi(U.extractToken(record, pos, more));
		m_stockQunatity = std::stoi(U.extractToken(record, pos, more));

		if (m_widthField < U.getFieldWidth()) m_widthField = U.getFieldWidth();

		m_description = U.extractToken(record, pos, more);
	}

	const std::string& Station::getItemName() const {
		return m_itemName;
	}

	size_t Station::getNextSerialNumber() {
		return m_serialNumber++;
	}

	size_t Station::getQuantity() const {
		return m_stockQunatity;
	}

	void Station::updateQuantity() {
		if (m_stockQunatity > 0) --m_stockQunatity;
	}

	void Station::display(std::ostream& os, bool full) const {
		os << std::setw(3) << std::setfill('0') << std::right << m_ID << " | " << std::setfill(' ') << std::setw(m_widthField)
			<< std::left << m_itemName << " | " << std::resetiosflags(std::ios::left) << std::setfill('0')
			<< std::setw(6) << m_serialNumber << " | ";

		if (full) os << std::setfill(' ') << std::setw(4) << m_stockQunatity << " | " << m_description;

		os << std::endl;
	}
}