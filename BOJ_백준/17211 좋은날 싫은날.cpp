#include <iostream>
#include <cmath>
using namespace std;

int N;
int now_Jae;

int main() {
	cin >> N >> now_Jae;
	//now_Jae == 0 ? 좋은 날 : 싫은날
	double gg, gb, bg, bb; //좋은날->좋은날, 좋은날->나쁜날, 나쁜날->좋은날, 나쁜날->나쁜날
	cin >> gg >> gb >> bg >> bb;
	double good_day = 1;
	double bad_day = 1;
	if (now_Jae == 0) {
		good_day = gg;
		bad_day = gb;
	}
	else {
		good_day = bg;
		bad_day = bb;
	}
	//N일 뒤, i == 1부터 시작
	double temp;
	for (int i = 1; i < N; i++) {
		temp = good_day;
		good_day = good_day * gg + bad_day * bg;
		bad_day = temp * gb + bad_day * bb;
	}
	int good_day_ans = round(good_day * 1000);
	int bad_day_ans = round(bad_day * 1000);
	cout << good_day_ans << "\n" << bad_day_ans;
}