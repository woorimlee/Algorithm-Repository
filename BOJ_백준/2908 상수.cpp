#include <iostream> 
#include <string>

using namespace std;

int main() {
	string A, B;
	cin >> A >> B;

	string rA = ""; //reverse A
	string rB = ""; //reverse B
	//rA와 rB는 입력받은 두 숫자(string형태)의 맨 뒤 숫자부터
	//더해줘 나가는 string임
	for (int i = A.length() - 1; i >= 0; i--) {
		rA += A[i];
		rB += B[i];
	}
	//stoi : string을 int로 바꾸기
	//바꾼 두 값 중 처음으로 입력된 값이 더 크다면 처음 값 출력
	//아니면 두 번째 값 출력
	cout << (stoi(rA) > stoi(rB) ? rA : rB) << "\n";
	return 0;
}