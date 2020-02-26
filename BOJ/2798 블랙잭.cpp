#include <iostream>

using namespace std;

int main()
{
	int N, M;
	int card[101];
	cin >> N >> M;
	//M에 근접한 수를 저장할 변수
	int ans = 0;
	for (int i = 0; i < N; i++) {
		//카드 입력
		cin >> card[i];
	}

	//3중 포문으로 모든 조합의 경우를 검사할 것임.
	for (int i = 0; i < N - 2; i++)	{
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++)	{
				//세 카드의 합이 M이하인 동시에, 이전에 계산한 M에 최대로 근접한 카드의 합이 현재 카드의 합보다 작으면 
				if (card[i] + card[j] + card[k] <= M &&  ans < card[i] + card[j] + card[k])
				{
					//답 갱신
					ans = card[i] + card[j] + card[k];
				}
			}
		}
	}
	//next_permutation으로도 풀 수 있을듯.
	cout << ans;
}