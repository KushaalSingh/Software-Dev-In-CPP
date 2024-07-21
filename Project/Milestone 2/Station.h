// Name: Kushaal Singh
// Seneca Student ID: 115320228
// Seneca email: kna28@myseneca.ca
// Date of completion: 13/7/2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

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