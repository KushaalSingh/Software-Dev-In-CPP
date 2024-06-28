#include "Reservation.h"

namespace seneca {

	Reservation::Reservation() : resID(""), resName(""), email(""), numPeople(0), arrivalDay(0), arrivalHour(0) {}

	Reservation::Reservation(const std::string& res) {

	}

	void Reservation::update(int day, int time) {
		arrivalDay = day;
		arrivalHour = time;
	}
}