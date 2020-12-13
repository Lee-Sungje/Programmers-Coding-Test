/* 프로그래머스 - Level 2 124 나라의 숫자 */

#include <string>
#include <vector>

using namespace std;

constexpr int ZERO = 0;
constexpr int ONE = 1;
constexpr int NOTATION = 3;
constexpr char number[NOTATION] = { '4', '1', '2' };

string solution(int n) {
	string answer = "";

	while (n != ZERO) {
		answer.insert(ZERO, ONE, number[n % NOTATION]);
		if (n % NOTATION == ZERO)
			n = n / NOTATION - ONE;
		else
			n = n / NOTATION;
	}
	return answer;
}