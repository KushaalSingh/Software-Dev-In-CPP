#ifndef CONFIRMATION_ORDER_H
#define CONFIRMATION_ORDER_H
#include "Toy.h"

namespace seneca {

	class ConfirmationOrder {
		const Toy** m_toys;
		size_t m_count;

	public:
		ConfirmationOrder(const Toy* toys[], size_t count);
		ConfirmationOrder(const ConfirmationOrder& src);
		ConfirmationOrder(ConfirmationOrder&& src) noexcept;
		~ConfirmationOrder();
	};
}

#endif