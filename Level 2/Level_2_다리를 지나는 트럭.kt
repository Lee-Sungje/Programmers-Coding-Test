/* 프로그래머스 - Level 2 다리를 지나는 트럭 */

package level2

import java.util.*

class Solution {
    data class Truck(val loadedSecond: Int, val weight: Int)

    fun solution(bridge_length: Int, weight: Int, truck_weights: IntArray): Int {
        var bridge: Queue<Truck> = LinkedList<Truck>()

        var second = 0
        var loadedWeight = 0
        var waiting = 0
        while(waiting < truck_weights.size) {
            second++

            if(!bridge.isEmpty()) {
                val frontTruck = bridge.peek()
                if(second - frontTruck.loadedSecond == bridge_length) {
                    bridge.poll()
                    loadedWeight -= frontTruck.weight
                }
            }

            val truckWeight = truck_weights[waiting]
            if(loadedWeight + truckWeight <= weight) {
                bridge.add(Truck(second, truckWeight))
                loadedWeight += truckWeight
                waiting += 1
            }
        }
        second += bridge_length

        return second
    }
}