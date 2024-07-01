#include "Book.h"

namespace seneca {

	Book::Book() : m_author(""), m_title(""), m_countryOfPub(""), m_yearOfPub(0), m_price(0), m_summery("") {}

	Book::Book(const string& strBook) : m_author(""), m_title(""), m_countryOfPub(""), m_yearOfPub(0), m_price(0), m_summery("") {

	}

	const string& Book::title() const {
		return m_title;
	}

	const string& Book::country() const {
		return m_countryOfPub;
	}

	const size_t& Book::year() const {
		return m_yearOfPub;
	}

	double& Book::price() {
		return m_price;
	}

}