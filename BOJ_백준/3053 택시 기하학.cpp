#include <cstdio>
#define M_PI 3.14159265358979323846

int main() {
	//택시 기하학에서 원의 넓이 = 2 * r^2
	//유클리드 기하학에서 원의 넓이 = pi * r^2
	double R;
	scanf("%lf", &R);
	printf("%.6f\n%.6f", M_PI * R * R, 2 * R * R);
	return 0;
}