#include "collection.h"
#include <iostream>
#include <iomanip>

namespace seneca {

    // Constructor
    Collection::Collection(const std::string& name) : m_name(name) {}

    // Destructor
    Collection::~Collection() {
        for (auto* item : m_items) {
            delete item; // Free dynamically allocated memory
        }
    }

    // Get the name of the collection
    const std::string& Collection::name() const {
        return m_name;
    }

    // Get the size of the collection
    size_t Collection::size() const {
        return m_items.size();
    }

    // Set the observer function
    void Collection::setObserver(void (*observer)(const Collection&, const MediaItem&)) {
        m_observer = observer;
    }

    // Add a new MediaItem to the collection
    Collection& Collection::operator+=(MediaItem* item) {
        auto it = std::find_if(m_items.begin(), m_items.end(), [item](const MediaItem* existingItem) {
            return existingItem->getTitle() == item->getTitle();
            });

        if (it == m_items.end()) { // If item is not already in the collection
            m_items.push_back(item);
            if (m_observer) {
                m_observer(*this, *item); // Notify the observer
            }
        }
        else {
            delete item; // Delete the duplicate item
        }

        return *this;
    }

    // Access item by index
    MediaItem* Collection::operator[](size_t idx) const {
        if (idx >= m_items.size()) {
            throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" +
                std::to_string(m_items.size()) + "] items.");
        }
        return m_items[idx];
    }

    // Access item by title
    MediaItem* Collection::operator[](const std::string& title) const {
        auto it = std::find_if(m_items.begin(), m_items.end(), [&title](const MediaItem* item) {
            return item->getTitle() == title;
            });

        return (it != m_items.end()) ? *it : nullptr;
    }

    // Remove quotes from titles and summaries
    void Collection::removeQuotes() {
        std::for_each(m_items.begin(), m_items.end(), [](MediaItem* item) {
            std::string title = item->getTitle();
        std::string summary = item->getSummary();

        if (!title.empty() && title.front() == '"' && title.back() == '"') {
            item->setTitle(title.substr(1, title.size() - 2));
        }
        if (!summary.empty() && summary.front() == '"' && summary.back() == '"') {
            item->setSummary(summary.substr(1, summary.size() - 2));
        }
            });
    }

    // Sort the collection based on a given field
    void Collection::sort(const std::string& field) {
        std::sort(m_items.begin(), m_items.end(), [&field](const MediaItem* a, const MediaItem* b) {
            if (field == "title") {
                return a->getTitle() < b->getTitle();
            }
            else if (field == "year") {
                return a->getYear() < b->getYear();
            }
        return false;
            });
    }

    // Overload the insertion operator
    std::ostream& operator<<(std::ostream& os, const Collection& collection) {
        for (const auto* item : collection.m_items) {
            os << *item; // Insert each MediaItem into the stream
        }
        return os;
    }

} // namespace seneca