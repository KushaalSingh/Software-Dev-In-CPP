// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#include "LineManager.h"

namespace seneca {

    LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) : m_cntCustomerOrder(0), m_firstStation(nullptr) {

        try {
            std::ifstream fs(file);
            std::string line = "";

            while (std::getline(fs, line)) {
                size_t pos = line.find('|');
                std::string currStation = line.substr(0, pos);
                std::string nextStation = (pos == std::string::npos) ? "" : line.substr(pos + 1);

                auto curr = std::find_if(stations.begin(), stations.end(), [&](Workstation* ws) { return ws->getItemName() == currStation; });

                if (curr != stations.end()) {
                    if (std::find(m_activeLine.begin(), m_activeLine.end(), *curr) == m_activeLine.end()) m_activeLine.push_back(*curr);

                    if (!nextStation.empty()) {
                        auto next = std::find_if(stations.begin(), stations.end(), [&](Workstation* ws) { return ws->getItemName() == nextStation; });
                        if (next != stations.end()) (*curr)->setNextStation(*next);
                    }

                }

                m_firstStation = *std::find_if(stations.begin(), stations.end(), [&](Workstation* ws) {
                    return std::none_of(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* active) {
                        return active->getNextStation() == ws;
                        });
                    });

                m_cntCustomerOrder = g_pending.size();
            }
        }

        catch (const std::exception& e) {
            std::cerr << "Error initializing LineManager: " << e.what() << std::endl;
            throw;
        }
    }

    void LineManager::reorderStations() {
        std::vector<Workstation*> orderedStations;
        Workstation* station = m_firstStation;
        while (station) {
            orderedStations.push_back(station);
            station = station->getNextStation();
        }
        m_activeLine = orderedStations;
    }

    bool LineManager::run(std::ostream& os) {
        static size_t currItr = 0;
        os << "Line Manager Iteration: " << ++currItr << std::endl;

        if (!g_pending.empty()) {
            *m_firstStation += std::move(g_pending.front());
            g_pending.pop_front();
        }

        for (auto& station : m_activeLine) station->fill(os);
        for (auto& station : m_activeLine) station->attemptToMoveOrder();

        return g_completed.size() + g_incomplete.size() == m_cntCustomerOrder;
    }

    void LineManager::display(std::ostream& os) const {
        for (const auto& station : m_activeLine) station->display(os);
    }
}