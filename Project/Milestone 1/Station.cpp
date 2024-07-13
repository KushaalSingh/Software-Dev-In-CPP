#include "Station.h"

namespace seneca {

	uint Station::m_widthField { 0 }; // Static variables initalized
	uint Station::id_generator { 0 };

	Station::Station(const std::string& record) : m_stationID(0), m_itemName(""), m_description(""), m_nextSerialNumber(0), m_stockQunatity(0) {
		Utilities U;


	}

}