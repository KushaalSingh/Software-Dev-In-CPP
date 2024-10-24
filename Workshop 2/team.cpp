#include "team.h"

namespace seneca {

	Team::Team() : m_characters(nullptr), m_name(""), m_size(0) {}

	Team::Team(const char* name) : m_characters(nullptr), m_name(name), m_size(0) {}

	Team::Team(const Team& src) : m_characters(nullptr), m_name(src.m_name), m_size(src.m_size) {
		m_characters = new Character * [m_size];
		for (size_t i = 0; i < m_size; i++) m_characters[i] = src.m_characters[i]->clone();
	}

	Team& Team::operator = (const Team& src) {
		if (this != &src) {
			for (size_t i = 0; i < m_size; i++) delete m_characters[i];
			delete[] m_characters;

			m_size = src.m_size;
			m_name = src.m_name;

			m_characters = new Character * [m_size];
			for (size_t i = 0; i < m_size; i++) m_characters[i] = src.m_characters[i]->clone();
		}
		return *this;
	}

	Team::Team(Team&& src) noexcept : m_characters(src.m_characters), m_name(src.m_name), m_size(src.m_size) {
		src.m_characters = nullptr;
		src.m_name = "";
		src.m_size = 0;
	}

	Team& Team::operator = (Team&& src) noexcept {
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

	Team::~Team() {
		for (size_t i = 0; i < m_size; i++) delete[] m_characters[i];
		delete[] m_characters;
		m_characters = nullptr;
	}

	void Team::addMember(const Character* c) {
		bool found = false;
		for (size_t i = 0; i < m_size; i++) if (m_characters[i]->getName() == c->getName()) found = true;

		if (!found) {
			Character** temp = new Character * [m_size + 1];
			for (size_t i = 0; i < m_size; i++) temp[i] = m_characters[i]->clone();
			temp[m_size] = c->clone();
			delete[] m_characters;
			m_characters = temp;
			++m_size;
		}
	}

	void Team::removeMember(const std::string& c) {
		size_t index = m_size;
		for (size_t i = 0; i < m_size; ++i) {
			if (m_characters[i]->getName() == c) {
				index = i;
				break;
			}
		}

		delete m_characters[index];

		Character** temp = new Character * [m_size];
		for (size_t i = 0, k = 0; i < m_size; ++i) {
			if (i != index) {
				temp[k++] = m_characters[i];
			}
		}

		delete[] m_characters;
		m_characters = temp;
		--m_size;
	}

	Character* Team::operator[](size_t idx) const {
		if (idx < m_size) return m_characters[idx];
		return nullptr;
	}

	void Team::showMembers() const {
		if (m_characters) {
			std::cout << "[Team] " << m_name << std::endl;
			for (size_t i = 0; i < m_size; i++) std::cout << std::setw(5) << (i + 1) << ": " << *m_characters[i] << std::endl;
		}
		else std::cout << "No team." << std::endl;
	}
}