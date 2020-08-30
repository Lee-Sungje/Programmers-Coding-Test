/* 프로그래머스 - [2019 카카오 개발자 겨울 인턴십]크레인 인형뽑기 게임 */

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> basket;
	
	for (int idx1 = 0; idx1 < moves.size(); idx1++) {
		for (int idx2 = 0; idx2 < board.size(); idx2++) {
			int *current = &board[idx2][moves[idx1] - 1];
			if (*current) {
				if (!basket.empty() && basket.top() == *current) {
					answer += 2;
					basket.pop();
				} else {
					basket.push(*current);
				}
				*current = 0;

				break;
			}
		}
	}

	return answer;
}