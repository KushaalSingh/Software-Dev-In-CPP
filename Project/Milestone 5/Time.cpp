/*
Citation and Sources...
Final Project Milestone 1
Module: Time
Filename: Time.cpp
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

#include "Time.h"

namespace seneca {

	Time& Time::reset() {
		minutes = U.getTime();
		return *this;
	}

	Time::Time(unsigned int min) {
		minutes = min;
	}

	std::ostream& Time::write(std::ostream& out) const {
		unsigned int hours = minutes / 60;
		unsigned int mints = minutes % 60;
		out.width(2);
		out.fill('0');
		out << hours << ":";
		out.width(2);
		out << mints;
		return out;
	}

	std::istream& Time::read(std::istream& in) {
		unsigned int hour, mins;
		char input[6];
		in.get(input, 6, ',');
		if (!(validateAndSetInput(input, hour, mins))) {
			in.setstate(std::ios::failbit);
			return in;
		}
		else minutes = hour * 60 + mins;
		return in;
	}

	Time::operator unsigned int() const {
		return minutes;
	}

	Time& Time::operator*= (int val) {
		minutes *= val;
		return *this;
	}

	Time& Time::operator-= (const Time& D) {
		if (minutes <= D.minutes) minutes = (minutes + 1440) - D.minutes;
		else minutes = minutes - D.minutes;
		return *this;
	}

	Time Time::operator- (const Time& T) const {
		int difference = minutes - T.minutes;
		if (difference < 0) difference += 1440;
		return Time(difference);
	}

	std::ostream& operator<< (std::ostream& out, const Time& src) {
		return src.write(out);
	}

	std::istream& operator>> (std::istream& in, Time& src) {
		return src.read(in);
	}

	bool Time::validateAndSetInput(const char* input, unsigned int& hour, unsigned int& mins) {
		char hourStr[32] = { '\0' };
		char minStr[32] = { '\0' };
		int divd = 0, i;
		if (std::strchr(input, ':') == nullptr) return false;
		for (i = 0; i < (int)strlen(input); i++) {
			if (input[i] != ':') hourStr[i] = input[i];
			else if (input[i] == ':') divd = i;
		}
		for (i = divd + 1; i < (int)strlen(input); i++) minStr[i - divd - 1] = input[i];
		hour = atoi(hourStr);
		mins = atoi(minStr);
		if (hourStr[0] == '0' && minStr[0] == '0') return true;
		else if (hourStr[0] == '0' && minStr[0] != '0' && mins) return true;
		else if (hourStr[0] != '0' && minStr[0] == '0' && hour) return true;
		else if (hour && mins) return true;
		else return false;
	}


}