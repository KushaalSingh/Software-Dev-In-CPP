#include "PreTriage.h"

namespace seneca {

	PreTriage::PreTriage(const char* file) : m_avgContaigenTime(15), m_avgTriageTime(5), m_dataFile(nullptr), m_numPatients(0) {
		for (int i = 0; i < MAX_PATIENTS; i++) m_patients[i] = nullptr;
		if (file) {
			U.allocStringCopy(m_dataFile, file);
			load();
		}
		else std::cerr << "ERROR: Bad File!!!" << std::endl;
	}

	PreTriage::~PreTriage() {
		save();
		for (int i = 0; i < m_numPatients; i++) delete m_patients[i];
		delete[] m_dataFile;
	}

	Time PreTriage::getWaitTime(const Patient& src) const {
		int matches = 0;
		for (int i = 0; i < m_numPatients; i++) if (*m_patients[i] == src) matches++;
		matches *= (src == 'C') ? m_avgContaigenTime : m_avgTriageTime;
		return Time(matches);
	}

	void PreTriage::setAverageWaitTime(const Patient& src) {
		char type = src.type();
		Time currTime;
		currTime.reset();
		Time ticketTime = src.time();
		Time& avgWaitTime = type == 'C' ? m_avgContaigenTime : m_avgTriageTime;
		int ticketNumber = src.number();
		avgWaitTime = ((currTime - ticketTime) + (avgWaitTime * (ticketNumber - 1))) / ticketNumber;
	}

	int PreTriage::indexOfFirstInLine(char type) {
		for (int i = 0; i < m_numPatients; i++) if (*m_patients[i] == type) return i;
		return -1;
	}

	void PreTriage::load() {
		Patient* patient{ nullptr };
		char type{};

		std::cout << "Loading data..." << std::endl;
		std::ifstream fin(m_dataFile);
		if (!fin.is_open()) {
			std::cerr << "No data or bad data file!" << std::endl << std::endl;
			return;
		}

		else {
			fin >> m_avgContaigenTime;
			fin.ignore(10000, ',');
			fin >> m_avgTriageTime;
			fin.ignore(10000, '\n');

			while (fin >> type) {
				fin.ignore(10000, ',');
				if (type == 'C') patient = new TestPatient();
				else patient = new TriagePatient();
				if (fin >> *patient) {
					if (m_numPatients < MAX_PATIENTS) {
						m_patients[m_numPatients++] = patient;
					}
					else {
						std::cerr << "Warning: number of records exceeded " << MAX_PATIENTS << std::endl;
						delete patient;
						break;
					}
				}
				else {
					delete patient;
					std::cerr << "Error: Bad Data!!!" << std::endl;
					break;
				}
			}
			fin.close();
			if (m_numPatients) std::cout << m_numPatients << " Records imported..." << std::endl << std::endl;
			else std::cout << "No data or bad data file!" << std::endl << std::endl;
		}
	}

	void PreTriage::save() {
		int cont = 0, tri = 0, i;
		std::cout << "Saving lineup..." << std::endl;
		std::ofstream fout(m_dataFile);
		fout << m_avgContaigenTime << "," << m_avgTriageTime << std::endl;
		for (i = 0; i < m_numPatients; i++) {
			fout << *m_patients[i] << std::endl;
			if (m_patients[i]->type() == 'C') cont++;
			else tri++;
		}
		std::cout << cont << " Contagion Tests and " << tri << " Triage records were saved!" << std::endl;
	}

	void PreTriage::Register() {
		if (m_numPatients == MAX_PATIENTS) {
			std::cout << "Line up full!" << std::endl;
			return;
		}

		int selection{ 0 };
		Patient* patient{ nullptr };
		Menu subMenu("Select Type of Registration:\n1- Contagion Test\n2- Triage", 1);
		subMenu.display();
		subMenu.read(selection);
		if (selection == 1) patient = new TestPatient();
		else if (selection == 2) patient = new TriagePatient();
		else if (selection == 0) return;
		
		patient->setArrivalTime();
		std::cout << "Please enter patient information: " << std::endl;
		std::cin >> *patient;
		std::cout << std::endl;
		std::cout << "******************************************" << std::endl;
		std::cout << *patient;
		std::cout << "Estimated Wait Time: " << getWaitTime(*patient) << std::endl;
		std::cout << "******************************************" << std::endl << std::endl;
		m_patients[m_numPatients++] = patient;
	}

	// Can't put it in module. Getting error LNK2019.
	template <typename type>
	void removeDynamicElement(type* array[], int index, int& size) {
		delete array[index];
		for (int j = index; j < size; j++) {
			array[j] = array[j + 1];
		}
		size--;
	}

	void PreTriage::admit() {
		int selection{ 0 };
		char type{};
		Menu subMenu("Select Type of Admittance:\n1- Contagion Test\n2- Triage", 1);
		subMenu.display();
		subMenu.read(selection);
		if (selection == 1) type = 'C';
		else if (selection == 2) type = 'T';
		else if (selection == 0) return;
		int index = type == 'C' ? indexOfFirstInLine('C') : indexOfFirstInLine('T');
		if (index == -1) {
			std::cerr << "Lineup is empty!" << std::endl;
			return;
		}
		Patient* patient = m_patients[index];
		std::cout << std::endl << "******************************************" << std::endl;
		std::cout << "Call time: [" << Time(U.getTime()) << "]" << std::endl;
		std::cout << "Calling at for " << *patient;
		std::cout << "******************************************" << std::endl << std::endl;
		setAverageWaitTime(*patient);
		
		// Can't access it from utils module via U. Getting error LNK2019.
		removeDynamicElement(m_patients, index, m_numPatients);
	}

	void PreTriage::lineup() const {
		int selection{ 0 };
		char type{};
		Menu subMenu("Select The Lineup:\n1- Contagion Test\n2- Triage", 1);
		subMenu.display();
		subMenu.read(selection);
		if (selection == 1) type = 'C';
		else if (selection == 2) type = 'T';
		else if (selection == 0) return;

		if (m_numPatients == 0) {
			std::cerr << "Lineup is empty!" << std::endl;
			return;
		}
		else {
			std::cout << "Row - Patient name                                          OHIP     Tk #  Time" << std::endl;
			std::cout << "-------------------------------------------------------------------------------" << std::endl;
			int row = 0;
			for (int i = 0; i < m_numPatients; i++) {
				if (*m_patients[i] == type) {
					row++;
					std::clog.width(3);
					std::clog.setf(std::ios::left);
					std::clog.fill(' ');
					std::clog << row;
					std::clog << " - " << *m_patients[i] << std::endl;
				}
			}
			std::cout << "-------------------------------------------------------------------------------" << std::endl;
		}
	}

	void PreTriage::run() {
		int selection{ 0 };
		int stst = 1;
		Menu mainMenu("General Healthcare Facility Pre-Triage Application\n1- Register\n2- Admit\n3- View Lineup");
		while (stst) {
			mainMenu.display();
			mainMenu.read(selection);
			if (selection == 1) Register();
			else if (selection == 2) admit();
			else if (selection == 3) lineup();
			else if (selection == 0) stst = 0;
		}
		return;
	}
}