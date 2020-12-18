/* 프로그래머스 - Level 2 프린터 */

#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> P;

queue<P> load(vector<int> priorities) {
	queue<P> spool;

	for (int location = 0; location < priorities.size(); location++)
		spool.push({ location, priorities[location] });

	return spool;
}

int solution(vector<int> priorities, int location) {
	queue<P> spool;
	spool = load(priorities);
	sort(priorities.begin(), priorities.end());

	int answer = 0;
	while (!spool.empty()) {
		P document = spool.front();
		spool.pop();

		if (document.second == priorities.back()) {
			answer += 1;
			priorities.pop_back();
			if (document.first == location)
				break;
		} else {
			spool.push(document);
		}
	}

	return answer;
}