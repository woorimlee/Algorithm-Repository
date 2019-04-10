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


void findCustomer(vector <customer> &cus, vector <int> a, vector <int> b) {
	int time = 0, endCount = 0;
	queue <int> reception, repair;
	vector <pair <int, int> > receptionINFO; //고객 번호, 접수 소요 시간
	receptionINFO.resize(a.size());
	vector <int> repairINFO(b.size(), 0);
	while (1) {
		//1. 현재 시간과 도달한 시간이 똑같으면 접수 창구 큐에 넣기
		for (int i = 0; i < K; i++) {
			if (cus[i].tk == time) {
				reception.push(i);
			}
		}

		//2-1. 접수 창구 번호 부여
		//접수 창구 비어있고, reception 큐에 대기 인원 있으면
		for (int i = 0; i < reception.size(); i++) { //접수 창구 큐에 있는 인원 사이즈만큼
			for (int j = 0; j < receptionINFO.size(); j++) { // 접수처 사이즈 만큼
				if (receptionINFO[j].second == 0) { // 만약 j번째 접수처가 비어있으면
					receptionINFO[j].first = reception.front(); // j번째 접수처의 고객 번호
					receptionINFO[j].second = a[j]; // j 번째 접수처의 처리 시간 저장
					cus[receptionINFO[j].first].ak = j+1; // 접수 창구 큐에서 기다리던 고객(해당 번호)에 접수처 번호 저장
					reception.pop();
				}
			}
		}

		//2-2. 접수 창구 끝난 사람 체크
		//repair에 추가 reception에서 제거 
		for (int i = 0; i < receptionINFO.size(); i++) { //접수 창구 사이즈만큼
			if (receptionINFO[i].second == 0) { // 접수 창구 비어있는 곳은 패스
				continue;
			}
			receptionINFO[i].second--; // 한 타임마다 접수원 처리 시간 감소
			
			//만약 접수원 처리 시간이 0이 됐다면 업무를 다 처리했다는 뜻.
			//접수처는 자동으로 비어있는 상태가 되니(0의 값), 고객만 정비 창구 큐에 넣어줌.
			if (receptionINFO[i].second == 0) {
				endCount++;
			}
		}

		//3-1. 정비 창구 번호 부여
		//정비 창구 비어있고, repair 큐에 대기 인원 있으면

		//3-2. 정비 창구 끝난 사람 체크
		//모든 과정 끝난 사람 숫자 추가 repair에서 제거 

		//4. 모든 인원이 서비스를 다 받으면 while 끝
		if (endCount == K) {
			/*cout << endCount << "테스트 끝\n";
			for (int i = 0; i < cus.size(); i++) {
				cout << i << "번째 고객의 접창 번호 : " << cus[i].ak << " ";
			}*/
			break;
		}
		
		time++;
	}
}

int main(void) {
	cin >> T;
	int temp;

	for (int i = 1; i <= T; i++) {
		cin >> N >> M >> K >> A >> B;
		//초기화
		vector <int> a; //접수 창구별 시간 저장
		vector <int> b; //정비 창구별 시간 저장
		vector <customer> cus; //고객 정보 저장
		answer = -1;

		for (int j = 0; j < N; j++) {
			cin >> temp;
			a.push_back(temp);
		}
		for (int j = 0; j < M; j++) {
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
		findCustomer(cus, a, b);

		cout << "#" << i << " " << answer << "\n";
	}

	return 0;
}