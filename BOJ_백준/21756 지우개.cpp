#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int N;
	cin >> N;

	//방법 1. 큐나 배열을 이용해 알고리즘을 구현
	//방법 2. 문제의 수학적 특성을 살펴보고 수식을 세움

	//방법 2 풀이법
	//마지막으로 남는 수는 2^x <= N < 2^(x+1) 꼴임
	//x를 구하기 위해서 N에 log2 연산을 하고 2의 제곱 꼴로 만들어 줌.
	cout << pow(2, int(log2(N)));

	return 0;
}