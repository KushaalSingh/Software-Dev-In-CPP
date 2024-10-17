#ifndef SENECA_CHARACTER_H
#define SENECA_CHARACTER_H
#include <iostream>
#include <iomanip>
#include <string>

namespace seneca {

	class Character {
		std::string m_name{};

	public:
		Character(const char* name) : m_name{ name } {}
		const std::string& getName() const { return m_name; }
		bool isAlive() const { return getHealth() > 0; }
		virtual int getAttackAmnt() const = 0;
		virtual int getDefenseAmnt() const = 0;
		virtual int getHealth() const = 0;
		virtual void setHealth(int health) = 0;
		virtual int getHealthMax() const = 0;
		virtual void setHealthMax(int health) = 0;
		virtual Character* clone() const = 0;
		virtual void attack(Character* enemy) = 0;
		virtual void takeDamage(int dmg) = 0;
		virtual ~Character() = default;

		friend std::ostream& operator<<(std::ostream& out, const Character& c)
		{
			out.setf(std::ios::left);
			out << std::setw(20) << c.m_name << "  ";
			out.unsetf(std::ios::left);

			int health = 100 * c.getHealth() / c.getHealthMax();
			out << "  Health: " << std::setw(3) << health << "% ";
			out << '(' << std::setw(4) << c.getHealth() << '/'
				<< std::setw(4) << c.getHealthMax() << ')';
			out << "  Attack: " << std::setw(4) << c.getAttackAmnt();
			out << "  Defense: " << std::setw(4) << c.getDefenseAmnt();
			return out;
		}
	};
}

#endif