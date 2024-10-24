#ifndef SENECA_BARBARIAN_H
#define SENECA_BARBARIAN_H

#include "characterTpl.h"

namespace seneca {

	template <typename T, typename Ability_t, typename Weapon_t>
	class Barbarian : public CharacterTpl<T> {
		int m_baseDefense;
		int m_baseAttack;
		Ability_t m_ability;
		Weapon_t m_weapon[2];

	public:
		Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t primaryWeapon, Weapon_t secondaryWeapon);
		int getAttackAmnt() const;
		int getDefenseAmnt() const;
		Character* clone() const;
		void attack(Character* enemy);
		void takeDamage(int dmg);
	};

	template <typename T, typename Ability_t, typename Weapon_t>
	Barbarian<T, Ability_t, Weapon_t>::Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t primaryWeapon, Weapon_t secondaryWeapon) : CharacterTpl<T>(name, healthMax), m_baseDefense(baseDefense), m_baseAttack(baseAttack) {
		m_weapon[0] = primaryWeapon;
		m_weapon[1] = secondaryWeapon;
	}

	template <typename T, typename Ability_t, typename Weapon_t>
	int Barbarian<T, Ability_t, Weapon_t>::getAttackAmnt() const {
		return static_cast<int>(m_baseAttack + (m_weapon[0] / 2) + (m_weapon[1] / 2));
	}

	template <typename T, typename Ability_t, typename Weapon_t>
	int Barbarian<T, Ability_t, Weapon_t>::getDefenseAmnt() const {
		return m_baseDefense;
	}

	template <typename T, typename Ability_t, typename Weapon_t> 
	Character* Barbarian<T, Ability_t, Weapon_t>::clone() const {
		return new Barbarian(*this);
	}

	template <typename T, typename Ability_t, typename Weapon_t> 
	void Barbarian<T, Ability_t, Weapon_t>::attack(Character* enemy) {
		std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;

		m_ability.useAbility(this);
		auto damage = getAttackAmnt();
		m_ability.transformDamageDealt(damage);

		std::cout << "    Barbarian deals " << damage << " melee damage!" << std::endl;
		enemy->takeDamage(damage);
	}

	template <typename T, typename Ability_t, typename Weapon_t>
	void Barbarian<T, Ability_t, Weapon_t>::takeDamage(int dmg) {
		std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
		std::cout << "    Barbarian has a defense of " << m_baseDefense << ". Reducing damage received." << std::endl;

		dmg -= m_baseDefense;
		if (dmg < 0) dmg = 0;

		m_ability.transformDamageReceived(dmg);
		CharacterTpl<T>::takeDamage(dmg);
	}
}


#endif