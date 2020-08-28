/* 프로그래머스 - 정수 내림차순으로 배치하기 */

#include <string>
#include <vector>
#include <algorithm>
//#include <cmath>

using namespace std;

long long solution(long long n) {
	long long answer = 0;
	string str = to_string(n);
	//vector<int> digit;

	//for (size_t i = 0; i < str.size(); i++)
	//	digit.push_back(str[i] - '0');

	sort(str.begin(), str.end(), greater<char>());

	//for (size_t i = 0; i < digit.size(); i++)
	//	answer += digit[i] * pow(10, i);
	answer = stoll(str);

	return answer;
}