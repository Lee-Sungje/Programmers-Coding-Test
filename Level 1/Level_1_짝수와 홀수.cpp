/* 프로그래머스 - Level 1 짝수와 홀수 */

#include <string>

using namespace std;

string solution(int num) {
	return num % 2 ? "Odd" : "Even";
}