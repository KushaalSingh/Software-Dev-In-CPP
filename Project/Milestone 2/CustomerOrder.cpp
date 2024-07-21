// Name: Kushaal Singh
// Seneca Student ID: 115320228
// Seneca email: kna28@myseneca.ca
// Date of completion: 20/7/2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "CustomerOrder.h"

namespace seneca {

	size_t CustomerOrder::m_widthField { 0 };

	Item::Item(const std::string& src) : m_itemName(src) {}

	CustomerOrder::CustomerOrder() : m_name(""), m_product(""), m_cntItem(0), m_lstItem(nullptr) {}

	CustomerOrder::CustomerOrder(const std::string line) : m_name(""), m_product(""), m_cntItem(0), m_lstItem(nullptr) {
		Utilities U;
		bool more = true;
		size_t pos = 0;

		m_name = U.extractToken(line, pos, more);
		m_product = U.extractToken(line, pos, more);

		size_t i = 0, temp_pos = pos;
		while (more) {
			U.extractToken(line, temp_pos, more);
			++i;
		}
		m_lstItem = new Item*[i];
		m_cntItem = i;

		more = true;
		for (size_t i = 0; i < m_cntItem; i++) m_lstItem[i] = new Item(U.extractToken(line, pos, more));

		if (m_widthField < U.getFieldWidth()) m_widthField = U.getFieldWidth();
	}

	CustomerOrder::CustomerOrder(const CustomerOrder& src) {
		throw std::runtime_error("Copy constructor called");
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept : m_name(""), m_product(""), m_cntItem(0), m_lstItem(nullptr) {
		*this = std::move(src);
	}

	CustomerOrder& CustomerOrder::operator = (CustomerOrder&& src) noexcept {
		if (this != &src) {
			if (m_lstItem) {
				for (size_t i = 0; i < m_cntItem; i++) delete m_lstItem[i];
				delete[] m_lstItem;
			}

			m_name = src.m_name;
			m_product = src.m_product;
			m_cntItem = src.m_cntItem;
			m_lstItem = src.m_lstItem;

			src.m_name = "";
			src.m_product = "";
			src.m_cntItem = 0;
			src.m_lstItem = nullptr;
		}
		return *this;
	}

	CustomerOrder::~CustomerOrder() {
		for (size_t i = 0; i < m_cntItem; i++) delete m_lstItem[i];
		delete[] m_lstItem;
		m_lstItem = nullptr;
	}

	bool CustomerOrder::isOrderFilled() const {
		for (size_t i = 0; i < m_cntItem; i++) if (m_lstItem[i]->m_isFilled == false) return false;
		return true;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		for (size_t i = 0; i < m_cntItem; i++) if (m_lstItem[i]->m_itemName == itemName && !m_lstItem[i]->m_isFilled) return false;
		return true;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os) {
		for (size_t i = 0; i < m_cntItem; i++) {
			if (station.getItemName() == m_lstItem[i]->m_itemName && station.getQuantity()) {
				m_lstItem[i]->m_isFilled = true;
				m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
				station.updateQuantity();
				os << "Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
			}
			else if (!station.getQuantity()) os << "Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
		}
	}

	void CustomerOrder::display(std::ostream& os) const {
		os << m_name << " - " << m_product << std::endl;
		
		for (size_t i = 0; i < m_cntItem; i++) {
			os << std::setw(6) <<  " [" << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] " << std::setfill(' ') << std::setw(m_widthField) << std::left << m_lstItem[i]->m_itemName << " - ";
			os << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << std::endl;
		}
	}
}