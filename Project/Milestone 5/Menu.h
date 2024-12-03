#ifndef SENECA_MENU_H
#define SENECA_MENU_H

#include "Utils.h"

namespace seneca {

	class Menu {
	private:
		char* m_text;
		int m_numOptions;
		int m_numberOfTabs;
		void setEmpty();
		int returnNumOptions(const char* str) const;
		std::ostream& indent() const;

	public:
		Menu(const char* menuContent, int numberOfTabs = 0);
		~Menu();
		Menu(const Menu& src) = delete;
		Menu& operator=(const Menu& src) = delete;
		std::ostream& display(std::ostream& out = std::cout) const;
		std::istream& read(int& sel, std::istream& in = std::cin) const;
		int& operator>>(int& Selection);
	};
}


#endif