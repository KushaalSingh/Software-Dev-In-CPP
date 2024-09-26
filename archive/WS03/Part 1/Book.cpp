#include "Book.h"

namespace seneca {

	Book::Book() : m_title(""), m_numChapters(0), m_numPages(0) {}

	Book::Book(const std::string& title, unsigned nChapters, unsigned nPages) : m_title(title), m_numChapters(nChapters), m_numPages(nPages) {}

	bool Book::valid() const {
		return (!m_title.empty()) && (m_numChapters > 0) && (m_numPages > 0);
	}

	double Book::calcAveragePages() const {
		return static_cast<double>(m_numPages) / m_numChapters;
	}

	std::ostream& Book::print(std::ostream& out) const {
		if (valid()) {
			out << std::setw(56) << std::right << (m_title + "," + std::to_string(m_numChapters) + "," + std::to_string(m_numPages)) << " | ";
			out << std::left << std::setw(14) << std::fixed << std::setprecision(6) << "(" + std::to_string(calcAveragePages()) + ")";
		}
		else std::cout << "| Invalid book data";
		return out;
	}

	Book& Book::operator= (const Book& src) {
		m_title = src.m_title;
		m_numChapters = src.m_numChapters;
		m_numPages = src.m_numPages;
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const Book& bk) {
		return bk.print(os);
	}
}