/* 프로그래머스 - Level 2 멀쩡한 사각형*/

package level2

class Solution {
    private fun gcd(op1: Long, op2: Long): Long = if (op1 % op2 == 0L) op2 else gcd(op2, op1 % op2)

    fun solution(w: Int, h: Int): Long {
        val width: Long = w.toLong()
        val height: Long = h.toLong()

        return width * height - (width + height - gcd(width, height))
    }
}