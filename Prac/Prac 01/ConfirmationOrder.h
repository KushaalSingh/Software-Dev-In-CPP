#ifndef CONFIRMATION_ORDER_H
#define CONFIRMATION_ORDER_H
#include "Toy.h"

namespace seneca {

	class ConfirmationOrder {
		const Toy** m_toys;
		size_t m_count;

		bool valid(bool selfcheck, const ConfirmationOrder* src);
		bool findToy(const Toy* toy);
	public:
		ConfirmationOrder();
		ConfirmationOrder(const Toy* toys[], size_t count);
		ConfirmationOrder(const ConfirmationOrder& src);
		ConfirmationOrder(ConfirmationOrder&& src) noexcept;
		~ConfirmationOrder();
		ConfirmationOrder& operator = (const ConfirmationOrder& src);
		ConfirmationOrder& operator = (ConfirmationOrder&& src) noexcept;
		ConfirmationOrder& operator += (const Toy& toy);
		ConfirmationOrder& operator -= (const Toy& toy);
	};
}

#endif