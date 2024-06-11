#include "TimedTask.h"

namespace seneca {

	TimedTask::TimedTask() : numRecords(0) {}

	void TimedTask::startClock() {
		startPoint = std::chrono::steady_clock::now();
	}

	void TimedTask::stopClock() {
		endPoint = std::chrono::steady_clock::now();
	}

	void TimedTask::addTask(const char* taskName) {
		if (numRecords < 10) {
			tasks[numRecords].taskName = taskName;
			tasks[numRecords].unitOfTime = "nanoseconds";
			tasks[numRecords].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endPoint - startPoint);
			numRecords++;
		}
	}

	std::ostream& operator << (std::ostream& out, TimedTask src) {
		for (int i = 0; i < src.numRecords; i++) {
			out << "Execution Times:" << std::endl << "--------------------------" << std::endl;
			out << std::left << std::setw(21) << src.tasks[i].taskName << std::right 
				<< std::setw(13) << src.tasks[i].duration.count() << " " << src.tasks[i].unitOfTime << std::endl;
			out << "--------------------------" << std::endl;
		}
	}
}