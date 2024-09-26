#ifndef MOVIE_H
#define MOVIE_H

#include "Book.h"

namespace seneca {

	class Movie {
	private:
		string m_title;
		size_t m_releaseYear;
		string m_description;

	public:
		Movie();
		Movie(const std::string& strMovie);
		const string& title() const;

		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_title);
			spellChecker(m_description);
		}

		friend std::ostream& operator << (std::ostream& out, const Movie& src);
	};


}

#endif