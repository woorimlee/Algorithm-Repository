#include <iostream>
#include <queue> 
#include <memory.h>
#include <string>

using namespace std;

int main(void) {

	int T;
	cin >> T;
	bool check[10001] = { false, };
	int A, B;

	while (T--) {
		//dslr에는 사용된 operator와 적용된 결괏값을 저장할 것임.
		queue <pair<string, int> > dslr;
		pair <string, int> now;
		int next;
		cin >> A >> B;
		memset(check, false, sizeof(check));
		dslr.push({ "", A });
		check[A] = true;
		
		while (!dslr.empty()) {
			now = dslr.front(); 
			dslr.pop();

			//정답이면 반복 끝
			if (now.second == B) {
				break;
			}

			//D 실행결과 반영
			next = (now.second * 2) % 10000;
			if (check[next] == false) {
				//pair의 string 부분에는 현재 + D를 더한 값을 넘기고
				//pair의 int 부분에는 next 값을 넘겨
				dslr.push({ now.first + 'D', next });
				check[next] = true;
			}

			//S 실행결과 반영
			//현재 값 -1이 0이면 9999를 저장하는게 아님!
			//현재 값 == 0이면 9999를 저장, 아니면 -1 값 저장
			next = ((now.second) == 0) ? 9999 : now.second - 1;
			if (check[next] == false) {
				dslr.push({ now.first + 'S', next });
				check[next] = true;
			}

			//L 실행결과 반영
			next = ((now.second % 1000) * 10) + (now.second / 1000);
			if (check[next] == false) {
				dslr.push({ now.first + 'L', next });
				check[next] = true;
			}

			//R 실행결과 반영
			next = ((now.second % 10) * 1000) + (now.second / 10);
			if (check[next] == false) {
				dslr.push({ now.first + 'R', next });
				check[next] = true;
			}
		}
		cout << now.first << "\n";
	}

	return 0;
}
