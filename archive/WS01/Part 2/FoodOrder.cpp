#include "FoodOrder.h"

double g_taxrate;
double g_dailydiscount;

namespace seneca {

	FoodOrder::FoodOrder() : m_description(nullptr), m_price(0.00), m_special(false) {
		m_custName[0] = '\0';
	}

	FoodOrder::~FoodOrder() {
		delete[] m_description;
		m_description = nullptr;
	}

	std::ifstream& FoodOrder::read(std::ifstream& in) {
		if (in.good()) {
			char specialStatus;
			str desc, custName;

			std::getline(in, custName, ',');
			std::getline(in, desc, ',');
			in >> m_price;
			in.ignore(10000, ',');
			in >> specialStatus;
			
			strncpy(m_custName, custName.c_str(), 10);
			m_description = new char[desc.length() + 1];
			strcpy(m_description,desc.c_str());
			m_special = (specialStatus == 'Y');
		}
		return in;
	}

	void FoodOrder::display() const {
		static int counter = 0;
		if (strlen(m_custName) == 0) std::cout << std::left << std::setw(2) << ++counter << ". No Order" << std::endl;
		else {
			double taxedPrice = m_price + (m_price * g_taxrate);
			std::cout << std::left << std::setw(2) << ++counter << ". " << std::setw(10) <<
				m_custName << "|" << std::setw(25) << m_description << "|" << std::setw(12) <<
				std::setprecision(2) << std::fixed << taxedPrice;
			if (m_special) {
				double discountedPrice = taxedPrice - g_dailydiscount;
				std::cout << std::right << std::setw(13) << std::setprecision(2) << std::fixed << discountedPrice;
			}
			std::cout << std::endl;
		}
	}

}