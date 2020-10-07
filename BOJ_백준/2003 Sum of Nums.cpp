#include <iostream>
#include <vector>

using namespace std;

/*
N이 10,000까지 가능하기 때문에 모든 원소를 나열하고 조합을 찾는 방식의 시간 복잡도로는 풀지 못한다.
집합의 모든 원소가 자연수고, 만들고자 하는 답도 자연수면 Two pointer algorithm을 사용한다. (음수가 원소로 있으면 다른 방법 써야한다.)
집합의 head 부분에 포인터 두 개를 둬서 위치를 증가시키며 답을 찾는다. (진짜 포인터를 안 둬도 vec나 배열의 인덱스를 가리키게만 하면 되니 int 자료형을 쓴다)
*/
int N, M;

int main(void) {
	ios::sync_with_stdio(false);

	cin >> N >> M; // N이 원소 갯수, M이 만들고자 하는 답

	int answer = 0;
	//N 개의 int 값을 가진 vector A
	vector <int> A(N);

	for (int i = 0; i < N ; i++) {
		cin >> A[i];
	}

	//초기화
	int sum = A[0];
	int left = 0, right = 0;

	//투 포인터 알고리즘 시퀀스는 다음과 같다.
	//1. left는 right보다 작거나 같고, right가 N 직전까지
	//2. sum이 M보다 작으면 right++, 
	while (right < N && left <= right) {
		if (sum < M) {
			right++;
			//벡터 크기를 넘겼다면 검사 끝
			if (right >= N) break;
			
			sum += A[right];
		}
		else if (sum == M) {
			answer++;
			//정답 찾았으니 다시 right 포인터 하나 이동
			right++;
			sum += A[right];
		}
		else { //sum > M
			sum -= A[left];
			left++;
			//left == right 위치를 넘었으면, left 위치로 값 초기화.
			if (left > right) {
				right = left;
				if(left < N) sum = A[right];
			}
		}
	}
	cout << answer << endl;
	return 0;
}