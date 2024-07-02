#include "SpellChecker.h"

namespace seneca {

	void SpellChecker::setDefault() {
		m_badWords[0] = '\0';
		m_goodWords[0] = '\0';
	}

	SpellChecker::SpellChecker() {
		setDefault();
	}

	SpellChecker::SpellChecker(const char* filename) {
		setDefault();
		
		try {
			std::ifstream file(filename);
			if (file.is_open()) throw "Bad file name!";
			
		}

		catch (const char* errorMsg) {
			std::cout << errorMsg << std::endl;
		}
	}
}