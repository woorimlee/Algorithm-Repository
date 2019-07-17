#include <iostream>
#include <string>
using namespace std;
int N;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	string ** matrix = new string *[N];
	for (int i = 0; i < N; i++)
		matrix[i] = new string[N];


	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> matrix[i][j];

	for (int i = N - 1; i >= 0; i--)
		for (int j = 0; j < N; j++)
			cout << matrix[j][i];

	return 0;
}