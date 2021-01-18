/* 프로그래머스 - Level 2 가장 큰 수 */

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

constexpr int kNumberSystem = 10;
constexpr int kExtensionSize = 4;
constexpr int kNine = 9;
constexpr int kOne = 1;
constexpr int kZero = 0;

pair<string, int> ExtensionStringNumber(int number) {
	string string_number = "";
	for (int i = 0; i < kExtensionSize; i++) {
		string_number += to_string(number);
	}

	return make_pair(string_number.substr(kZero, kExtensionSize),
		string_number.length() / kExtensionSize);
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<vector<pair<string, int>>> string_numbers(kNumberSystem);

	for (int number : numbers) {
		auto number_info = ExtensionStringNumber(number);
		string_numbers[number_info.first.front() - '0'].push_back(number_info);
	}

	for (int index = kNine; index >= kZero; index--) {
		sort(string_numbers[index].begin(), string_numbers[index].end());
		while (!string_numbers[index].empty()) {
			auto number_info = string_numbers[index].back();
			string_numbers[index].pop_back();

			answer += number_info.first.substr(kZero, number_info.second);
		}
	}

	return answer.front() == '0' ? "0" : answer;
}