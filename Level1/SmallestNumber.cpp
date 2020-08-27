/* 제일 작은 수 제거하기 */

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
	vector<int> answer;
	int min = arr[0];
	int idx = 0;

	for (int i = 1; i < arr.size(); i++) {
		if (min >= arr[i]) {
			min = arr[i];
			idx = i;
		}
	}
	
	arr.erase(arr.begin() + idx);
	if (idx)
		answer = arr;
	else
		answer = { -1 };

	return answer;
}