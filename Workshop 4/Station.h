// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#ifndef SENECA_STATION_H
#define SENECA_STATION_H

#include "Utilities.h"
#include <iomanip>

namespace seneca {

	typedef unsigned uint;

	class Station {
	private:
		int m_ID;
		std::string m_itemName;
		std::string m_description;
		uint m_serialNumber;
		uint m_stockQunatity;

		static size_t m_widthField;
		static uint id_generator;

	public:
		Station(const std::string& record);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}

#endif