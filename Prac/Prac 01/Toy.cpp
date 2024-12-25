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
	}

	void Toy::update(int numItems) {
		m_numToys = numItems;
	}

	void trim(std::string& str) {
		int first = str.find_first_not_of(" ");
		int last = str.find_last_not_of(" ");

		str = str.substr(first, last - first + 1);
	}
}