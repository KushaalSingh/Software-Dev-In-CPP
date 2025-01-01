#ifndef TOY_H
#define TOY_H

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <exception>

namespace seneca {

	typedef unsigned uint;

	class Toy {
		uint m_id;
		std::string m_name;
		uint m_quantity;
		double m_grossPrice;
		double m_netPrice;
		static constexpr double HST = 0.13;

	public:
		Toy();
		Toy(const std::string& toy);
		void update(int numItems);

		friend std::ostream& operator << (std::ostream& os, const Toy& toy);
	};

	void trim(std::string& str);
	template<typename T>
	inline void printAttribute(T attribute, int size, std::string postCom = "", char fill = ' ');
}

#endif