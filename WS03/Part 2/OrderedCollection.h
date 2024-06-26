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
		if (Collection<T, 72>::size() >= 72) return false;

		for (uint32_t i = 0; i < Collection<T, 72>::size(); i++) {
			if (Collection<T, 72>::[i])
		}

		return true;
	}
}


#endif