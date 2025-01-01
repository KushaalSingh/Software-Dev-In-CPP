#include "ShoppingCart.h"

namespace seneca {

	ShoppingCart::ShoppingCart(const std::string& name, int age, const Toy* toys[], size_t count) : m_toys(nullptr), m_count(count), m_name(name), m_age(age) {
		if (count > 0 && toys != nullptr) {
			m_toys = new const Toy * [count];
			for (int i = 0; i < m_count; i++) m_toys[i] = new Toy(*toys[i]);
		}
		else m_count = 0;
	}

	ShoppingCart::~ShoppingCart() {
		for (int i = 0; i < m_count; i++) delete m_toys[i];
		delete[] m_toys;
	}

	std::ostream& operator << (std::ostream& os, ShoppingCart& sc) {
		static size_t CALL_CNT = 0;

		if (sc.m_toys == nullptr) {
			prln();
			std::cout << "Order " << ++CALL_CNT << ": This shopping cart is invalid." << std::endl;
			prln();
		}
		else if (sc.m_count < 1) {
			prln();
			std::cout << "Order " << ++CALL_CNT << ": Shopping for " << sc.m_name << " " << sc.m_age << " years old (" << sc.m_count << ") toys" << std::endl;
			prln();
			std::cout << "Empty shopping cart!" << std::endl;
			prln();
		}
		else {
			prln();
			std::cout << "Order " << ++CALL_CNT << ": Shopping for " << sc.m_name << " " << sc.m_age << " years old (" << sc.m_count << ") toys" << std::endl;
			prln();
			for (int i = 0; i < sc.m_count; i++) std::cout << sc.m_toys[i];
			prln();
		}
	}


	inline void prln() {
		std::cout << "--------------------------" << std::endl;
	}
}