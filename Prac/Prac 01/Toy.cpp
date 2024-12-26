#include "Toy.h"

namespace seneca {

	Toy::Toy() : m_id(0), m_name(""), m_numToys(0), m_grossPrice(0.00), m_netPrice(0.00) {}

	Toy::Toy(const std::string& toy) : m_id(0), m_name(""), m_numToys(0), m_grossPrice(0.00), m_netPrice(0.00) {
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
		m_numToys = std::stoi(num);
		m_grossPrice = std::stod(price);
		m_netPrice = m_grossPrice * 0.13;
	}

	void Toy::update(int numItems) {
		m_numToys = numItems;
	}

	std::ostream& operator << (std::ostream& os, const Toy& toy) {
		os << std::right << std::setw(8) << std::setfill('0') << toy.m_id << ": ";
		os << std::right << std::setw(24) << std::setfill('.') << toy.m_name;
		os << std::right << std::setw(2) << std::setfill(' ') << toy.m_numToys << " items @ ";
		os << std::right << std::setw(6) << std::setfill(' ') << toy.m_grossPrice << "/item subtotal: ";
		os << std::right << std::setw(7) << std::setfill(' ') << toy.m_grossPrice * toy.m_numToys << " tax: ";
		os << std::right << std::setw(7) << std::setfill(' ') << toy.m_netPrice - toy.m_grossPrice << " total: ";
		os << std::right << std::setw(7) << std::setfill(' ') << toy.m_netPrice << std::endl;
	}

	void trim(std::string& str) {
		int first = str.find_first_not_of(" ");
		int last = str.find_last_not_of(" ");

		str = str.substr(first, last - first + 1);
	}
}