#ifndef CONFIRMATION_ORDER_H
#define CONFIRMATION_ORDER_H
#include "Toy.h"

namespace seneca {

	class ConfirmationOrder {
		const Toy** m_toys;
		size_t count;

	public:
		ConfirmationOrder(const Toy& toy);
	};
}

#endif