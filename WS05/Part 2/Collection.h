#ifndef COLLECTION_H
#define COLLECTION_H

#include "Book.h"

namespace seneca {
	
	template <typename T>
	class Collection {
	private:
		string m_collectionName;
		T* m_items;
		size_t m_size;
		void (*m_observer)(const Collection<T>&, const T&);

	public:
		Collection(const Collection&) = delete;
		Collection& operator = (const Collection&) = delete;

		Collection() : m_collectionName(""), m_items(nullptr), m_size(0), m_observer(nullptr) {};

		Collection(const std::string& name) : m_collectionName(name), m_items(nullptr), m_size(0), m_observer(nullptr) {}
		
		~Collection() {
			delete[] m_items;
		}

		const std::string& name() const {
			return m_collectionName;
		}

		size_t size() const {
			return m_size;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			m_observer = observer;
		}

		Collection<T>& operator+=(const T& item) {
			for (size_t i = 0; i < m_size; i++) if (m_items[i].title() == item.title()) return *this;

			T* temp = new T[m_size + 1];
			for (size_t i = 0; i < m_size; i++) temp[i] = m_items[i];
			temp[m_size++] = item;
			delete[] m_items;
			m_items = temp;

			if (m_observer) m_observer(*this, item);
			return *this;
		}

		T& operator[](size_t idx) const {
			if (idx < m_size) return m_items[idx];
			else throw std::out_of_range("Bad index " + std::to_string(idx) + " Collection has " + std::to_string(m_size) + " items.");
		}

		T* operator[](const std::string& title) const {
			for (size_t i = 0; i < m_size; i++) if (m_items[i].title() == title) return &m_items[i];
			return nullptr;
		}

		friend std::ostream& operator << (std::ostream& out, Collection<T>& src) {
			for (size_t i = 0; i < src.m_size; i++) out << src.m_items[i];
			return out;
		}
	};
}

#endif