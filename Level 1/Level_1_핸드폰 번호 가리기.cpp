/* 프로그래머스 - Level 1 핸드폰 번호 가리기 */

#include <string>

using namespace std;

string solution(string phone_number) {
	string answer = phone_number;

	for (int idx = 0; idx < phone_number.size() - 4; idx++)
		answer[idx] = '*';

	return answer;
}