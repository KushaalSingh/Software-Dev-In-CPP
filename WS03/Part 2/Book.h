#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>

namespace seneca {

	typedef std::string string;

	class Book {
	private:
		string m_title{};
		uint32_t m_numChapters{};
		uint32_t m_numPages{};

	public:
		Book();
		Book(const std::string& title, uint32_t nChapters, uint32_t nPages);
		std::ostream& print(std::ostream& out) const;
		bool valid() const;
		double calcAveragePages() const;
		Book& operator = (const Book& src);
		bool operator < (const Book& src) const;
		bool operator > (const Book& src) const;
	};
	std::ostream& operator<< (std::ostream& os, const Book& bk);



}


#endif