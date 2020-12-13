/* 프로그래머스 - Level 1 자릿수 더하기 */

using namespace std;

int solution(int n) {
	int answer = 0;

	while (n) {
		answer += n % 10;
		n /= 10;
	}

	return answer;
}