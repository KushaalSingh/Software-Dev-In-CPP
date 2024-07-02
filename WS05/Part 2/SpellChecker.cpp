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
		int i = 0;
		try {
			std::ifstream file(filename);
			if (file.is_open()) throw "Bad file name!";
			while (file && i < 6) {
				string wordsString = "";
				std::getline(file, wordsString);
				setWords(wordsString, m_badWords[i], m_goodWords[i]);
				++i;
			}
		}
		catch (const char* errorMsg) {
			std::cout << errorMsg << std::endl;
		}
	}

	void setWords(const string& str, string& badWord, string& goodWord) {
		int alph1 = 0, alph2 = 0, i = 0, k = 0, l = 0;
		bool first = true, last = false;
		for (i = 0; i < str.length() && !last; i++) {
			if (str[i] != ' ') {
				alph1 = i;
				for (k = i; k < str.length() && first; k++) {
					if (str[k] == ' ') {
						alph2 = k;
						first = false;
					}
				}
				badWord = str.substr(alph1, alph2 - alph1);
				for (l = k; l < str.length() && !last; l++) {
					if (str[l] != ' ') {
						alph1 = l;
						for (k = l; k < str.length(); k++) if (str[k] == '\n') alph2 = k;
						goodWord = str.substr(alph1, alph2 - alph1);
						last = true;
					}
				}
			}
		}
	}
}