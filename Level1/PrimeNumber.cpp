/* 프로그래머스 - 소수 찾기 */

#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
	vector<bool> prime(n + 1);

	prime[0] = prime[1] = true;
	for (int i = 2; i * i <= n; i++)
		if (!prime[i])
			for (int j = i * i; j <= n; j += i)
				prime[j] = true;
	
	return count(prime.begin(), prime.end(), false);
}