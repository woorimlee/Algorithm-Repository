//1. ���� ������ ������ ���� ���� ������, �� ���� �������� ����
//2. ������ ������ ������ �Ÿ��� �� ���ؼ� ����ص�
//0��° : 5 -> �Ÿ� 2
//1��° : 2 -> �Ÿ� 3 + ������ ���� �ٲ�鼭 ���� �� * �Ÿ��� �� ��뿡 �����ص�.
//2��° : 2 -> �Ÿ� 4
//3��°�� �˻� ���ص� �ǰ�, �ݺ��� �� ������ �� ��� ���
#include <iostream> 
#include <limits.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int N, i;
	std::cin >> N;
	int* r_len = new int[N];
	int* price = new int[N];
	for (i = 0; i < N - 1; i++) {
		std::cin >> r_len[i];
	}
	r_len[N - 1] = 0;

	int np = INT_MAX;
	long long ans = 0;
	for (i = 0; i < N; i++) {
		std::cin >> price[i];
		if (np > price[i]) {
			np = price[i];
		}
		ans = ans + (long long)r_len[i] * np;
	}
	std::cout << ans;
	return 0;
}

/* �Է°� �� ����� �и��ؼ� Ǭ �� (���� ����)
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int N , i;
	std::cin >> N;
	int* r_len = new int[N-1];
	int* price = new int[N];
	for (i = 0; i < N - 1; i++) {
		std::cin >> r_len[i];
	}
	for (i = 0; i < N; i++) {
		std::cin >> price[i];
	}
	
	int np = price[0]; //now_price
	int t_len = 0; //total length
	long long ans = 0;
	for (i = 0; i < N - 1; i++) { 
		if (np > price[i]) {
			ans = ans + (long long)t_len * np;
			np = price[i];
			t_len = 0;
		}
		t_len += r_len[i];
	}
	ans = ans + (long long)t_len * np;
	printf("%lld", ans);

	return 0;
}*/