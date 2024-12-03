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

	std::istream& Menu::read(int& sel, std::istream& in) const {
		char str[32];
		int value, stst = 1;
		//std::cin.ignore();
		while (stst) {
			in.getline(str, 32, '\n');
			int result = U.hasNonDigit(str, value);
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

	std::ostream& Menu::indent() const {
		for (int k = 0; k < m_numberOfTabs * 3; std::cout << " ", k++);
		return std::cout;
	}
}