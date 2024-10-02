#include "Dictionary.h"
#include <fstream>
#include <sstream>
namespace seneca {
	
	Dictionary::Dictionary() : m_words(nullptr), m_wordCount(0) {}

	Dictionary::Dictionary(const char* filename) : m_words(nullptr), m_wordCount(0) {
		std::ifstream file(filename);
		if (!file.is_open()) return;
		std::string line = "";
		size_t count = 0;

		while (std::getline(file, line)) count++;
		m_words = new Word[m_wordCount];

		file.clear();
		file.seekg(0, std::ios::beg);

		size_t i = 0;
		while (std::getline(file, line)) {
			std::stringstream sstr(line);
			std::string word, pos, def;

			std::getline(sstr, word, ',');
			std::getline(sstr, pos, ',');
			std::getline(sstr, def, ',');

			m_words[i].m_word = word;
			m_words[i].m_pos = mapPOS(pos);
			m_words[i].m_definition = def;
		}
	}

	PartOfSpeech mapPOS(std::string pos) {
		if (pos == "n." || "n. pl.") return PartOfSpeech::Noun;
		else if (pos == "adv.") return PartOfSpeech::Adverb;
		else if (pos == "a.") return PartOfSpeech::Adjective;
		else if (pos == "v." || "v. i." || "v. t." || "v. t. & i.") return PartOfSpeech::Verb;
		else if (pos == "prep.") return PartOfSpeech::Preposition;
		else if (pos == "pron.") return PartOfSpeech::Pronoun;
		else if (pos == "conj.") return PartOfSpeech::Conjunction;
		else if (pos == "interj.") return PartOfSpeech::Interjection;
		else return PartOfSpeech::Unknown;
	}
}