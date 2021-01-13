/* 프로그래머스 - Level 2 주식가격 */

#include <stack>
#include <vector>

using namespace std;

struct Stock {
	int timing;
	int price;

	Stock(int timing, int price) : timing(timing), price(price) {}
};

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size());
	stack<Stock> stack;
	
	for (int time = 0; time < prices.size(); time++) {
		while (!stack.empty() && prices[time] < stack.top().price) {
			Stock stock = stack.top();
			stack.pop();
			answer[stock.timing] = time - stock.timing;
		}
		stack.push({ time, prices[time] });
	}

	int length = prices.size() - 1;
	while (!stack.empty()) {
		Stock stock = stack.top();
		stack.pop();
		answer[stock.timing] = length - stock.timing;
	}

	return answer;
}