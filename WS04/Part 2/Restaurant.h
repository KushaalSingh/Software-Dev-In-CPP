#ifndef SENECA_RESTAURANT_H
#define SENECA_RESTAURANT_H

#include "Reservation.h"

namespace seneca {

	class Restaurant {
	private:
		Reservation** m_reservations;
		size_t m_size;

	public:
		Restaurant(const Reservation* reservations[], size_t cnt);
		~Restaurant();
	};

}
#endif