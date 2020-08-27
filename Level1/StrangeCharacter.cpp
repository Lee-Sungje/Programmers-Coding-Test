/* 프로그래머스 - 이상한 문자 만들기 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	vector<string> word;
	size_t previous = 0, current;

	current = s.find(' ');
	while (current != string::npos) {
		word.push_back(s.substr(previous, current - previous));

		previous = current + 1;
		current = s.find(' ', previous);
	}
	word.push_back(s.substr(previous, current - previous));

	for (size_t i = 0; i < word.size(); i++) {
		for (size_t j = 0; j < word.at(i).size(); j++) {
			if (j % 2 == 0)
				word.at(i).at(j) = toupper(word.at(i).at(j));
			else if (j % 2 == 1)
				word.at(i).at(j) = tolower(word.at(i).at(j));
		}
	}

	for (size_t i = 0; i < word.size() - 1; i++) {
		answer.append(word.at(i) + " ");
	}
	answer.append(word.back());

	return answer;
}