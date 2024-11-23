// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include <string>
#include <vector>
#include <functional>
#include <stdexcept>
#include <algorithm>
#include "mediaItem.h"

namespace seneca {

    class Collection {
        std::string m_name;
        std::vector<MediaItem*> m_items;
        void (*m_observer)(const Collection&, const MediaItem&) = nullptr;

    public:
        
        explicit Collection(const std::string& name);
        ~Collection();
        Collection(const Collection&) = delete;
        Collection& operator=(const Collection&) = delete;
        Collection(Collection&&) = delete;
        Collection& operator=(Collection&&) = delete;
        const std::string& name() const;
        size_t size() const;
        void setObserver(void (*observer)(const Collection&, const MediaItem&));
        Collection& operator+=(MediaItem* item);
        MediaItem* operator[](size_t idx) const;
        MediaItem* operator[](const std::string& title) const;
        void removeQuotes();
        void sort(const std::string& field);
        friend std::ostream& operator<<(std::ostream& os, const Collection& collection);
    };
} 
#endif