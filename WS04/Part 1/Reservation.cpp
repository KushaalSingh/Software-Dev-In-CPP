#include "Reservation.h"

namespace seneca {

	Reservation::Reservation() : resID(""), resName(""), email(""), numPeople(0), arrivalDay(0), arrivalHour(0) {}

	Reservation::Reservation(const string& res) : resID(""), resName(""), email(""), numPeople(0), arrivalDay(0), arrivalHour(0) {
		string id, name, _email, num, day, hour;
		uint col = res.find(':');
		resID = returnReservationID(res);
		resName = returnReservatoinName(res);
		email = returnEmail(res);
		numPeople = returnNumberOfPeople(res);

	}

	void Reservation::update(int day, int time) {
		arrivalDay = day;
		arrivalHour = time;
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
		uint firstChar = 0, lastChar = 0, com1 = 0, com2 = 0, x = 0, i;
		for (i = 0; i < _str.length(); i++) {
			if (_str[i] == ',') {
				++x;
				if (x == 1) com1 = i;
				else if (x == 2) com2 = i;
			}
		}
		string str = _str.substr(com1 + 1, com2 - com1 - 1);
		for (firstChar = 0; firstChar < str.length() && str[firstChar] == ' '; ++firstChar);
		for (lastChar = str.length(); str[lastChar - 1] == ' '; --lastChar);
		return str.substr(firstChar, lastChar - firstChar);
	}

	uint Reservation::returnNumberOfPeople(const string& _str) {
		uint firstChar = 0, lastChar = 0, com1 = 0, com2 = 0, x = 0, i;
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
}