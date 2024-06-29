#ifndef SENECA_RESERVATION_H
#define SENECA_RESERVATION_H

#include <iostream>
#include <string>

namespace seneca {

	typedef std::string string;
	typedef uint32_t uint;

	class Reservation {
	private:
		string resID;
		string resName;
		string email;
		uint numPeople;
		uint arrivalDay;
		uint arrivalHour;
		
	public:
		Reservation();
		Reservation(const string& res);
		void update(int day, int time);
		string returnReservationID(const string& _str);
		string returnReservatoinName(const string& _str);
		string returnEmail(const string& _str);
		uint returnNumberOfPeople(const string& _str);
	};
}

#endif
