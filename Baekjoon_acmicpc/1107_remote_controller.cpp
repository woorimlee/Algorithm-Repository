#include <iostream>

using namespace std;

//현재 채널 100번.
//고장난 버튼을 입력 받으면 bool 배열의 해당 인덱스를 true로 만들어 고장난 상태라고 말한다.
//N으로 바로 이동 가능한지, 불가능 하다면 가장 가까운 수를 구해서 몇 번 +나 - 버튼을 누르면 될지 구한다.
//모든 경우의 수를(모든 채널) 다~ 분석하는 브루트 포스 방식으로 풀 것이다.

//ex. N : 500,000, 고장난 버튼은 7과 0을 뺀 나머지라고 하면, 정답을 구하는데 두 가지 방법이 있다.
//1) 77,777로 이동해서 + 버튼만 누른다
//2) 700,000로 이동해서 - 버튼만 누른다.
//2)번이 훨씬 빠른 방법이다. 
//따라서 우리는 모든 경우의 수(채널)를 계산할 때 500,000이 넘는 채널도 검색해야 한다.

//고장난 버튼을 담을 bool 배열
bool button[10];

//브루트 포스 방식으로 모든 경우의 수(채널)를 검색하면서 
//숫자 버튼 클릭으로 이동 가능한 채널인지 판단하는 함수.
int check_num(int temp) {
	if (temp == 0) {
		if (button[0]) {
			return 0;
		}
		else return 1;
	}
	int num_length = 0;
	while (temp) {
		if (button[temp%10]) {
			return 0;
		}
		temp /= 10;
		num_length++;
	}
	return num_length;
	//이동 불가능한 채널이면 0을 return.
	//이동 가능한 채널이면 채널의 숫자 갯수 return.
}

int main(void) {

	int N;//이동하려는 채널
	int M;//고장난 버튼 갯수
	int temp;
	int current = 100;
	int answer = 0;
	int calculate_sum;
	cin >> N;
	cin >> M;
	
	for (int i = 0; i < M; i++) {
		cin >> temp;
		button[temp] = true;
	}

	//현재 위치한 채널인 100번 채널에서 +나 -만 눌러서 몇 번만에 N 채널에 도달할 수 있는가
	answer = abs(N - current);

	for (int i = 0; i < 1000000; i++) {
		temp = check_num(i);
		//check_num이 0을 return하면 그냥 다음 경우의 수로 넘어가고
		//0이 아닌 값을 return하면 1)이동하려는 채널 - 이동 가능한 채널
		//2) 1)의 결과 값에 채널의 숫자 갯수를 더해서
		//3) 100번에서 +나 - 버튼만 눌러서 이동한 값보다 빠른지 판단.

		//ex) N = 109, 고장난 숫자 없음.
		//0) answer = 109 - 100 = 9. 
		//1) check_num(109)는 3을 return. 따라서 temp = 3
		//2) N - i = 109 - 109 = 0
		//3) calculate_sum = 0 + 3
		//4) answer > calculate_sum이 9 > 3으로 true인 상황.
		//5) 따라서 answer는 3.
		if (temp) {
			calculate_sum = abs(N - i) + temp;
			if (answer > calculate_sum) {
				answer = calculate_sum;
			}
		}
	}

	cout << answer << endl;
	return 0;
}

/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> vec;

int check_num(int temp) {
	if (temp == 0) {
		if (binary_search(vec.begin(), vec.end(), 0)) {
			return 0;
		}
		else return 1;
	}
	int num_length = 0;
	while (temp>0) {
		if (binary_search(vec.begin(), vec.end(), temp%10)) {
			return 0;
		}
		temp /= 10;
		num_length++;
	}
	return num_length;
}

int main(void) {

	int N;//이동하려는 채널
	int M;//고장난 버튼 갯수
	int temp;
	int current = 100;
	int answer = 0;
	int calculate_sum;
	cin >> N;
	cin >> M;


	for (int i = 0; i < M; i++) {
		cin >> temp;
		vec.push_back(temp);
	}

	answer = abs(N - current);

	for (int i = 0; i < 1000000; i++) {
		temp = check_num(i);
		if (temp > 0) {
			calculate_sum = abs(N - i) + temp;
			if (answer > calculate_sum) {
				answer = calculate_sum;
			}
		}
	}
	cout << answer << endl;
	return 0;
}*/