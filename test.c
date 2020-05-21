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

		printf("%d번째 숫자 입력:", N);
		scanf_s("%d", &answer);

		if (answer > randomNumber) {
			Hint[N - 1] = answer;
			
			if (N > 1 && N <= 5) {
				if (Hint[N - 2] < Hint[N - 1] && N>1) {
					printf("\n");
					printf("1.벌칙수행!!!\n");
					printf("계속?(y/n):");
					scanf_s(" %c", &op, sizeof(op));

					if (op == 'y') {
						N = 1;
						Random();
						continue;
					}
					else {
						printf("게임종료...");
						break;
					}
				}
				else if (Hint[N - 2] = Hint[N - 1] && N > 1 && N <= 5) {
					printf("\n");
					printf("5.벌칙수행!!!\n");
					printf("계속?(y/n):");
					scanf_s(" %c", &op, sizeof(op));
					if (op == 'y') {
						N = 1;
						Random();
						continue;
					}
					else {
						printf("게임종료...");
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
					printf("2.벌칙수행!!!\n");
					printf("계속?(y/n):");
					scanf_s(" %c", &op, sizeof(op));


					if (op == 'y') {
						N = 1;
						Random();
						continue;
					}
					else {
						printf("게임종료...");
						break;
					}
				}
			}
			else if (N > 1 && N <= 5) {
				if (Hint[N - 2] = Hint[N - 1]) {
					printf("\n");
					printf("5.벌칙수행!!!\n");
					printf("계속?(y/n):");
					scanf_s(" %c", &op, sizeof(op));


					if (op == 'y') {
						N = 1;
						Random();
						continue;
					}
					else {
						printf("게임종료...");
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
			printf("3.벌칙수행!!!\n");
			printf("계속?(y/n):");
			scanf_s(" %c", &op, sizeof(op));


			if (op == 'y') {
				N = 1;
				Random();
				continue;
			}
			else {
				printf("게임종료...");
				break;
			}
		}

		if (N >= 6) {
			printf("%d번째 숫자 입력:\n", N);
			printf("\n");
			printf("4.벌칙수행!!!\n");
			printf("계속?(y/n):");
			scanf_s(" %c", &op, sizeof(op));


			if (op == 'y') {
				N = 1;
				Random();
				continue;
			}
			else {
				printf("게임종료...");
				break;
			}

		}





	} while (1);


}

int main() {

	printf("up down  게임 시작\n");
	game();
	return 0;
}