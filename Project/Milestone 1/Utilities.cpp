// Name: Kushaal Singh
// Seneca Student ID: 115320228
// Seneca email: kna28@myseneca.ca
// Date of completion: 13/7/2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"

namespace seneca {

	char Utilities::m_delimiter { ' ' };
	
	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	}

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		
		if (next_pos >= str.length() || emptyStr(str)) {
			more = false;
			return "";
		}

		size_t delim = str.find(m_delimiter, next_pos);
		if (delim == std::string::npos) delim = str.length();
		else if (delim == next_pos) {
			more = false;
			throw std::runtime_error("Delimiter found at next_pos");
		}

		std::string token = str.substr(next_pos, delim - next_pos);
		next_pos = delim + 1;

		token = trim(token);

		if (m_widthField < token.length()) m_widthField = token.length();
		more = (next_pos < str.length());

		return token;
	}

	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter() {
		return m_delimiter;
	}

	std::string trim(const std::string& str) {
		auto first = str.find_first_not_of(' ');
		auto last = str.find_last_not_of(' ');
		return str.substr(first, last - first + 1);
	}

	bool emptyStr(const std::string& str) {
		return str.empty() || std::all_of(str.begin(), str.end(), [](const char c) { return std::isspace(c); });
	}
}