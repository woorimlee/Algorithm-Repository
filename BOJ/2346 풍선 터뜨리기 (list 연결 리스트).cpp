#include <iostream>
#include <list>

using namespace std;

int main() {
	int N, temp;
	cin >> N;
	//first에는 적혀있는 수, second에는 풍선 번호
	list <pair <int, int> > balloon;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		balloon.push_back({ temp, i + 1 });
	}
	int cnt;
	list <pair <int, int>>::iterator it = balloon.begin();
	while (balloon.size()) {
		//풍선 번호 출력
		cout << (*it).second << " ";
		//풍선이 하나만 남은 상태면 이하의 풍선 삭제 ~ 다음 풍선 탐색
		//부분을 할 필요가 없음. 오히려 에러 발생함
		if (balloon.size() == 1)
			return 0;

		//cnt는 삭제할 풍선 노드에 적혀있는 수를 기억해둠
		cnt = it->first;
		//현재 삭제한 풍선의 다음 풍선을 가리키게 함
		it = balloon.erase(it);
		//다음 풍선을 가리키는 순간 적혀있는 수가 양수일 때 
		//이미 한 번은 다음 풍선을 가리키는 것으로 생각할 수 있음.
		//따라서 양수의 경우 반복문을 한 번 덜 돌림
		if (it == balloon.end() && cnt > 0)
			//이 부분은 다음 풍선을 가리켰는데 end 부분이라면
			//맨 처음 풍선을 가리키게 함
			it = balloon.begin();
		if (cnt > 0) {
			for (int j = 0; j < cnt - 1; j++) {
				it++;
				if (it == balloon.end()) {
					it = balloon.begin();
				}
			}
		}
		//음수일 경우
		else {
			for (int j = 0; j < (cnt * -1); j++) {
				if (it == balloon.begin()) {
					it = balloon.end();
				}
				it--;
			}
		}
	}
	return 0;
}