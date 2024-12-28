#include "ShoppingCart.h"

namespace seneca {

	ShoppingCart::ShoppingCart(const std::string& name, int age, const Toy* toys[], size_t count) : m_toys(nullptr), m_count(count), m_name(name), m_age(age) {
		if (count > 0 && toys != nullptr) {
			m_toys = new Toy * [count];
			for (int i = 0; i < m_count; i++) m_toys[i] = new Toy(*toys[i]);
		}
	}

	std::ostream& operator << (std::ostream& os, ShoppingCart& sc) {
		static size_t CALL_CNT = 0;

		if (sc.m_toys == nullptr || sc.m_count > 0) {

		}
	}
}