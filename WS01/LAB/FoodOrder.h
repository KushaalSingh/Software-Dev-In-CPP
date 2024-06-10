#ifndef SENECA_FOODORDER_H
#define SENECA_FOODORDER_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

extern double g_taxrate;
extern double g_dailydiscount;

namespace seneca {

	class FoodOrder {
	private:
		char m_custName[10];
		char m_description[25];
		double m_price;
		bool m_special;
	public:
		FoodOrder();
		std::ifstream& read(std::ifstream& in);
		void display() const;
	};


}

#endif