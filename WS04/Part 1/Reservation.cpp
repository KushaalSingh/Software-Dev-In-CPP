#include "Reservation.h"

namespace seneca {

	Reservation::Reservation() : resID(""), resName(""), email(""), numPeople(0), arrivalDay(0), arrivalHour(0) {}

	Reservation::Reservation(const string& res) : resID(""), resName(""), email(""), numPeople(0), arrivalDay(0), arrivalHour(0) {
		resID = returnReservationID(res);
		resName = returnReservatoinName(res);
		email = returnEmail(res);
		numPeople = returnNumberOfPeople(res);
		arrivalDay = returnArrivalDay(res);
		arrivalHour = returnArrivalHour(res);
	}

	void Reservation::update(int day, int time) {
		arrivalDay = day;
		arrivalHour = time;
	}

	std::ostream& operator << (std::ostream& out, const Reservation& res) {
		out << "Reservation";
		out << std::right << std::setw(10) << res.resID << ": ";
		out << std::right << std::setw(20) << res.resName << " ";
		out << std::left << std::setw(20) << "<" << res.email << ">" << " ";

		if (res.arrivalHour >= 6 && res.arrivalHour <= 9) out << "Breakfast ";
		else if (res.arrivalHour >= 3 && res.arrivalHour <= 11) out << "Lunch ";
		else if (res.arrivalHour >= 5 && res.arrivalHour <= 9) out << "Dinner ";
		else out << "Driinks ";

		out << "on day " << res.arrivalDay << " @ " << res.arrivalHour << ":00 for " << res.numPeople;
		if (res.numPeople > 1) out << " people" << std::endl;
		else out << " person" << std::endl;
		
	}

	std::ostream& hourBetween6and9(std::ostream& out, const Reservation& res) {
		out << "Breakfast on day " << res.arrivalDay << " @ " << res.arrivalHour << ":00 for " << res.numPeople;
		if (res.numPeople > 1) out << " people" << std::endl;
		else out << " person" << std::endl;
		return out;
	}

	string Reservation::returnReservationID(const string& _str) {
		uint firstChar = 0, lastChar = 0, x = _str.find(':');
		for (firstChar = 0; firstChar < x && _str[firstChar] == ' '; ++firstChar);
		for (lastChar = x; _str[lastChar - 1] == ' '; --lastChar);
		return _str.substr(firstChar, lastChar - firstChar);
	}

	string Reservation::returnReservatoinName(const string& _str) {
		uint firstChar = 0, lastChar = 0, x = _str.find(':');
		++x;
		string str = _str.substr(x, _str.find(',') - x);
		for (firstChar = 0; firstChar < str.length() && str[firstChar] == ' '; ++firstChar);
		for (lastChar = str.length(); str[lastChar - 1] == ' '; --lastChar);
		return str.substr(firstChar, lastChar - firstChar);
	}

	string Reservation::returnEmail(const string& _str) {
		uint firstChar = 0, lastChar = 0, com1 = 0, com2 = 0;
		com1 = _str.find(',');
		com2 = _str.find(',', com1 + 1);
		string str = _str.substr(com1 + 1, com2 - com1 - 1);
		for (firstChar = 0; firstChar < str.length() && str[firstChar] == ' '; ++firstChar);
		for (lastChar = str.length(); str[lastChar - 1] == ' '; --lastChar);
		return str.substr(firstChar, lastChar - firstChar);
	}

	uint Reservation::returnNumberOfPeople(const string& _str) {
		uint com1 = 0, com2 = 0, x = 0, i;
		for (i = 0; i < _str.length(); i++) {
			if (_str[i] == ',') {
				++x;
				if (x == 2) com1 = i;
				else if (x == 3) com2 = i;
			}
		}
		string str = _str.substr(com1 + 1, com2 - com1 - 1);
		return std::stoi(str);
	}

	uint Reservation::returnArrivalDay(const string& _str) {
		uint com1 = 0, com2 = 0, x = 0, i;
		for (i = 0; i < _str.length(); i++) {
			if (_str[i] == ',') {
				++x;
				if (x == 3) com1 = i;
				else if (x == 4) com2 = i;
			}
		}
		string str = _str.substr(com1 + 1, com2 - com1 - 1);
		return std::stoi(str);
	}

	uint Reservation::returnArrivalHour(const string& _str) {
		uint com1 = 0, x = 0, i;
		for (i = 0; i < _str.length(); i++) {
			if (_str[i] == ',') {
				++x;
				if (x == 4) com1 = i;
			}
		}
		string str = _str.substr(com1 + 1, com1 - _str.length());
		return std::stoi(str);
	}

	string subString(const string& str, uint pos1, uint pos2) {
		uint com1 = 0, com2 = 0, x = 0, i;
		for (i = 0; i < str.length(); i++) {
			if (str[i] == ',') {
				++x;
				if (x == pos1) com1 = i;
				else if (x == pos2) com2 = i;
			}
		}
		return str.substr(com1 + 1, com2 - com1 - 1);
	}
}