#include <iostream>
#include <string>
#include <deque>

using namespace std;

bool r_flag = false;
int T, n;
string p, arr;
deque <int> dq;

//R 연산 : 
//출력할 때 배열을 앞에서부터 출력하냐, 뒤에서부터 출력하냐만 결정해주면 됨.

//D 연산 : 
//pop_front & empty() 체크

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
	r_flag = false; //true면 R 한 거, false면 R 안한거 or 짝수번 한 거
	int j = 1;
	string snum = "";
	dq.clear();
	cin >> p; //함수
	cin >> n;
	cin >> arr; //배열

	//입력받은 배열에서 숫자 쪼개 실제 배열에(덱) 집어넣기
	for (auto it : arr) {
		//숫자면 문자열에 더해두다가
		//숫자 아닌순간 && 문자열에 어떤 값이 있다면
		//배열에 추가하고 문자열 초기화
		if ('0' <= it && it <= '9') {
			snum += it;
		}
		else if(snum != "") {
			dq.push_back(stoi(snum));
			snum = "";
		}
	}

	//함수 하나씩 확인하면서 덱에 적용하기
	for (auto it : p) {
		if (it == 'R') {
			r_flag = !r_flag;
		}
		else { //함수가 D면
			if (dq.size() == 0) {
				cout << "error\n";
				return false; //에러면 false를 리턴. 더이상 함수 사용 못하게
			}
			else if(r_flag) { // 거꾸로 배열이 구성되어 있으면
				dq.pop_back();
			}
			else {
				dq.pop_front();
			}
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> T;
	while (T--) {
		//AC를 실행하는데, error만 아니면 [배열값]출력
		//AC는 error가 발생한 경우 false를 return.
		if (AC()) {
			if (dq.empty()) {
				cout << "[]\n";
			}
			else {
				int size = dq.size();
				cout << "[";
				if (r_flag) {//R이 홀수 번 실행되면 거꾸로 출력
					for (int i = 0; i < size - 1; i++) {
						cout << dq.back() << ",";
						dq.pop_back();
					}
					cout << dq[0];
				}
				else {
					for (int i = 0; i < size - 1; i++) {
						cout << dq[i] << ",";
					}
					cout << dq.back();
				}
				cout << "]\n";
			}
		}

	}
}