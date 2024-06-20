#ifndef COLLECTION_H
#define COLLECTION_H

#include <iostream>
#include <algorithm>
#include <string>
#include "Book.h"

namespace seneca {

    template <typename T, unsigned C>
    class Collection {
    private:
        T m_items[C];
        unsigned m_size{};
        static T m_smallestItem;
        static T m_largestItem;

    protected:
        void setSmallestItem(const T& item);
        void setLargestItem(const T& item);

    public:
        Collection();

        unsigned size() const;
        unsigned capacity() const;
        bool operator+=(const T& item);
        void print(std::ostream& os) const;

        
        static T getSmallestItem();
        static T getLargestItem();

        T operator[](unsigned index) const;
        void incrSize();
    };

    // Constructor
    template <typename T, unsigned C>
    Collection<T, C>::Collection() : m_size(0) {}

    // Protected member functions
    template <typename T, unsigned C>
    void Collection<T, C>::setSmallestItem(const T& item) {
        if (item < m_smallestItem) {
            m_smallestItem = item;
        }
    }

    template <typename T, unsigned C>
    void Collection<T, C>::setLargestItem(const T& item) {
        if (item > m_largestItem) {
            m_largestItem = item;
        }
    }

    // Public member functions
    template <typename T, unsigned C>
    unsigned Collection<T, C>::size() const {
        return m_size;
    }

    template <typename T, unsigned C>
    unsigned Collection<T, C>::capacity() const {
        return C;
    }

    template <typename T, unsigned C>
    bool Collection<T, C>::operator+=(const T& item) {
        if (m_size >= C) {
            return false;
        }
        setSmallestItem(item);
        setLargestItem(item);
        m_items[m_size++] = item;
        return true;
    }

    template <typename T, unsigned C>
    void Collection<T, C>::print(std::ostream& os) const {
        os << "[";
        for (unsigned i = 0; i < m_size; i++) {
            if ((i != m_size) && (i != 0)) os << ",";
            os << m_items[i];
        }
        os << "]" << std::endl;
    }

    
    template <typename T, unsigned C>
    T Collection<T, C>::getSmallestItem() {
        return m_smallestItem;
    }

    template <typename T, unsigned C>
    T Collection<T, C>::getLargestItem() {
        return m_largestItem;
    }

    template <typename T, unsigned C>
    T Collection<T, C>::operator[](unsigned index) const {
        return m_items[index];
    }

    template <typename T, unsigned C>
    void Collection<T, C>::incrSize() {
        ++m_size;
    }

    template <>
    Book Collection<Book, 10>::m_smallestItem = Book("", 1, 10000);

    template <>
    Book Collection<Book, 10>::m_largestItem = Book("", 10000, 1);

    template<>
    Book Collection<Book, 72>::m_smallestItem = Book("", 1, 10000);

    template<>
    Book Collection<Book, 72>::m_largestItem = Book("", 10000, 1);

    template <>
    void Collection<Book, 10>::print(std::ostream& os) const {
        os << "[";
        for (unsigned i = 0; i < m_size; i++) {
            if ((i != m_size) && (i != 0)) os << ",";
            os << m_items[i];
        }
        os << "]" << std::endl;
    }

    template <typename T, unsigned C>
    T Collection<T, C>::m_smallestItem = 9999;

    template <typename T, unsigned C>
    T Collection<T, C>::m_largestItem = -9999;

    template <>
    double Collection<double, 10>::getLargestItem() {
        std::cout << std::fixed << std::setprecision(1);
        return m_largestItem;
    }

    template <>
    double Collection<double, 10>::getSmallestItem() {
        std::cout << std::fixed << std::setprecision(1);
        return m_smallestItem;
    }
} 

#endif 