#ifndef SENECA_ORDERED_COLLECTION
#define SENECA_ORDERED_COLLECTION

#include "Collection.h"

namespace seneca {

	template <typename T>
	class OrderedCollection : public Collection<T, 72> {
	public:
		bool operator+=(const T& item);
	};

	template <typename T>
	bool OrderedCollection<T>::operator+=(const T& item) {
		uint32_t size = Collection<T, 72>::size();
		if (size >= Collection<T, 72>::capacity()) return false;

		uint32_t index = 0;
		while (index < size && Collection<T, 72>::operator[](index) < item) ++index;

		for (uint32_t i = size; i > size; i--) {
			Collection<T, 72>::operator[](i) = Collection<T, 72>::operator[](i - 1);
		}

		Collection<T, 72>::operator[](index) = item;
		Collection<T, 72>::incrSize();

		Collection<T, 72>::setSmallestItem(item);
		Collection<T, 72>::setLargestItem(item);

		return true;
	}
}


#endif