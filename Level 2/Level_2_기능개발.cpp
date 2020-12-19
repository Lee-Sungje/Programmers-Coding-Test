/* 프로그래머스 - Level 2 기능개발 */

#include <queue>
#include <vector>

using namespace std;

constexpr int ZERO = 0;
constexpr int ONE = 1;
constexpr int COMPLETION = 100;

struct Development {
	Development() {}
	Development(int progress, int speed) : progress(progress), speed(speed) {}

	int progress;
	int speed;
};

queue<Development> scheduling(vector<int>& progresses, vector<int>& speeds) {
	queue<Development> schedule;
	for (int index = ZERO; index < progresses.size(); index++)
		schedule.push(Development(progresses[index], speeds[index]));

	return schedule;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	queue<Development> schedule = scheduling(progresses, speeds);

	vector<int> distribution;
	int days = ZERO;
	while (!schedule.empty()) {
		days += ONE;
		
		int completed_function = ZERO;
		Development front_function = schedule.front();
		while (COMPLETION <= front_function.progress + (front_function.speed * days)) {
			completed_function += ONE;
			schedule.pop();
			front_function = schedule.front();
		}

		if (completed_function != ZERO)
			distribution.push_back(completed_function);
	}

	return distribution;
}