#ifndef SENECA_ORDERED_COLLECTION
#define SENECA_ORDERED_COLLECTION

#include "Collection.h"

namespace seneca {

	template <typename T>
	class OrderedCollection : public Collection<T, 72> {
	public:
		bool operator+=(const T& item);
		void print(std::ostream& out) const;
	};

	template <typename T>
	bool OrderedCollection<T>::operator+=(const T& item) {
		auto size = Collection<T, 72>::size();
		if (size >= Collection<T, 72>::capacity()) return false;

		uint32_t index = 0;
		while (index < size && Collection<T, 72>::operator[](index) < item) ++index;

		if (size) for (uint32_t i = size; i > index; i--) Collection<T, 72>::setElement(i, i - 1);
		
		Collection<T, 72>::setElement(index, item);
		Collection<T, 72>::incrSize();
		Collection<T, 72>::setSmallestItem(item);
		Collection<T, 72>::setLargestItem(item);

		return true;
	}

	template <typename T>
	void OrderedCollection<T>::print(std::ostream& out) const {
		std::cout << std::fixed << std::setprecision(1);
		Collection<T, 72>::print(out);
	}

	template<>
	void OrderedCollection<Book>::print(std::ostream& out) const {
		std::cout << std::fixed << std::setprecision(1);
		Collection<Book, 72>::print(out);
	}
}

#endif