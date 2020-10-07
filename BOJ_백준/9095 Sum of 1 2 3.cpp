	#include <iostream>

	using namespace std;

	int n, answer = 0;

	//만약 찾고자 하는 숫자가 4면
	//f(1) + 1 --> f(2)
	//f(2) + 1 --> f(3)
	//f(3) + 1 --> f(4) : return & answer++
	//f(3) + 2 --> f(5) : return 
	//f(3) + 3 --> f(6) : return
	//f(2) + 2 --> f(4) : return & answer++
	// ... ...
	void find_combination(int current, int goal) {
		if (current == goal) {
			answer++;
			return;
		}
		else if (current > goal) {
			return;
		}

		find_combination(current + 1, goal);
		find_combination(current + 2, goal);
		find_combination(current + 3, goal);

		return;
	}

	int main(void) {
		cin >> n;
		int temp = 0;
		while (n--) {
			cin >> temp;
			find_combination(0, temp);
			cout << answer << endl;
			answer = 0;
		}


		return 0;
	}