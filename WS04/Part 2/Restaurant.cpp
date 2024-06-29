#include "Restaurant.h"


namespace seneca {

	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) : m_size(cnt) {
		m_reservations = new Reservation*[cnt];
		for (size_t i = 0; i < m_size; i++) m_reservations[i] = new Reservation(*reservations[i]);
	}

	Restaurant::~Restaurant() {
		for (size_t i = 0; i < m_size; i++) delete m_reservations[i];
		delete[] m_reservations;
	}

	size_t Restaurant::size() {
		return m_size;
	}
}