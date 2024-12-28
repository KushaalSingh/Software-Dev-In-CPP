#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H
#include "Toy.h"
#include <vector>

namespace seneca {

	class ShoppingCart {
		const Toy** m_toys;
		size_t m_count;
		std::string m_name;
		int m_age;

		//std::vector<Toy> toys;

	public:
		ShoppingCart(const std::string& name, int age, const Toy* toys[], size_t count);

		friend std::ostream& operator << (std::ostream& os, ShoppingCart& sc);
	};

}


#endif