#include "Collection.h"

namespace seneca {

	template <typename T, uint32_t C>
	T Collectoin<T, C>::m_smallestItem = T();

	template <typename T, uint32_t C>
	T Collectoin<T, C>::m_largestItem = T();

	template <typename T, uint32_t C>
	void Collectoin<T, C>::setSmallestItem(const T& src) {
		m_smallestItem = src;
	}

	template <typename T, uint32_t C>
	void Collectoin<T, C>::setLargestItem(const T& src) {
		m_largestItem = src;
	}

	template <typename T, uint32_t C>
	uint32_t Collectoin<T, C>::size() const {
		return m_size;
	}

	template <typename T, uint32_t C>
	uint32_t Collectoin<T, C>::capacity() const {
		return m_capacity;
	}

	template <typename T, uint32_t C>
	bool Collectoin<T, C>::operator+= (const T& src) {
		if (m_size >= C) return false;

		if (src < m_smallestItem) setSmallestItem(src);
		else if (src > m_largestItem) setLargestItem(src);
		
		m_data[m_size++] += src;
		return true;
	}
}