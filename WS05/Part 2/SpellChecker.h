#ifndef SENECA_SPELL_CHECKER_H
#define SENECA_SPELL_CHECKER_H

#include <iostream>
#include <exception>
#include <fstream>

namespace seneca {

	class SpellChecker {
	private:
		char m_badWords[6];
		char m_goodWords[6];
		void setDefault();
	public:
		SpellChecker();
		SpellChecker(const char* filename);
	};

}

#endif