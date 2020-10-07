#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, answer, temp;
struct stairs {
	int x, y, h;
	int count;
	stairs(int x, int y, int h) : x{ x }, y{ y }, h{ h }{};
};

struct people {
	int x, y;
	int distA, distB;
	people(int x, int y) : x{ x }, y{ y }{};
};

vector <people> pe;
vector <stairs> st;


int lunchTime(vector<int> v, int t) {
	if (v.size() == 0) return 0;
	//도착시간 기준으로 정렬
	sort(v.begin(), v.end());

	//계단 사용중인지 확인하는 배열
	int use[3] = { 0, };

	//현재까지 소요된 시간
	int time = v[0];

	while (true) {
		for (int i = 0; i < v.size(); i++) {
			//이미 계단을 내려갔다면 continue
			if (!v[i])continue;

			//도착시간 확인
			if (v[i] <= time) {

				for (int j = 0; j < 3; j++) {
					//빈 계단이 있는지 확인
					if (use[j] <= 0) {
						use[j] = t;
						v[i] = 0;
						if (i == v.size() - 1) {
							return time + t;
						}
						break;
					}
				}
			}
		}

		//1초 지난거에 대한 처리
		for (int i = 0; i < 3; i++) {
			use[i]--;
		}
		time++;
	}
}

//모든 경우의 수 계산
void dfs(vector <int> & A, vector <int> &B, int person) {
	if (person >= pe.size()) {
		//계단 1, 2 이용하는 사람에 대한 경우의 수가 다 만들어지면
		answer = min(answer, max(lunchTime(A, st[0].h), lunchTime(B, st[1].h)));
		return;
	}

	//계단 수만큼
	//cout << answer;
	for (int j = 0; j < 2; j++) {
		if (j == 0) {
			A.push_back(pe[person].distA);
		}
		else
			B.push_back(pe[person].distB);
		//cout << person << " " << j;
		dfs(A, B, person + 1);
		//cout << endl;
		//cout << lunchTime(A, st[0].h) << " ";
		//cout << lunchTime(B, st[1].h) << endl;
		

		if (j == 0)
			A.pop_back();
		else
			B.pop_back();
	}
}

int main() {
	cin >> T;
	int temp;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		//초기화
		//to do
		pe.clear();
		st.clear();
		answer = 987654321;

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				cin >> temp;
				if (temp == 1) {
					pe.push_back(people(k, j));
				}
				else if (temp >= 2) {
					st.push_back(stairs(k, j, temp));
				}
			}
		}

		//출구 거리 계산
		for (int j = 0; j < pe.size(); j++) {
			pe[j].distA = abs(pe[j].x - st[0].x) + abs(pe[j].y - st[0].y);
			pe[j].distB = abs(pe[j].x - st[1].x) + abs(pe[j].y - st[1].y);
			//cout << pe[j].distA << " " << pe[j].distB << endl;
		}

		vector <int> stairA;
		vector <int> stairB;
		//cout << answer;
		dfs(stairA, stairB, 0);
		cout << "#" << i << " " << answer + 1 << "\n";
	}

	return 0;
}