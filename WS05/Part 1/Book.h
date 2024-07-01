#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

namespace seneca {

	typedef std::string string;

	class Book {
	private:
		string m_author;
		string m_title;
		string m_countryOfPub;
		size_t m_yearOfPub;
		double m_price;
		string m_summery;

	public:
		Book();
		Book(const string& strBook);
		const string& title() const;
		const string& country() const;
		const size_t& year() const;
		double& price();

		friend std::ostream& operator << (std::ostream& os, const Book& src);
	};

	string subString(string _str, int column);
}

#endif