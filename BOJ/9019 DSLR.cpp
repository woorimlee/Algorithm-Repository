#include <iostream>
#include <queue> 
#include <memory>

using namespace std;

int print_DSLR(int A, int now, char * operation, int * path) {
	if (now == A) {
		return 0;
	}
	int n = 0;
	n = path[now];

	print_DSLR(A, n, operation, path);
	cout << operation[now];
	return 0;
}

int main(void) {

	int T;
	cin >> T; 
	char operation[10000];
	bool check[10000] = { false, };
	int path[10000] = { 0, };

	while (T--) {
		//1. bfs 저장할 queue
		//2. 검사한 queue인지 저장할 배열
		//3. 이동 숫자 경로를 저장한 int 배열과
		//4. 그 숫자경로 별 적용시킨 연산을 저장할 char 배열
		queue <int> q;
		
		int A, B, now, next;
		cin >> A >> B;
		memset(check, false, sizeof(check));
		
		q.push(A); 
		while (!q.empty()) {
			now = q.front(); q.pop();
			if (now == B) {
				break;
			}

			next = (now * 2) % 10000;
			if (check[next] == false) {
				q.push(next);
				check[next] = true;
				path[next] = now;
				operation[next] = 'D';
			}

			next = (now - 1);
			if (next == 0) next = 9999;
			if (check[next] == false) {
				q.push(next);
				check[next] = true;
				path[next] = now;
				operation[next] = 'S';
			}

			next = ((now % 1000) * 10) + (now / 1000);
			if (check[next] == false) {
				q.push(next);
				check[next] = true;
				path[next] = now;
				operation[next] = 'L';
			}

			next = ((now % 10) * 1000) + (now / 10);
			if (check[next] == false) {
				q.push(next);
				check[next] = true;
				path[next] = now;
				operation[next] = 'R';
			}
		}
		print_DSLR(A, now, operation, path);
		cout << endl;
	}



	return 0;
}
