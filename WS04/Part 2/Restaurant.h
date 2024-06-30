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
		Restaurant(Restaurant&& src) noexcept;
		Restaurant& operator = (Restaurant&& src) noexcept;
		~Restaurant();
		size_t size();

		friend std::ostream& operator << (std::ostream& out, const Restaurant& src);
	};

}
#endif