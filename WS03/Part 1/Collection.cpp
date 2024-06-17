#include "Collection.h"

namespace seneca {

	template <typename T, unsigned C>
	T Collection<T, C>::m_smallestItem = T();

	template <typename T, unsigned C>
	T Collection<T, C>::m_largestItem = T();

	template <typename T, unsigned C>
	void Collection<T, C>::setSmallestItem(const T& src) {
		m_smallestItem = src;
	}

	template <typename T, unsigned C>
	void Collection<T, C>::setLargestItem(const T& src) {
		m_largestItem = src;
	}

	template <typename T, unsigned C>
	unsigned Collection<T, C>::size() const {
		return m_size;
	}

	template <typename T, unsigned C>
	unsigned Collection<T, C>::capacity() const {
		return C;
	}

	template <typename T, unsigned C>
	bool Collection<T, C>::operator+= (const T& src) {
		if (m_size >= C) return false;

		if (src < m_smallestItem) setSmallestItem(src);
		else if (src > m_largestItem) setLargestItem(src);
		
		m_data[m_size++] += src;
		return true;
	}

	template <typename T, unsigned C>
	std::ostream& Collection<T, C>::print(std::ostream& out) const {
		std::cout << " <<<>>> THIS IS WORKING <<<>>>";
		return out;
	}

	template <typename T, unsigned C>
	T Collection<T, C>::getSmallestItem() {
		return m_smallestItem;
	}

	template <typename T, unsigned C>
	T Collection<T, C>::getLargestItem() {
		return m_largestItem;
	}

	template <>
	Book Collection<Book, 10>::m_smallestItem = Book("", 1, 10000);

	template<>
	Book Collection<Book, 10>::m_largestItem = Book("", 10000, 1);
}