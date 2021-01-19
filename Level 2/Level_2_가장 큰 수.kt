/* 프로그래머스 - Level 2 가장 큰 수 */

package level2

class Solution {
    fun solution(numbers: IntArray): String {
        val stringNumbers = Array(numbers.size) {
            i -> numbers[i].toString()
        }.sortedWith(Comparator { o1, o2 ->
            when {
                (o1 + o2) < (o2 + o1) -> 1
                (o1 + o2) > (o2 + o1) -> -1
                else -> 0
            }
        })

        var answer = ""
        for (stringNumber in stringNumbers) {
            answer += stringNumber
        }
        return if (answer.first() == '0') "0" else answer
    }
}