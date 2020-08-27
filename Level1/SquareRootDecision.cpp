/* 정수 제곱근 판별 */

#include <string>
#include <vector>

#define sqr(x) ((x) * (x))

using namespace std;

long long solution(long long n) {
	long long x = 0;
	
	do {
		x++;
		if (sqr(x) == n)
			return sqr(x + 1);
	} while (sqr(x) < n);

	return -1;
}