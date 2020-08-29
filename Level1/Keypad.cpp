/* 프로그래머스 - [카카오 인턴] 키패드 누르기 */

#include <string>
#include <vector>
#include <map>

#define ABS(x) (((x) < 0) ? -(x) : (x))

using namespace std;

typedef struct {
	int x;
	int y;
} Point;

Point make_point(int x, int y) {
	Point p;
	p.x = x;
	p.y = y;

	return p;
}

map<int, Point> create_keypad() {
	map<int, Point> keys;

	keys[0] = make_point(3, 1);
	keys[1] = make_point(0, 0);
	keys[2] = make_point(0, 1);
	keys[3] = make_point(0, 2);
	keys[4] = make_point(1, 0);
	keys[5] = make_point(1, 1);
	keys[6] = make_point(1, 2);
	keys[7] = make_point(2, 0);
	keys[8] = make_point(2, 1);
	keys[9] = make_point(2, 2);

	return keys;
}

int cost_calc(Point current, Point next) {
	int cost = ABS(current.x - next.x) + ABS(current.y - next.y);

	return cost;
}

string solution(vector<int> numbers, string hand) {
	string answer = "";
	map<int, Point> keypad = create_keypad();
	Point curr_l = make_point(3, 0);
	Point curr_r = make_point(3, 2);

	for (int idx = 0; idx < numbers.size(); idx++) {
		if (numbers[idx] % 3 == 1) {
			curr_l = keypad[numbers[idx]];
			answer.push_back('L');
		} else if (numbers[idx] % 3 == 0 && numbers[idx] != 0) {
			curr_r = keypad[numbers[idx]];
			answer.push_back('R');
		} else {
			int cost_l = cost_calc(curr_l, keypad[numbers[idx]]);
			int cost_r = cost_calc(curr_r, keypad[numbers[idx]]);

			if (cost_l < cost_r) {
				curr_l = keypad[numbers[idx]];
				answer.push_back('L');
			} else if (cost_l > cost_r) {
				curr_r = keypad[numbers[idx]];
				answer.push_back('R');
			} else {
				if (!hand.compare("left")) {
					curr_l = keypad[numbers[idx]];
					answer.push_back('L');
				} else {
					curr_r = keypad[numbers[idx]];
					answer.push_back('R');
				}
			}
		}
	}

	return answer;
}