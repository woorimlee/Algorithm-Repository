#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 회의를 배정한다는 과정을 독립된 부분 문제로 살펴보면
// 회의를 배정하기 위한 조건 : 현시간을 기준으로 배정된 회의가 없어야함
// 배정된 회의가 없는 현 상황에서 가장 많은 회의를 만들어주는 조건 : 언제 시작하든 일찍 끝나는 회의를 배정
// 총 회의 시간이 짧든, 시작하는 시간이 빠르든 다른 회의에 비해 회의가 늦게 끝난다면 
// 그 차이만큼(회의a - 회의b) 시간을 낭비하게 됨

int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	vector<pair<int, int> > meeting(N);

	for (int i = 0; i < N; i++) {
		cin >> meeting[i].second >> meeting[i].first;
	}
	// 일찍 끝나는 시간을 기준으로 오름차순 정렬 후 겹치는 시간있으면 (상관은 없지만) 일찍 시작하는 강의 위주로 정렬
	sort(meeting.begin(), meeting.end());

	int end_time = meeting[0].first;
	int ans = 1;
	for (int i = 1; i < N; i++)
	{
		if (end_time <= meeting[i].second)
		{
			ans++;
			end_time = meeting[i].first;
		}
	}
	cout << ans;

	return 0;
}
