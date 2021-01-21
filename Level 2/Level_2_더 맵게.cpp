/* 프로그래머스 - Level 2 더 맵게 */

#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	bool is_exceed = false;
	priority_queue<int, vector<int>, greater<int>> min_heap(scoville.begin(), scoville.end());

	while (!is_exceed && 1 < min_heap.size()) {
		int first_scoville = min_heap.top(); min_heap.pop();
		int second_scoville = min_heap.top(); min_heap.pop();

		min_heap.push(first_scoville + (second_scoville * 2));
		answer += 1;

		if (K <= min_heap.top())
			is_exceed = true;
	}

	return is_exceed ? answer : -1;
}