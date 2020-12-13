/* 프로그래머스 - Level 1 x만큼 간격이 있는 n개의 숫자 */

#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
	vector<long long> answer;

	for (int interval = 1; interval <= n; interval++)
		answer.push_back(x * interval);

	return answer;
}