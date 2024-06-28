#ifndef SENECA_RESERVATION_H
#define SENECA_RESERVATION_H

#include <iostream>

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
	};



}

#endif // !SENECA_RESERVATION_H
