#include <iostream>
#include <string>
#include <deque>

using namespace std;

int T, n;
string p, arr;
deque <int> dq;

void R(deque <int> & dq) {
	if (dq.size() == 1) {
		return;
	}
	int temp, j = dq.size()-1;
	for (int i = 0; i < dq.size() / 2; i++) {
		temp = dq[i];
		dq[i] = dq[j];
		dq[j] = temp;
		j--;
	}
}

bool D(deque <int>& dq) {
	if (dq.size() == 0) {
		printf("error\n");
		return false; //에러면 false를 리턴. 더이상 함수 사용 못하게
	}
	else {
		dq.pop_front();
		return true;
	}
}

bool AC() {
	dq.clear();
	cin >> p; //함수
	cin >> n;
	cin >> arr; //배열
	int j = 1;
	int num;
	for (int i = 0; i < arr.size(); i++) {
		if ('0' <= arr[i] && arr[i] <= '9') {
			string snum = "";
			snum += arr[i];
			while ('0' <= arr[i + j] && arr[i + j] <= '9' && i + j < arr.size()) {
				snum += arr[i + j];
				j++;
				i++;
			}
			num = stoi(snum);
			dq.push_back(num);
			j = 1;
		}
	}
	for (auto it : dq) {
		cout << it << " ";
	}
	for (auto it : p) {
		if (it == 'R') {
			R(dq);
		}
		else {
			if (!D(dq)) {
				return false;	//에러 출력하면 더이상 뭐 안해도됨.
			}
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//R은 배열 숫자 순서 뒤집기
	//D는 첫 수 버리기
	//배열 비어있는데 D 쓰면 에러
	
	cin >> T;
	while (T--) {
		if (AC()) {
			if (dq.size() == 0) {
				cout << "[]\n";
			}
			else {
				cout << "[";
				for (int i = 0; i < dq.size() - 1; i++) {
					cout << dq[i] << ",";
				}
				cout << dq[dq.size() - 1];
				cout << "]\n";
			}
		}
	}
}