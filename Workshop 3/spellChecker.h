// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
#ifndef SENECA_SPELLCHECKER_H
#define SENECA_SPELLCHECKER_H

#include <string>
#include <iostream>
#include <array>
#include <fstream>
#include <sstream>
#include <iomanip>

namespace seneca {

	class SpellChecker {
		static const size_t ARRAY_SIZE = 6;
		std::array<std::string, ARRAY_SIZE> m_badWords; 
		std::array<std::string, ARRAY_SIZE> m_goodWords; 
		std::array<size_t, ARRAY_SIZE> m_replacements{};

	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}
#endif