#include "Book.h"

namespace seneca {

	Book::Book() : m_author(""), m_title(""), m_countryOfPub(""), m_yearOfPub(0), m_price(0), m_summery("") {}

	Book::Book(const string& strBook) : m_author(""), m_title(""), m_countryOfPub(""), m_yearOfPub(0), m_price(0), m_summery("") {
		m_author = subString(strBook, 1);
		m_title = subString(strBook, 2);
		m_countryOfPub = subString(strBook, 3);
		auto tempYear = subString(strBook, 4);
		m_yearOfPub = std::stoull(tempYear);
		auto price = subString(strBook, 5);
		m_price = std::stod(price);
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

	std::ostream& operator << (std::ostream& os, const Book& src) {
		os << std::setw(20) << src.m_author << std::setw(22) << src.m_title << 
			std::setw(5) << src.m_countryOfPub << std::setw(4) << src.m_yearOfPub << 
			std::setw(6) << std::fixed << std::setprecision(2) << src.m_price << std::endl;
	}

	string subString(string _str, int column) {
		string str;
		int firstChar, lastChar, count = 0, c1 = 0, c2 = 0;
		for (int i = 0; i < _str.length(); i++) {
			if (_str[i] == ',') {
				++count;
				c1 = c2;
				if (c2) ++c1;
				c2 = i;
			}
			if (column == 6) str = _str.substr(c1, _str.length());
			if (count == column) str = _str.substr(c1, c2 - c1);
		}
		for (firstChar = 0; firstChar < str.length() && str[firstChar] == ' '; ++firstChar);
		for (lastChar = str.length(); str[lastChar - 1] == ' '; --lastChar);
		return str.substr(firstChar, lastChar - firstChar);
	}
}