/* 프로그래머스 - 자연수 뒤집어 배열로 만들기 */

#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
	vector<int> answer;
	string str = to_string(n);

	//for (int i = 0; i < str.size(); i++)
	//	answer.insert(answer.begin(), str[i] - '0');
	
	for (int i = str.size() - 1; i >= 0; i--)
		answer.push_back(str[i] - '0');

	return answer;
}