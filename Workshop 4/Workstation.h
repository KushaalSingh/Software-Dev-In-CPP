// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#ifndef SENECA_WORKSTATION_H
#define SENECA_WORKSTATION_H

#include "CustomerOrder.h"
#include <deque>

namespace seneca {

	extern std::deque<CustomerOrder> g_pending;
	extern std::deque<CustomerOrder> g_completed;
	extern std::deque<CustomerOrder> g_incomplete;

	class Workstation : public Station {
	private:
		std::deque<CustomerOrder> m_orders;
		Workstation* m_pNextStation{ nullptr };

	public:
		Workstation(const std::string& record);
		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station);
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator += (CustomerOrder&& newOrder);

		Workstation(const Workstation& src) = delete;
		Workstation& operator = (const Workstation& src) = delete;
		Workstation(Workstation&& src) = delete;
		Workstation& operator = (Workstation&& src) = delete;
	};
}
#endif 