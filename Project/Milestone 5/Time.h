/*
Citation and Sources...
Final Project Milestone 1
Module: Time
Filename: Time.h
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

#ifndef SENECA_TIME_H
#define SENECA_TIME_H

#include "Utils.h"
#include <cstring>

namespace seneca {

	class Time {
	private:
		unsigned int minutes;
	public:
		Time& reset();
		Time(unsigned int min = 0u);
		std::ostream& write(std::ostream& out = std::cout) const;
		std::istream& read(std::istream& in = std::cin);
		operator unsigned int() const;
		Time& operator*= (int val);
		Time& operator-= (const Time& D);
		Time operator- (const Time& T) const;
		bool validateAndSetInput(const char* input, unsigned int& hour, unsigned int& mins);
	};

	std::ostream& operator<< (std::ostream& out, const Time& src);
	std::istream& operator>> (std::istream& in, Time& src);
}

#endif 