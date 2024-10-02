#ifndef SENECA_DICTIONARY_H
#define SENECA_DICTIONARY_H

#include "Event.h"

namespace seneca {
	
	enum class PartOfSpeech {
		Unknown,
		Noun,
		Pronoun,
		Adjective,
		Adverb,
		Verb,
		Preposition,
		Conjunction,
		Interjection,
	};
	
	struct Word {
		std::string m_word{};
		std::string m_definition{};
		PartOfSpeech m_pos = PartOfSpeech::Unknown;
	};
	
	class Dictionary {
		Word* m_words;
		size_t m_wordCount;

	public:
		Dictionary();
		Dictionary(const char* filename);
		void searchWord(const char* word);
	};

	PartOfSpeech mapPOS(std::string pos);
	std::string returnPOS(PartOfSpeech pos);
}

#endif