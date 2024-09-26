// Name: Kushaal Singh
// Seneca Student ID: 115320228
// Seneca email: kna28@myseneca.ca
// Date of completion: 5/8/2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SENECA_LINEMANAGER_H
#define SENECA_LINEMANAGER_H

#include "Workstation.h"
#include <vector>
#include <fstream>

namespace seneca {
	
	class LineManager {
	private:
		std::vector<Workstation*> m_activeLine;
		size_t m_cntCustomerOrder;
		Workstation* m_firstStation;

	public:
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void reorderStations();
		bool run(std::ostream& os);
		void display(std::ostream& os) const;
	};
}

#endif 