#include <iostream>
using namespace std;
int main() {
	int N= 1;
	long long S;
	long long sum = 0;
	cin >> S;
	//N의 최댓값을 구하는 것이니 N은 1부터 1 + 2 + ...
	//S == 6 ~ 10 사이의 값이라고 가정 --> 
	//6 => 1 + 2 + 3
	//7 => 1 + 2 + 4
	//8 => 1 + 2 + 5
	//9 => 1 + 2 + 6
	//10 => 1 + 2 + 3 + 4
	//6~9는 N이 최대 3임.
	//1부터 1씩 증가하는 등차수열의 합이 S값을 넘어가는 순간 최대 사용가능한 N은 마지막에 더해준 값 - 1
	while (1) {
		sum += N;
		if (sum > S) {
			cout <<	--N;
			return 0;
		}
		N++;
	}
	return 0;
}