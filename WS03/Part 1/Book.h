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
		unsigned m_numChapters{};
		unsigned m_numPages{};

	public:
		Book();
		Book(const std::string& title, unsigned nChapters, unsigned nPages);
		std::ostream& print(std::ostream& out) const;
		bool valid() const;
		double calcAveragePages() const;
		Book& operator= (const Book& src);
	};
	std::ostream& operator<< (std::ostream& os, const Book& bk);



}


#endif