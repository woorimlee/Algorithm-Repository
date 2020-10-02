//양수와 음수가 포함된 배열 A[i]가 있을 떄, 그 합이 0에 가장 가까운 구간을 찾아보자.
//0부터 i까지 부분합을 구하는 함수 partialsum을 이용해 부분합 psum을 구한 뒤,
//a부터 b까지 특정 구간의 부분 합을 구하기 위해 range_sum 함수를 만들었다.
//psum[]의 두 값의 차이가 가장 작은 것이 합이 0에 가장 가까운 구간이기 때문에, psum[]을 정렬하고 값의 차가 가장 작은 것을 구한다.
//마지막으로, 두 구간의 위치까지 구하기 위해서 psum[i]번째의 first에는 부분합을, second에는 그 구간의 index를 가져왔다.

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair <int, int> > partialsum(const array <int, 10>& a) {
	vector <pair<int, int> > ret(a.size());
	ret[0].first = a[0];
	ret[0].second = 0;

	for (int i = 1; i < a.size(); i++) {
		ret[i] = make_pair( (a[i] + ret[i - 1].first), i);
	}

	return ret;
}

int main() {

	array <int, 10> A = { -14, 7, 2, 3, -8, 4, -6, 8, 9, 11 };
	vector <pair<int, int> > psum;
	psum = partialsum(A);

	cout << "partialsum의 결과 : ";
	for (auto it : psum) {
		cout << it.first << " " << it.second << " / ";
	}cout << "\n\n";

	sort(psum.begin(), psum.end());
	cout << "정렬된 psum : ";
	for (auto it : psum) {
		cout << it.first << " " << it.second << " / ";
	}cout << "\n\n";

	int a = 0, b = 0; //a구간, b구간
	int min_sum = abs(psum[0].first); //psum[i] - psum[i-1]의 최솟값을 찾기 위한 변수
	int temp_sum = 0;
	for (int i = 1; i < psum.size(); i++) {
		temp_sum = abs(psum[i].first - psum[i - 1].first);
		if (min_sum > temp_sum) {
			min_sum = temp_sum;
			a = psum[i].second;
			b = psum[i - 1].second;
			if (a > b) {
				swap(a, b);
			}
		}
	}

	cout << "합이 0에 가장 가까운 구간의 값 : " << min_sum;
	cout << "\n두 구간의 위치 : " << ++a << " ~ " << b << "\n";

	return 0;
}