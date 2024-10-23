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

		if (!found) {
			c->setHealthMax(c->getHealthMax() + 300);
			Character** temp = new Character * [m_size + 1];
			for (size_t i = 0; i < m_size; i++) temp[i] = m_characters[i];
			temp[m_size] = c;

			delete[] m_characters;
			m_characters = temp;
			++m_size;
		}

	}

	void Guild::removeMember(const std::string& c) {
		size_t index = m_size;
		for (size_t i = 0; i < m_size; ++i) {
			if (m_characters[i]->getName() == c) {
				index = i;
				break;
			}
		}

		if (index == m_size) return;

		m_characters[index]->setHealthMax(m_characters[index]->getHealthMax() - 300);
		Character** temp = new Character * [m_size - 1];

		for (size_t i = 0, k = 0; i < m_size; i++) if (i != index) temp[k++] = m_characters[i];

		delete[] m_characters;
		m_characters = temp;
		--m_size;
	}

	Character* Guild::operator[](size_t idx) const {
		if (idx < m_size) return m_characters[idx];
		return nullptr;
	}

	void Guild::showMembers() const {
		std::cout << "[Guild] " << m_name << std::endl;
		for (size_t i = 0; i < m_size; i++) std::cout << std::setw(5) << (i + 1) << ": " << *m_characters[i] << std::endl;
	}
}