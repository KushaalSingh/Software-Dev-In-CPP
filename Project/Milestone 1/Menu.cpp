/*
Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
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

#include "Menu.h"
#include "Utils.h"

namespace seneca {
	Menu::Menu(const char* menuContent, int numberOfTabs) {
		setEmpty();
		m_text = new char[strlen(menuContent) + 1];
		strcpy(m_text, menuContent);
		m_numberOfTabs = numberOfTabs;
		m_numOptions = returnNumOptions(menuContent);
	}

	int Menu::returnNumOptions(const char* str) const {
		int options = 0;
		for (int i = 0; i < (int)strlen(str); i++) if (str[i] == '\n') options++;
		return options;
	}

	void Menu::setEmpty() {
		m_text = nullptr;
		m_numberOfTabs = 0;
		m_numOptions = 0;
	}

	Menu::~Menu() {
		delete[] m_text;
		m_text = nullptr;
	}

	std::ostream& Menu::display(std::ostream& out) const {
		for (int i = 0; i < (int)strlen(m_text); i++) {
			for (int k = 0; k < m_numberOfTabs * 3 && (i == 0 || m_text[i - 1] == '\n'); std::cout << " ", k++);
			std::cout << m_text[i];
		}
		std::cout << std::endl;
		indent() << "0- Exit" << std::endl;
		indent() << "> ";
		return out;
	}

	std::istream& Menu::read(int& sel, std::istream& in) const{
		char str[32];
		int value, stst = 1;
		while (stst) {
			in.getline(str, 32, '\n');
			int result = hasNonDigit(str, value);
			switch (result) {
				case 0:
					std::cout << "Bad integer value, try again: ";
					break;
				case 1:
					std::cout << "Only enter an integer, try again: ";
					break;
				case 2: 
					if (value < 0 || value > m_numOptions) {
						std::cout << "Invalid value enterd, retry[0 <= value <= " << m_numOptions << "]: ";
					}
					else {
						sel = value;
						stst = 0;
						return in;
					}
					break;
				case -1:
					std::cerr << "ERROR: This should not happen";
					break;
			}
		}
		return in;
	}

	int& Menu::operator>>(int& Selection) {
		display();
		read(Selection, std::cin);
		return Selection;
	}

	int hasNonDigit(const char* str, int& value) {
		int digit = 0;
		int str_len = (int)strlen(str);
		bool isNgtv = isNegative(str);
		if (isNgtv) digit++;
		for (int i = 0; i < str_len; i++) if (str[i] >= 48 && str[i] <= 57) digit++;
		if (digit == 0) return 0;
		else if (digit < str_len) return 1;
		else if (digit == str_len) {
			value = atoi(str);
			return 2;
		}
		else return -1;
	}

	bool isNegative(const char* str) {
		for (int i = 0; i < (int)strlen(str); i++) if (str[i] >= 48 && str[i] <= 57 && str[i - 1] == '-') return true;
		return false;
	}

	std::ostream& Menu::indent() const {
		for (int k = 0; k < m_numberOfTabs * 3; std::cout << " ", k++);
		return std::cout;
	}
}