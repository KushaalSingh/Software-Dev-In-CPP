#ifndef SENECA_TEAM_H
#define SENECA_TEAM_H

#include "character.h"

namespace seneca {

	
	class Team {
		Character** m_characters;
		std::string m_name;
		size_t m_size;

	public:
		Team();
		Team(const char* name);
		Team(const Team& src);
		Team& operator = (const Team& src);
		Team(Team&& src) noexcept;
		Team& operator = (Team&& src) noexcept;
		~Team();
		void addMember(const Character* c);
		void removeMember(const std::string& c);
		Character* operator[](size_t idx) const;
		void showMembers() const;
	};

}


#endif