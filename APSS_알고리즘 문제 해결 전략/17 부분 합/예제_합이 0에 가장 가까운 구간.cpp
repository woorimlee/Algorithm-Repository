//����� ������ ���Ե� �迭 A[i]�� ���� ��, �� ���� 0�� ���� ����� ������ ã�ƺ���.
//0���� i���� �κ����� ���ϴ� �Լ� partialsum�� �̿��� �κ��� psum�� ���� ��,
//a���� b���� Ư�� ������ �κ� ���� ���ϱ� ���� range_sum �Լ��� �������.
//psum[]�� �� ���� ���̰� ���� ���� ���� ���� 0�� ���� ����� �����̱� ������, psum[]�� �����ϰ� ���� ���� ���� ���� ���� ���Ѵ�.
//����������, �� ������ ��ġ���� ���ϱ� ���ؼ� psum[i]��°�� first���� �κ�����, second���� �� ������ index�� �����Դ�.

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

	cout << "partialsum�� ��� : ";
	for (auto it : psum) {
		cout << it.first << " " << it.second << " / ";
	}cout << "\n\n";

	sort(psum.begin(), psum.end());
	cout << "���ĵ� psum : ";
	for (auto it : psum) {
		cout << it.first << " " << it.second << " / ";
	}cout << "\n\n";

	int a = 0, b = 0; //a����, b����
	int min_sum = abs(psum[0].first); //psum[i] - psum[i-1]�� �ּڰ��� ã�� ���� ����
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

	cout << "���� 0�� ���� ����� ������ �� : " << min_sum;
	cout << "\n�� ������ ��ġ : " << ++a << " ~ " << b << "\n";

	return 0;
}