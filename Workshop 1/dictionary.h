#ifndef SENECA_DICTIONARY_H
#define SENECA_DICTIONARY_H

#include "event.h"

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
		~Dictionary();
		Dictionary(const Dictionary& src);
		Dictionary(Dictionary&& src) noexcept;
		Dictionary& operator = (const Dictionary& src);
		Dictionary& operator = (Dictionary&& src) noexcept;
		Dictionary(const char* filename);
		void searchWord(const char* word);
		size_t count() const;
	};

	PartOfSpeech mapPOS(std::string pos);
	std::string returnPOS(PartOfSpeech pos);
}

#endif