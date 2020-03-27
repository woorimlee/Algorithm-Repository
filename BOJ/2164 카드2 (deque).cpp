#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 1;
	cin >> N;

	deque<int> dq;
	
	//[0]번째 인덱스가 제일 위에 있는 카드라고 가정
	//1부터 N까지 카드 번호를 dq에 저장해 둠
	dq.resize(N);
	for (int i = 0; i < N; i++) {
		dq[i] = i + 1;
	}

	int card;
	//맨 위 카드는 버리고 그 다음으로 위에 있는 카드를 맨 밑으로
	while (dq.size() != 1) {
		dq.pop_front();
		card = dq.front();
		dq.pop_front();
		dq.push_back(card);
	}
	cout << dq.front();

	return 0;
}