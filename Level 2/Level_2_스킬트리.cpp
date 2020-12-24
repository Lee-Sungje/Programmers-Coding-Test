/* 프로그래머스 - Level 2 스킬트리 */

#include <string>
#include <vector>

using namespace std;

constexpr int MINUS_ONE = -1;
constexpr int SKILL_LENGTH = 26;

int solution(string skill, vector<string> skill_trees) {
	vector<int> skill_order(SKILL_LENGTH, MINUS_ONE);
	for (int order = 0; order < skill.length(); order++)
		skill_order[skill[order] - 'A'] = order;

	int answer = 0;
	for (string skill_tree : skill_trees) {
		bool isRight = true;
		int order = 0;

		for (int i = 0; i < skill_tree.length() && isRight; i++) {
			char currnet_skill = skill_tree[i];

			if (skill_order[currnet_skill - 'A'] == MINUS_ONE)
				continue;
			else if (skill_order[currnet_skill - 'A'] == order)
				order += 1;
			else
				isRight = false;
		}

		answer += isRight ? 1 : 0;
	}

	return answer;
}