#include<iostream>
#include<string>
#include<vector>
using namespace std;

int N, kbs1_idx, kbs2_idx;
string str;

void button();

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		//string 형태는 == "문자열"로 검사 가능
		if (str == "KBS1") {
			kbs1_idx = i;
		}
		else if (str == "KBS2") {
			kbs2_idx = i;
		}
	}
	//KBS1을 무조건 먼저 맨 위로 올릴건데,
	//KBS1밑에 KBS2가 있으면 문제가 없으나,
	//KBS2가 KBS1보다 위에 있다면 KBS2가 한 칸 밑으로 밀려나기 때문에
	//KBS2의 인덱스 값을 1 증가시킨다
	if (kbs1_idx > kbs2_idx)
		kbs2_idx++;
	button();
	return 0;
}

void button() {
	int i = 0;
	//KBS1 나올때까지 현재 가리키는 채널 내리기
	for (i = 0; i < kbs1_idx; i++) cout << '1';
	//KBS1채널 맨 처음으로 올리기
	for (i = 0; i < kbs1_idx; i++) cout << '4';
	if (kbs2_idx == 0)
		return;
	//KBS2 나올때까지 현재 가리키는 채널 내리기
	for (i = 0; i < kbs2_idx; i++) cout << '1';
	//KBS2 채널 두번째로 올리기
	for (i = 1; i < kbs2_idx; i++) cout << '4';
	return;
}

