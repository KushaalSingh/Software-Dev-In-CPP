#ifndef SENECA_CONFIRMATION_SENDER_H
#define SENECA_CONFIRMATION_SENDER_H

#include "Reservation.h"

namespace seneca {

	class ConfirmationSender {
	private:
		const Reservation** m_reservations;
		size_t m_size;

	public:
		ConfirmationSender();
		~ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& src);
		ConfirmationSender& operator = (const ConfirmationSender& res);
		ConfirmationSender& operator += (const Reservation& res);
		ConfirmationSender& operator -= (const Reservation& res);

		friend std::ostream& operator << (std::ostream& out, const ConfirmationSender& src);
	};

}
#endif