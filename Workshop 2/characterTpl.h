#ifndef SENECA_CHARACTER_TPL
#define SENECA_CHARACTER_TPL

#include "character.h"

namespace seneca {
	
	template <typename T>
	class CharacterTpl : public Character {
		int m_healthMax;
		T m_health;

	public:
		CharacterTpl(std::string name, int maxHealth);
		void takeDamage(int dmg) override;
		int getHealth() const override;
		int getHealthMax() const override;
		void setHealth(int health) override;
		void setHealthMax(int health) override;
	};

	template <typename T>
	CharacterTpl<T>::CharacterTpl(std::string name, int maxHealth) : Character(name.c_str()), m_healthMax(maxHealth) {
		m_health = maxHealth;
	}

	template <typename T>
	void CharacterTpl<T>::takeDamage(int dmg) {
		m_health -= dmg;
		if (m_health <= 0) std::cout << getName() << "has been defeated!" << std::endl;
		else std::cout << "    " << getName() << " took " << dmg << " damage," << m_health << " health remaining." << std::endl;
	}

	template <typename T> 
	int CharacterTpl<T>::getHealth() const {
		return static_cast<int>(m_health);
	}

	template <typename T>
	int CharacterTpl<T>::getHealthMax() const {
		return m_healthMax;
	}

	template <typename T>
	void CharacterTpl<T>::setHealth(int health) {
		m_health = health;
	}

	template <typename T>
	void CharacterTpl<T>::setHealthMax(int health) {
		m_healthMax = health;
		m_health = health;
	}
}

#endif