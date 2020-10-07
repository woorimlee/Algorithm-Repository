//1. 현재 주유소 값보다 낮은 값이 나오면, 그 값을 기준으로 삼음
//2. 낮은값 나오기 전까지 거리를 다 더해서 기억해둠
//0번째 : 5 -> 거리 2
//1번째 : 2 -> 거리 3 + 주유소 값이 바뀌면서 이전 값 * 거리를 총 비용에 저장해둠.
//2번째 : 2 -> 거리 4
//3번째는 검사 안해도 되고, 반복문 다 끝나면 총 비용 출력
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

/* 입력과 답 계산을 분리해서 푼 것 (보기 쉽게)
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