//https://koi.or.kr/board?pageid=1&page_id=279&mod=document&keyword=54&uid=442
#include <iostream>

int main() {
	int cnt = 0;

	for (int i = 1; i <= 255; ++i) {
		int j = 0;
		while (j < 7 && ((i & (3 << j)) >> j) != 3) ++j;
		if (j == 7) {
			++cnt;
			std::cout << i << " ";
		}
	}
	std::cout << std::endl << cnt;
	return 0;
}