#ifndef SENECA_TIMED_TASK_CPP
#define SENECA_TIMED_TASK_CPP

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <chrono>

namespace seneca {

	typedef std::string string;

	class TimedTask {
	private:
		int numRecords;
		std::chrono::steady_clock::time_point startPoint;
		std::chrono::steady_clock::time_point endPoint;
		Task task[10];

	public:
		TimedTask();
		void startClock();
		void stopClock();
		void addTask(const char* src);
		friend std::ostream& operator << (std::ostream& out, TimedTask src);
	};

	struct Task {
		string taskName;
		string unitOfTime;
		std::chrono::steady_clock::duration duration;
	};


}

#endif
