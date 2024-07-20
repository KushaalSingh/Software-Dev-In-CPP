#ifndef SENECA_CUSTOMER_ORDER_H
#define SENECA_CUSTOMER_ORDER_H

#include "Station.h"

namespace seneca {

	struct Item {
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src);
	};

	class CustomerOrder {

	}
}

#endif
