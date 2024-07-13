#ifndef SENECA_STATION_H
#define SENECA_STATION_H

#include "Utilities.h"

namespace seneca {

	typedef unsigned uint;

	class Station {
	private:
		int m_stationID;
		std::string m_itemName;
		std::string m_description;
		uint m_nextSerialNumber;
		uint m_stockQunatity;

		static uint m_widthField;
		static uint id_generator;

	public:
		Station(const std::string& record);
	};

}

#endif