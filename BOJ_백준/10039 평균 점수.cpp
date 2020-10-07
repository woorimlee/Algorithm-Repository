#include <cstdio>
int main() {
	int ans = 0;
	int temp;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &temp);
		(temp < 40) ? temp = 40 : temp;
		ans += temp;
	}
	printf("%d", ans / 5);
}