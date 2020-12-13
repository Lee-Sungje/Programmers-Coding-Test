/* 프로그래머스 - Level 1 콜라츠 추측 */

#include <string>
#include <vector>

using namespace std;

int solution(int num) {
	int count;
	long long n = num;

	for (count = 0; count < 500; count++) {
		if (n == 1)
			return count;
		n = n & 1 ? n * 3 + 1 : n / 2;
	}

	return -1;
}