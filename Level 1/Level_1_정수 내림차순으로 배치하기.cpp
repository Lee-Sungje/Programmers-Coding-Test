/* 프로그래머스 - Level 1 정수 내림차순으로 배치하기 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
	long long answer = 0;
	string str = to_string(n);

	sort(str.begin(), str.end(), greater<char>());
	answer = stoll(str);

	return answer;
}