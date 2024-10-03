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
			sstr.ignore();
			std::getline(sstr, def, '\"');

			m_words[i].m_word = word;
			m_words[i].m_pos = mapPOS(pos);
			m_words[i].m_definition = ("\"" + def + "\"");
			++i;
		}
	}

	void Dictionary::searchWord(const char* word) {
		bool cont = true, found = false;

		for (int i = 0; i < m_wordCount; i++) {
			if (word == m_words[i].m_word) {
				if (!found) std::cout << m_words[i].m_word;

				std::cout << std::right << std::setw(m_words[i].m_word.length()) << " - "
					<< (!g_settings.m_verbose || m_words[i].m_pos == PartOfSpeech::Unknown ? "" : ("(" + returnPOS(m_words[i].m_pos) + ") "))
					<< m_words[i].m_definition << std::endl;

				if (!g_settings.m_show_all) return;
				found = true;
			}
		}
		if (!found) std::cout << "Word '" << word << "' was not found in the dictionary." << std::endl;
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

	std::string returnPOS(PartOfSpeech pos) {
		switch (pos) {
		case seneca::PartOfSpeech::Unknown:
			return "Unknown";
		case seneca::PartOfSpeech::Noun:
			return "Noun";
		case seneca::PartOfSpeech::Pronoun:
			return "Pronoun";
		case seneca::PartOfSpeech::Adjective:
			return "Adjective";
		case seneca::PartOfSpeech::Adverb:
			return "Adverb";
		case seneca::PartOfSpeech::Verb:
			return "Verb";
		case seneca::PartOfSpeech::Preposition:
			return "Preposition";
		case seneca::PartOfSpeech::Conjunction:
			return "Conjuncation";
		case seneca::PartOfSpeech::Interjection:
			return "Interjection";
		default:
			return "Unknown";
		}
	}
}