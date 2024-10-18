#ifndef SENECA_GUILD_H
#define SENECA_GUILD_H

#include "character.h"

namespace seneca {

	class Guild {
		Character** m_characters;
		std::string m_name;
		size_t m_size;

	public:
		Guild();
		Guild(const char* name);
		Guild(const Guild& src);
		Guild& operator = (const Guild& src);
		Guild(Guild&& src) noexcept;
		Guild& operator=(Guild&& src) noexcept;
		~Guild();
		void addMember(Character* c);
		void removeMember(const std::string& c);
	};


}


#endif