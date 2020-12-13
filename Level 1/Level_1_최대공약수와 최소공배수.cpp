/* 프로그래머스 - Level 1 최대공약수와 최소공배수 */

#include <string>
#include <vector>

using namespace std;

int gcd(int n, int m) {
	return (n % m == 0) ? m : gcd(m, n % m);
}

vector<int> solution(int n, int m) {
	vector<int> answer;
	answer.push_back(gcd(n, m));
	answer.push_back((n * m) / answer[0]);

	return answer;
}