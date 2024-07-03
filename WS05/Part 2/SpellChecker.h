#ifndef SENECA_SPELL_CHECKER_H
#define SENECA_SPELL_CHECKER_H

#include "Book.h"
#include <exception>
#include <fstream>
#include <algorithm>

namespace seneca {

	class SpellChecker {
	private:
		string m_badWords[6];
		string m_goodWords[6];
		void setDefault();
	public:
		SpellChecker();
		SpellChecker(const char* filename);
		void operator()(std::string& text);
	};
	void setWords(const string& str, string& badWord, string& goodWord);
}

#endif