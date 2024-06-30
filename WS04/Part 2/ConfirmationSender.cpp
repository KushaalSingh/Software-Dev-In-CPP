#include "ConfirmationSender.h"

namespace seneca {

	ConfirmationSender::ConfirmationSender() : m_reservations(nullptr), m_size(0) {};

	ConfirmationSender::~ConfirmationSender() {
		delete[] m_reservations;
	}

	ConfirmationSender& ConfirmationSender::operator+= (const Reservation& res) {
		for (size_t i = 0; i < m_size; i++) if (&res == m_reservations[i]) return *this;

		++m_size;
		const Reservation** temp = new Reservation*[m_size];
		for (size_t i = 0; i < m_size; i++) temp[i] = m_reservations[i];
		temp[m_size] = &res;
		delete[] m_reservations;
		m_reservations = temp;

		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator -= (const Reservation& res) {
		for (size_t i = 0; i < m_size; i++) {
			if (&res == m_reservations[i]) {
				for (size_t k = i; k < m_size; k++) m_reservations[k] = m_reservations[k + 1];
				--m_size;
				const Reservation** temp = new Reservation*[m_size];
				for (size_t x = 0; x < m_size; x++) temp[x] = m_reservations[i];
				delete[] m_reservations;
				m_reservations = temp;
				break;
			}
		}
		return *this;
	}

	std::ostream& operator << (std::ostream& out, const ConfirmationSender& src) {
		out << "--------------------------" << std::endl;
		out << "Confirmations to Send" << std::endl;
		out << "--------------------------" << std::endl;
		if (src.m_size) for (size_t i = 0; i < src.m_size; i++) out << *src.m_reservations[i];
		else out << "There are no confirmations to send!" << std::endl;
		out << "--------------------------" << std::endl;

		return out;
	}
}