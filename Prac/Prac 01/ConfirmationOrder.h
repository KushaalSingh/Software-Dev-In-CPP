#ifndef CONFIRMATION_ORDER_H
#define CONFIRMATION_ORDER_H
#include "Toy.h"

namespace seneca {

	class ConfirmationOrder {
		const Toy** m_toys;
		size_t m_count;

	public:
		ConfirmationOrder(const ConfirmationOrder* toys[], size_t count);
	};
}

#endif