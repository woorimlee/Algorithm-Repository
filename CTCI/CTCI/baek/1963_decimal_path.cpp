#include <iostream>
#include <string>
#include <queue>

using namespace std;

//1. 소수 찾기
//2. 원하는 숫자로 도달하는데 최소 몇 단계가 필요한지 찾을 것이니, 현재 상태에서 숫자 하나만 바꿔서 만들 수 있는 
//   1) 소수이고, 2) 1000 이상의 값이며, 3) 이전에 검사하지 않은 값을 모두 큐에 넣어두며, 여기까지 도달하는데 걸리는 비용은 1이라고 저장해둔다.
//ex) 1033 -> 숫자 한 자리만 바꿔서 만들 수 있는 1) 소수이고, 2) 1000 이상의 값이며, 3) 이전에 검사하지 않은 숫자가 총 5개며, 모두 큐에 넣었다고 가정.
//    큐의 size는 현재 5이며, 이 숫자에 도달하는데 걸리는 비용은 1.
//    현재 큐에 들어있는 5개의 숫자를 다시 숫자 한 자리만 바꾸고 1) ~ 3) 까지의 조건을 만족하는 숫자를 큐에 넣으며 여기까지 걸리는 비용을 +1 한다.
//    5개의 숫자를 모두 검사하고 난 뒤 큐에 새로 저장한 검사 값들은, 1033에서 이 값까지 도달하는데 비용이 2인 상태.
//    이런식으로 진행하며 원하는 숫자에 도달시 비용을 출력.
//위와 같은 시퀀스로 프로그래밍 할 것이기 때문에 Queue와 BFS 개념을 사용할 것이다.

bool decimal[10000] = { false, };

int change(int num, int index, int x) {
	if (index == 0 && x == 0) {
		return num;
	}
	string s = to_string(num);
	s[index] = x + '0';
	return stoi(s);
}

int main(void) {

	int T, current, goal;
	cin >> T;

	//1. 소수를 찾아서 bool 배열에 기록해두는 과정.
	//true 인 경우 소수다.
	for (int i = 2; i*i < 10000; i++) {
		if (decimal[i] == false) {
			for (int j = i * i; j < 10000; j += i) {
				decimal[j] = true;
			}
		}
	}

	while (T--) {
		bool flag = false;
		queue <int> q;
		cin >> current >> goal;
		int check[10000] = { 0, };

		if (current == goal) {
			cout << 0 << endl;
			continue;
		}

		//BFS 시작.
		q.push(current);
		while (!q.empty()) {
			if (flag == true) {
				break;
			}
			int now = q.front(); q.pop();
			
			//일, 십, 백, 천의 총 네 자리를 바꿀 것(int i = 0 ~ 3)
			for (int i = 0; i < 4; i++) {
				if (flag == true) {
					break;
				}
				//각 자리수마다 바꿀 수 있는 숫자 값은 0 ~ 9. (int j = 0 ~ 9)
				for (int j = 0; j <= 9; j++) {
					//현재 검사하려는 값(now)에서 i에 해당하는 자리수를 j 숫자로 바꿔서 1) ~ 3)까지 조건을 만족하는지 검사한다.
					int next = change(now, i, j);
					if (next >= 1000 && !decimal[next] && check[next] == 0) { //1000보다 큰 값이고, 소수고, 검사 안 한 값이면
						//다음에 검사할 목표가 되니 큐에 넣어두고.
						q.push(next);
						//이 숫자까지 도달하기 위해 비용 값을 +1 해두고.
						check[next] = check[now] + 1;
						//만약 목적인 숫자라면 바로 정답 출력.
						if (next == goal) {
							cout << check[now] << endl;
							flag = true;
						}
					}
				}
			}
		}

		//위의 과정을 모두 진행해도 답이 나오지 않는다면, Impossible 출력.
		if (flag == false) {
			cout << "Impossible" << endl;
		}

	}
	return 0;
}