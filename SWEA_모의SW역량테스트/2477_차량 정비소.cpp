#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int T, N, M, K, A, B, answer;

struct customer {
	int tk; // 도착 시간
	int k; // 고객 번호
	int ak = 0; // 접수 창구 번호
	int bk = 0; // 정비 창구 번호
	customer(int tk, int k) : tk{ tk }, k { k } {};
};

void findCustomer(vector <customer> &cus) {
	int time = 0;
	queue <int> reception, repair;
	while (1) {
		//1. 현재 시간과 도달한 시간이 똑같으면 큐에 넣기
		for (int i = 0; i < K; i++) {
			if (cus[i].tk == time) {
				reception.push(i);
			}
		}

		//2-1. 접수 창구 번호 부여
		//접수 창구 비어있고, reception 큐에 대기 인원 있으면

		//2-2. 접수 창구 끝난 사람 체크
		//repair에 추가 reception에서 제거 

		//3-1. 정비 창구 번호 부여
		//정비 창구 비어있고, repair 큐에 대기 인원 있으면

		//3-2. 정비 창구 끝난 사람 체크
		//모든 과정 끝난 사람 숫자 추가 repair에서 제거 

		//4. 모든 인원이 서비스를 다 받으면 while 끝
	}
}

int main(void) {
	cin >> T;
	int temp;

	for (int i = 1; i <= T; i++) {
		cin >> N, M, K, A, B;
		//초기화
		vector <int> a; //접수 창구별 시간 저장
		vector <int> b; //정비 창구별 시간 저장
		vector <customer> cus; //고객 정보 저장
		answer = -1;

		for (int j = 0; j < N; j++) {
			cin >> temp;
			a.push_back(temp);
		}
		for (int j = 0; j < N; j++) {
			cin >> temp; 
			b.push_back(temp);
		}
		for (int j = 0; j < K; j++) {
			cin >> temp;
			//도착 시간, 고객 번호 저장
			cus.push_back(customer(temp, j));
		}
		
		//도착 시간별로 정렬
		//sort(cus.begin(), cus.end());
		findCustomer(cus);
		
		cout << "#" << i << " " << answer << "\n";
	}



	return 0;
}