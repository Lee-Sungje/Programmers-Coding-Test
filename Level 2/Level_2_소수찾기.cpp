/* 프로그래머스 - Level 2 124 나라의 숫자 */

#include <algorithm>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<bool> primeNumbers;

void eratos(int n) {
	if (n <= 1) return;

	primeNumbers = vector<bool>(n + 1, true);
	primeNumbers[0] = primeNumbers[1] = false;
	for (int i = 2; i * i <= n; i++) {
		if (primeNumbers[i]) {
			for (int j = i * i; j <= n; j += i)
				primeNumbers[j] = false;
		}
	}
}

int solution(string numbers) {
	int answer = 0;
	set<int> combinedNumbers;
	
	sort(numbers.begin(), numbers.end(), greater<>());
	eratos(stoi(numbers));
	
	do {
		int number = stoi(numbers);
		while (number) {
			combinedNumbers.insert(number);
			number /= 10;
		}
	} while (prev_permutation(numbers.begin(), numbers.end()));

	for (int number : combinedNumbers) {
		if (primeNumbers[number])
			answer += 1;
	}

	return answer;
}