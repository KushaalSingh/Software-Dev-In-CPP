#include "guild.h"

namespace seneca {

	Guild::Guild() : m_characters(nullptr), m_name(""), m_size(0) {}

	Guild::Guild(const char* name) : m_characters(nullptr), m_name(name), m_size(0) {}

	Guild::Guild(const Guild& src) : m_characters(nullptr), m_name(src.m_name), m_size(src.m_size) {
		m_characters = new Character * [m_size];
		for (size_t i = 0; i < m_size; i++) m_characters[i] = src.m_characters[i];
	}

	Guild& Guild::operator=(const Guild& src) {
		if (this != &src) {
			for (size_t i = 0; i < m_size; i++) delete m_characters[i];
			delete[] m_characters;

			m_size = src.m_size;
			m_name = src.m_name;

			m_characters = new Character * [m_size];
			for (size_t i = 0; i < m_size; i++) m_characters[i] = src.m_characters[i];
		}
		return *this;
	}

	Guild::Guild(Guild&& src) noexcept : m_characters(src.m_characters), m_name(src.m_name), m_size(src.m_size) {
		src.m_characters = nullptr;
		src.m_name = "";
		src.m_size = 0;
	}

	Guild& Guild::operator = (Guild&& src) noexcept {
		if (this != &src) {
			for (size_t i = 0; i < m_size; i++) delete m_characters[i];
			delete[] m_characters;

			m_characters = src.m_characters;
			m_name = src.m_name;
			m_size = src.m_size;

			src.m_characters = nullptr;
			src.m_name = "";
			src.m_size = 0;
		}
		return *this;
	}

	Guild::~Guild() {
		for (size_t i = 0; i < m_size; i++) delete m_characters[i];
		delete[] m_characters;
		m_characters = nullptr;
	}

	void Guild::addMember(Character* c) {
		bool found = false;
		for (size_t i = 0; i < m_size; i++) if (m_characters[i]->getName() == c->getName()) found = true;

		c->setHealthMax(c->getHealthMax() + 300);

		if (!found) {
			Character** temp = new Character * [m_size + 1];
			for (size_t i = 0; i < m_size; i++) temp[i] = m_characters[i];
			temp[m_size] = c;

			delete[] m_characters;
			m_characters = temp;
			++m_size;
		}

	}

	void Guild::removeMember(const std::string& c) {

	}
}