// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
#include "spellChecker.h"
#include <algorithm>
#include <stdexcept>

namespace seneca {

    SpellChecker::SpellChecker(const char* filename) {
        std::ifstream file(filename);

        if (!file) throw "Bad file name!"; 

        std::string line;
        size_t index = 0;

        while (std::getline(file, line) && index < ARRAY_SIZE) {
            std::istringstream iss(line);
            std::string bad, good;

            if (!(iss >> bad >> good)) {
                throw "Invalid file format!";
            }

            m_badWords[index] = bad;
            m_goodWords[index] = good;
            ++index;
        }

        if (index < ARRAY_SIZE) {
            throw "Insufficient data in file!";
        }
    }

    void SpellChecker::operator()(std::string& text) {
        for (size_t i = 0; i < ARRAY_SIZE; ++i) {
            size_t pos = 0;


            while ((pos = text.find(m_badWords[i], pos)) != std::string::npos) {
                text.replace(pos, m_badWords[i].length(), m_goodWords[i]);
                ++m_replacements[i];
                pos += m_goodWords[i].length();
            }
        }
    }

    void SpellChecker::showStatistics(std::ostream& out) const {
        out << "Spellchecker Statistics\n";
        for (size_t i = 0; i < ARRAY_SIZE; ++i) {
            out << std::left << std::setw(15) << m_badWords[i] << ": "
                << m_replacements[i] << " replacements" << std::endl;
        }
    }
}
