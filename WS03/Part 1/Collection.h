#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include "Book.h"

namespace seneca {

	template <typename T, unsigned C> 
	class Collection {
	private:
		T m_data[C];
		static T m_smallestItem;
		static T m_largestItem;
		unsigned m_size;

	protected:
		void setSmallestItem(const T& src);
		void setLargestItem(const T& src);

	public:
		unsigned size() const;
		unsigned capacity() const;
		bool operator+= (const T& src);
		std::ostream& print(std::ostream& out) const;

		static T getSmallestItem();
		static T getLargestItem();
	};
}


#endif