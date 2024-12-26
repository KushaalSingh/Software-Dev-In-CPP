#ifndef TOY_H
#define TOY_H

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>


typedef unsigned uint;

namespace seneca {

	class Toy {
		uint m_id;
		std::string m_name;
		uint m_numToys;
		double m_grossPrice;
		double m_netPrice;

	public:
		Toy();
		Toy(const std::string& toy);
		void update(int numItems);

		friend std::ostream& operator << (std::ostream& os, const Toy& toy);
	};

	void trim(std::string& str);
}

#endif