/* 프로그래머스 - Level 2 다리를 지나는 트럭 */

#include <queue>
#include <vector>

using namespace std;

struct Truck {
	int loaded_second;
	int weight;

	Truck(int loaded_second, int weight) : loaded_second(loaded_second), weight(weight) {}
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	queue<Truck> bridge;

	int second = 0, loaded_weight = 0, waiting = 0;
	while (waiting < truck_weights.size()) {
		second += 1;

		if (!bridge.empty()) {
			Truck front_truck = bridge.front();
			if (second - front_truck.loaded_second == bridge_length) {
				bridge.pop();
				loaded_weight -= front_truck.weight;
			}
		}

		int truck_weight = truck_weights[waiting];
		if (loaded_weight + truck_weight <= weight) {
			bridge.push(Truck(second, truck_weight));
			loaded_weight += truck_weight;
			waiting += 1;
		}
	}
	second += bridge_length;
	
	return second;
}