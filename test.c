#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Num 11


int randomNumber = 0;
int N = 1;
char op;


int Random() {
	randomNumber = rand() % Num;
	srand((unsigned)time(NULL));

	return randomNumber;
}



void game() {
	int answer;
	Random();

	do {
		int Hint[6];

		printf("%d��° ���� �Է�:", N);
		scanf_s("%d", &answer);

		if (answer > randomNumber) {
			Hint[N - 1] = answer;
			
			if (N > 1 && N <= 5) {
				if (Hint[N - 2] < Hint[N - 1] && N>1) {
					printf("\n");
					printf("1.��Ģ����!!!\n");
					printf("���?(y/n):");
					scanf_s(" %c", &op, sizeof(op));

					if (op == 'y') {
						N = 1;
						Random();
						continue;
					}
					else {
						printf("��������...");
						break;
					}
				}
				else if (Hint[N - 2] = Hint[N - 1] && N > 1 && N <= 5) {
					printf("\n");
					printf("5.��Ģ����!!!\n");
					printf("���?(y/n):");
					scanf_s(" %c", &op, sizeof(op));
					if (op == 'y') {
						N = 1;
						Random();
						continue;
					}
					else {
						printf("��������...");
						break;
					}
				}
				else {
					printf("down\n");
					N++;
				}
			}
		}
		else if (answer < randomNumber) {
			Hint[N - 1] = answer;

			if (N > 1 && N <= 5) {
				if (Hint[N - 2] > Hint[N - 1]) {
					printf("\n");
					printf("2.��Ģ����!!!\n");
					printf("���?(y/n):");
					scanf_s(" %c", &op, sizeof(op));


					if (op == 'y') {
						N = 1;
						Random();
						continue;
					}
					else {
						printf("��������...");
						break;
					}
				}
			}
			else if (N > 1 && N <= 5) {
				if (Hint[N - 2] = Hint[N - 1]) {
					printf("\n");
					printf("5.��Ģ����!!!\n");
					printf("���?(y/n):");
					scanf_s(" %c", &op, sizeof(op));


					if (op == 'y') {
						N = 1;
						Random();
						continue;
					}
					else {
						printf("��������...");
						break;
					}
				}
			}
			else {
				printf("up\n");
				N++;
			}
		}



		else {
			printf("\n");
			printf("3.��Ģ����!!!\n");
			printf("���?(y/n):");
			scanf_s(" %c", &op, sizeof(op));


			if (op == 'y') {
				N = 1;
				Random();
				continue;
			}
			else {
				printf("��������...");
				break;
			}
		}

		if (N >= 6) {
			printf("%d��° ���� �Է�:\n", N);
			printf("\n");
			printf("4.��Ģ����!!!\n");
			printf("���?(y/n):");
			scanf_s(" %c", &op, sizeof(op));


			if (op == 'y') {
				N = 1;
				Random();
				continue;
			}
			else {
				printf("��������...");
				break;
			}

		}





	} while (1);


}

int main() {

	printf("up down  ���� ����\n");
	game();
	return 0;
}