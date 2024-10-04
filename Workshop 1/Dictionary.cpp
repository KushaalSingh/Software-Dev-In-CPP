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
		m_wordCount = count;
		m_words = new Word[m_wordCount];

		file.clear();
		file.seekg(0, std::ios::beg);

		size_t i = 0;
		while (std::getline(file, line)) {
			std::stringstream sstr(line);
			std::string word, pos, def;

			std::getline(sstr, word, ',');
			std::getline(sstr, pos, ',');
			std::getline(sstr, def);

			m_words[i].m_word = word;
			m_words[i].m_pos = mapPOS(pos);
			m_words[i].m_definition = def;
			++i;
		}
	}

	void Dictionary::searchWord(const char* word) {
		bool found = false;

		for (size_t i = 0; i < m_wordCount; i++) {
			if (word == m_words[i].m_word) {
				if (!found) std::cout << m_words[i].m_word;

				std::cout << (found ? std::setw(m_words[i].m_word.length() + 3) : std::setw(0)) << " - "
					<< (!g_settings.m_verbose || m_words[i].m_pos == PartOfSpeech::Unknown ? "" : ("(" + returnPOS(m_words[i].m_pos) + ") "))
					<< m_words[i].m_definition << std::endl;

				if (!g_settings.m_show_all) return;
				found = true;
			}
		}
		if (!found) std::cout << "Word '" << word << "' was not found in the dictionary." << std::endl;
	}

	PartOfSpeech mapPOS(std::string pos) {
		if (pos == "n." || pos == "n. pl.") return PartOfSpeech::Noun;
		else if (pos == "adv.") return PartOfSpeech::Adverb;
		else if (pos == "a.") return PartOfSpeech::Adjective;
		else if (pos == "v." || pos == "v. i." || pos == "v. t." || pos == "v. t. & i.") return PartOfSpeech::Verb;
		else if (pos == "prep.") return PartOfSpeech::Preposition;
		else if (pos == "pron.") return PartOfSpeech::Pronoun;
		else if (pos == "conj.") return PartOfSpeech::Conjunction;
		else if (pos == "interj.") return PartOfSpeech::Interjection;
		else return PartOfSpeech::Unknown;
	}

	std::string returnPOS(PartOfSpeech pos) {
		switch (pos) {
		case seneca::PartOfSpeech::Unknown:
			return "unknown";
		case seneca::PartOfSpeech::Noun:
			return "noun";
		case seneca::PartOfSpeech::Pronoun:
			return "pronoun";
		case seneca::PartOfSpeech::Adjective:
			return "adjective";
		case seneca::PartOfSpeech::Adverb:
			return "adverb";
		case seneca::PartOfSpeech::Verb:
			return "verb";
		case seneca::PartOfSpeech::Preposition:
			return "preposition";
		case seneca::PartOfSpeech::Conjunction:
			return "conjuncation";
		case seneca::PartOfSpeech::Interjection:
			return "interjection";
		default:
			return "unknown";
		}
	}
}