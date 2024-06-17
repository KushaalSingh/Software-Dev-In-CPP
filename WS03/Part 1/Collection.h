#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include "Book.h"

namespace seneca {

	template <typename T, uint32_t C> 
	class Collectoin {
	private:
		T m_data[C];
		static T m_smallestItem;
		static T m_largestItem;
		uint32_t m_capacity;
		uint32_t m_size;

	protected:
		void setSmallestItem(const T& src);
		void setLargestItem(const T& src);

	public:
		uint32_t size() const;
		uint32_t capacity() const;
		bool operator+= (const T& src);
		std::ostream& print(const std::ostream& out);

		static T getSmallestItem();
		static T getLargestItem();
	};
}


#endif