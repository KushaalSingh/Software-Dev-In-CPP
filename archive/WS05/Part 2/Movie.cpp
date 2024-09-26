#include "Movie.h"

namespace seneca {

	Movie::Movie() : m_title(""), m_releaseYear(0), m_description("") {}

	Movie::Movie(const std::string& strMovie) : m_title(subString(strMovie, 1, 3)), m_releaseYear(std::stoull(subString(strMovie, 2, 3))), m_description(subString(strMovie, 3, 3)) {}

	const string& Movie::title() const {
		return m_title;
	}

	std::ostream& operator << (std::ostream& out, const Movie& src) {
		out << std::setw(40) << src.m_title << " | " << std::setw(4) << src.m_releaseYear << " | " << src.m_description << std::endl;
		return out;
	}
}