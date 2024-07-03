#ifndef SENECA_SPELL_CHECKER_H
#define SENECA_SPELL_CHECKER_H

#include "Book.h"
#include <exception>
#include <fstream>
#include <algorithm>

namespace seneca {

	const int SIZE = 6;

	class SpellChecker {
	private:
		string m_badWords[SIZE];
		string m_goodWords[SIZE];
		int m_replacements[SIZE];

		void setDefault();
	public:
		SpellChecker();
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
	void setWords(const string& str, string& badWord, string& goodWord);
}

#endif