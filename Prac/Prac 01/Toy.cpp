#include "Toy.h"

namespace seneca {

	Toy::Toy() : m_id(0), m_name(""), m_quantity(0), m_grossPrice(0.00) {}

	Toy::Toy(const std::string& toy) : m_id(0), m_name(""), m_quantity(0), m_grossPrice(0.00) {

		try {
			if (toy[0] == '#') return;
			std::stringstream ss(toy);
			std::string id, name, num, price;

			std::getline(ss, id, ':');
			std::getline(ss, name, ':');
			std::getline(ss, num, ':');
			std::getline(ss, price);

			trim(id);
			trim(name);
			trim(num);
			trim(price);

			m_id = std::stoi(id);
			m_name = name;
			m_quantity = std::stoi(num);
			m_grossPrice = std::stod(price);
		}

		catch (const std::exception& e) {
			throw std::invalid_argument("Invalid string format: " + std::string(e.what()));
		}
	}

	void Toy::update(int numItems) {
		m_quantity = numItems;
	}

	std::ostream& operator << (std::ostream& os, const Toy& toy) {

		double subTotal = toy.m_grossPrice * toy.m_quantity;
		double tax = subTotal * toy.HST;
		double total = subTotal + tax;

		printAttribute<uint>(toy.m_id, 8, ": ", '0');
		printAttribute<std::string>(toy.m_name, 24, "", '.');
		printAttribute<uint>(toy.m_quantity, 2, " items @ ");
		printAttribute<double>(toy.m_grossPrice, 6, "/item subtotal: ");
		printAttribute<double>(subTotal, 7, " tax: ");
		printAttribute<double>(tax, 7, " total: ");
		printAttribute<double>(total, 7);
		os << std::endl;

		return os;
	}

	void trim(std::string& str) {
		int first = str.find_first_not_of(" ");
		int last = str.find_last_not_of(" ");

		str = str.substr(first, last - first + 1);
	}

	template<typename T>
	inline void printAttribute(T attribute, int size, std::string postCom, char fill) {
		std::cout << std::right << std::setw(8) << std::setfill(fill) << attribute << postCom;
	}
}