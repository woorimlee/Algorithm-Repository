#include <iostream>
using namespace std;
int main() {
	int x, y;
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	const char* day[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	cin >> x >> y;
	for (int i = 0; i < x - 1; i++) {
		y += month[i];
	}
	y = y % 7;
	cout << day[y];
	return 0;
}