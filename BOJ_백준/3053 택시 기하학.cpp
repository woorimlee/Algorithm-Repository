#include <cstdio>
#define M_PI 3.14159265358979323846

int main() {
	//�ý� �����п��� ���� ���� = 2 * r^2
	//��Ŭ���� �����п��� ���� ���� = pi * r^2
	double R;
	scanf("%lf", &R);
	printf("%.6f\n%.6f", M_PI * R * R, 2 * R * R);
	return 0;
}