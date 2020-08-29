/* 프로그래머스 - 하샤드 수 */

#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
	bool answer = true;
	int sum = 0;
	string digit = to_string(x);
	
	for (int idx = 0; idx < digit.size(); idx++)
		sum += digit[idx] - '0';

	answer = x % sum == 0 ? true : false;

	return answer;
}