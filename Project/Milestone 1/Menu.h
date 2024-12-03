/*
Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.h
Version  1.0
Author   Kushaal Singh
Revision History
-----------------------------------------------------------
Date      Reason
2023/?/?  Preliminary release
2023/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
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

	int hasNonDigit(const char* str, int& value);
	bool isNegative(const char* str);
}


#endif
