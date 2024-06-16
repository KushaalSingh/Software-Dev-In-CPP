#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

namespace seneca {

	class Book {
	private:
		std::string m_title{};
		unsigned m_numChapters{};
		unsigned m_numPages{};

	public:
		Book();
		Book(const std::string& title, unsigned nChapters, unsigned nPages);


		std::ostream& print(std::ostream& os) const;

	};
	std::ostream& operator<<(std::ostream& os, const Book& bk);


}


#endif