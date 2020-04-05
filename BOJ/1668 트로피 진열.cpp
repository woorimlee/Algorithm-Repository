#include <iostream>

using namespace std;

int N;
int arr[50];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int LC = 1; //���ʿ��� ���� ���� ī��Ʈ. �ּ� �� ��
	int highest = arr[0];
	for (int i = 1; i < N; i++) {
		if (arr[i] > highest) {
			LC++;
			highest = arr[i];
		}
	}

	int RC = 1; //�����ʿ��� ���� ���� ī��Ʈ. �ּ� �� ��
	highest = arr[N-1];
	for (int i = N-1; i >= 0; i--) {
		if (arr[i] > highest) {
			RC++;
			highest = arr[i];
		}
	}
	cout << LC << "\n" << RC;
	
	return 0;
}