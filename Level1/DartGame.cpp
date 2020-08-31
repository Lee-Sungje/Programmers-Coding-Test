/* 프로그래머스 - [1차] 다트 게임 */

#include <string>
#include <regex>
#include <vector>

#define SINGLE(x) (x)
#define DOUBLE(x) ((x)*(x))
#define TRIPLE(x) ((x)*(x)*(x))

using namespace std;

int ScoreCalculate(int score, string bonus, string option) {
	score = bonus == "S" ? SINGLE(score) : bonus == "D" ? DOUBLE(score) : TRIPLE(score);

	int multiple = 1;

	if (option == "*")
		multiple = 2;
	else if (option == "#")
		multiple = -1;

	return score * multiple;
}

int solution(string dartResult) {
	const int kScoreIndex = 1;
	const int kBonusIndex = 2;
	const int kOptionIndex = 3;
	const int chance = 3;
	
	int total = 0;
	vector<int> score(chance);
	regex pattern("(\\d{1,2})([SDT])([*#]?)");
	smatch match;

	for (size_t index = 0; index < chance; index++) {
		regex_search(dartResult, match, pattern);
		
		score[index] = ScoreCalculate(stoi(match[kScoreIndex].str()), match[kBonusIndex].str(), match[kOptionIndex].str());
		if (!(index - 1 < 0) && match[kOptionIndex].str() == "*")
			score[index - 1] *= 2;
		dartResult = match.suffix();
	}

	for_each(score.begin(), score.end(), [&total](int score) { total += score; });

	return total;
}