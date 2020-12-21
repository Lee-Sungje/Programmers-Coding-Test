/* 프로그래머스 - Level 2 멀쩡한 사각형 */

using namespace std;

int gcd(long long a, long long b) {
	return (a % b == 0) ? b : gcd(b, a % b);
}

long long solution(int w, int h) {
	long long lw = w, lh = h;
	long long answer = lw * lh - (lw + lh - gcd(lw, lh));

	return answer;
}

int main() {
	solution(8, 12);

	return 0;
}