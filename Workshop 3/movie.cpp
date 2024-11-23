#include "movie.h"
#include <sstream>
#include <iomanip>
#include <algorithm>

namespace seneca {

    Movie::Movie(const std::string& title, unsigned short year, const std::string& summary)
    : MediaItem(title, summary, year) {}

    void Movie::display(std::ostream& out) const {
        if (g_settings.m_tableView) {
            out << "M | ";
            out << std::left << std::setfill('.');
            out << std::setw(50) << this->getTitle() << " | ";
            out << std::right << std::setfill(' ');
            out << std::setw(9) << this->getYear() << " | ";
            out << std::left;
            if (g_settings.m_maxSummaryWidth > -1) {
                if (static_cast<short>(this->getSummary().size()) <= g_settings.m_maxSummaryWidth) out << this->getSummary();
                else out << this->getSummary().substr(0, g_settings.m_maxSummaryWidth - 3) << "...";
            }
            else out << this->getSummary();
            out << std::endl;
        }
        else {
            size_t pos = 0;
            out << this->getTitle() << " [" << this->getYear() << "]\n";
            out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << "" << '\n';
            while (pos < this->getSummary().size()) {
                out << "    " << this->getSummary().substr(pos, g_settings.m_maxSummaryWidth) << '\n';
                pos += g_settings.m_maxSummaryWidth;
            }
            out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << "" << std::setfill(' ') << '\n';
        }
    }

    Movie* Movie::createItem(const std::string& strMovie) {
        if (strMovie.empty() || strMovie[0] == '#') {
            throw "Not a valid movie.";
        }

        std::stringstream ss(strMovie);
        std::string title, yearStr, summary;

        std::getline(ss, title, ',');
        std::getline(ss, yearStr, ',');
        std::getline(ss, summary);

        auto trim = [](std::string& str) {
            str.erase(0, str.find_first_not_of(" \t\r\n"));
            str.erase(str.find_last_not_of(" \t\r\n") + 1);
        };

        trim(title);
        trim(yearStr);
        trim(summary);

        unsigned short year = static_cast<unsigned short>(std::stoi(yearStr));

        return new Movie(title, year, summary);
    }

}
