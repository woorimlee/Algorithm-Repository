#include <iostream>
#include <vector>
using namespace std;

//10,000 이하의 자연수로 길이 < 100,000 나왔으니 투 포인터 사용!
//저번 문제와 같이 int형을 담는 vector 하나를 선언해서
//두 개의 int형 변수인 left, right로 포인터 역할을 수행하게 한다.

int N, S;

int main(void) {
	ios::sync_with_stdio(false);
	
	//집합 갯수 N, 부분 집합의 합으로 만들 값 S
	cin >> N >> S;

	vector <int> vec(N);

	for (int i = 0; i < N; i++) {
		cin >> vec[i];
	}

	//N은 100,000까지니까 편하게 answer은 100,001로 선정함.
	int sum = vec[0], answer = 100001;
	int left = 0, right = 0;

	//투 포인터 알고리즘 시퀀스. 포인터 하나 먼저 출발시키고(right), 나머지 하나가 따라가게(left)
	while (right < N && left <= right) {
		if (sum < S) {
			right++;
			//더 이상 검사할 원소가 없음
			if (right >= N) break;

			sum += vec[right];
		}
		
		//합이 S이상 되는 것 중, 가장 짧은 것 구함
		else if (sum == S) {
			int temp = (right - left) + 1;
			if (answer > temp) answer = temp;
			right++;
			sum += vec[right];
		}

		else if(sum > S) {
			int temp = (right - left) + 1;
			if (answer > temp) answer = temp;

			sum -= vec[left];
			left++;
			
			//left를 +1 시켰더니 right의 위치를 넘어섰다면
			if (left > right && left < N) {
				//초기화.
				right = left;
				sum = vec[right];
			}
		}

	}

	if (answer == 100001) answer = 0;
	cout << answer << endl;

	return 0;
}