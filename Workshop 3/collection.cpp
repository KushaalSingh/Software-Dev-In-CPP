// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
#include "collection.h"
#include <iostream>
#include <iomanip>

namespace seneca {

    Collection::Collection(const std::string& name) : m_name(name) {}

    Collection::~Collection() {
        for (auto* item : m_items) delete item;
    }

    const std::string& Collection::name() const {
        return m_name;
    }

    size_t Collection::size() const {
        return m_items.size();
    }

    void Collection::setObserver(void (*observer)(const Collection&, const MediaItem&)) {
        m_observer = observer;
    }

    Collection& Collection::operator+=(MediaItem* item) {
        auto it = std::find_if(m_items.begin(), m_items.end(), [item](const MediaItem* existingItem) {
            return existingItem->getTitle() == item->getTitle();
        });

        if (it == m_items.end()) {
            m_items.push_back(item);
            if (m_observer) m_observer(*this, *item);
        }
        else delete item;

        return *this;
    }

    MediaItem* Collection::operator[](size_t idx) const {
        if (idx >= m_items.size()) {
            throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" +
                std::to_string(m_items.size()) + "] items.");
        }
        return m_items[idx];
    }

    MediaItem* Collection::operator[](const std::string& title) const {
        auto it = std::find_if(m_items.begin(), m_items.end(), [&title](const MediaItem* item) {
            return item->getTitle() == title;
        });
        return (it != m_items.end()) ? *it : nullptr;
    }

    void Collection::removeQuotes() {
        std::for_each(m_items.begin(), m_items.end(), [](MediaItem* item) {
            std::string title = item->getTitle();
            std::string summary = item->getSummary();
            if (!title.empty() && title.front() == '"') title.erase(0, 1);
            if (!title.empty() && title.back() == '"') title.pop_back();
            item->setTitle(title);
            if (!summary.empty() && summary.front() == '"') summary.erase(0, 1);
            if (!summary.empty() && summary.back() == '"') summary.pop_back();
            item->setSummary(summary);
        });
    }

    void Collection::sort(const std::string& field) {
        std::sort(m_items.begin(), m_items.end(), [&field](const MediaItem* a, const MediaItem* b) {
            if (field == "title") return a->getTitle() < b->getTitle();
            else if (field == "year") return a->getYear() < b->getYear();
            return false;
        });
    }

    std::ostream& operator<<(std::ostream& os, const Collection& collection) {
        for (const auto* item : collection.m_items) os << *item;
        return os;
    }
}