#include "Workstation.h"

namespace seneca {

	std::deque<CustomerOrder> g_pending;
	std::deque<CustomerOrder> g_completed;
	std::deque<CustomerOrder> g_incomplete;

	Workstation::Workstation(const std::string& record) : Station(record), m_pNextStation(nullptr) {}

	void Workstation::fill(std::ostream& os) {
		if (!m_orders.empty()) m_orders.front().fillItem(*this, os);
	}

	bool Workstation::attemptToMoveOrder() {
		if (m_orders.empty()) return false;

		if (m_orders.front().isItemFilled(getItemName()) || !getQuantity()) {

			if (m_pNextStation) m_pNextStation->m_orders.push_back(std::move(m_orders.front()));

			else {
				if (m_orders.front().isOrderFilled()) g_completed.push_back(std::move(m_orders.front()));
				else g_incomplete.push_back(std::move(m_orders.front()));
			}
			m_orders.pop_front();
			return true;
		}
		
		return false;
	}
}