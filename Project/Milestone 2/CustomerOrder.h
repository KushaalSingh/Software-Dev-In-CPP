#ifndef SENECA_CUSTOMER_ORDER_H
#define SENECA_CUSTOMER_ORDER_H

#include "Station.h"

namespace seneca {

	struct Item {
		std::string m_itemName;
		size_t m_serialNumber { 0 };
		bool m_isFilled { false };

		Item(const std::string& src);
	};

	class CustomerOrder {
	private:
		std::string m_name;
		std::string m_product;
		size_t m_cntItem;
		Item** m_lstItem;

		static size_t m_widthField;

	public:
		CustomerOrder();
		CustomerOrder(const std::string line);
		CustomerOrder(CustomerOrder&& src) noexcept;
		~CustomerOrder();
		CustomerOrder& operator = (CustomerOrder&& src) noexcept;
		bool isOrderFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
		CustomerOrder(const CustomerOrder& src);
		CustomerOrder& operator = (const CustomerOrder& src) = delete;
	};
}

#endif
