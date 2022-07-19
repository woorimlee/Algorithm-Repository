#include <iostream>
#include <queue>

using namespace std;

int n, w, L;
int truck[1001];

int main() {
	cin >> n >> w >> L;
	for (int i = 0; i < n; i++) 
		cin >> truck[i];
	
	queue <int> q;
	int time = 0, total = 0;
	for (int i = 0; i < n; i++) {
		
		//트럭 내보내기
		while (1) {
			//트럭이 도로에 다 찬 경우 | 이동중인 트럭이 다리 맨 끝에 위치
			if (q.size() == w) {
				total -= q.front();
				q.pop();
			}
			//트럭을 더 넣어도 되면 트럭 내보내기용 while 종료
			if (total + truck[i] <= L) break;
			//트럭 한 칸씩 도로 이동
			q.push(0);
			time++;
		}
		// 다음 트럭 넣기
		q.push(truck[i]);
		total += truck[i];
		time++;
	}
	cout << time + w;
	return 0;
}