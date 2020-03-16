#include <iostream>
#include <queue>

using namespace std;

int T, N, M, cnt;
int imp; //imp == important. 중요도 입력 받을 예정

/*
큐의 가장 앞 문서가 제일 중요도가 높은 상태라면 프린트 
아니라면 순서가 밀려남.
ex) 6 0
1(0번째) 1(...) 9 1 1 1
처음 큐 검사에서 0번째는 프린터 출력 순서 맨 뒤로
두 번째 큐 검사에서 1번째 프린터 출력 순서 맨 뒤로
9 1 1 1 1(6번째) 1(0번째) 1(1번째)
*/

int main() {
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cnt = 1;
		cin >> N >> M;
		queue<pair<int, int> > q;
		//우선순위 큐는 큐에 넣은 값들을 오름차순으로(바꿀 수 있음)
		priority_queue<int> pq;
		pair<int, int> temp;
		for (int j = 0; j < N; ++j) {
			cin >> imp;
			q.push({ j, imp });
			pq.push(imp);
		}

		//중요도가 일치하고 원하는 출력 순서의 문서를 찾을 때까지
		while (q.front().second != pq.top() || q.front().first != M) {
			temp = q.front();
			q.pop();
			//cout << temp.first << " " << temp.second << "\n";
			if (temp.second == pq.top()) {
				//cout << "if\n";
				pq.pop();
				//프린터 순서가 늘어나는 경우는 출력을 하는 경우에만 늘어남
				//우선순위 높은거 하나씩 프린팅할때 늘어난다는 뜻
				cnt++;
				continue;
			}
			q.push(temp);
		} 
		cout << cnt << "\n";
	}
	return 0;
}
