/* 프로그래머스 - 최대공약수와 최소공배수 */

#include <string>
#include <vector>

using namespace std;

int gcd(int n, int m) {
	if (n % m != 0)
		return gcd(m, n % m);
	else
		return m;
}

vector<int> solution(int n, int m) {
	vector<int> answer;
	answer.push_back(n > m ? gcd(n, m) : gcd(m, n));
	answer.push_back((n * m) / answer[0]);

	return answer;
}