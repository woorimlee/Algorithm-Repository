#include <iostream>
#include <vector>

using namespace std;

int N;
int blue, white;
vector <vector <int> > paper;

void divide(int x1, int y1, int x2, int y2) {
	int cntBlue = 0;
	int cntWhite = 0;
	for (int i = y1; i <= y2; i++) {
		for (int j = x1; j <= x2; j++) {
			if (paper[i][j] == 1)
				cntBlue++;
			else
				cntWhite++;
		}
	}

	if (cntBlue == 0)
		white++;
	else if (cntWhite == 0)
		blue++;
	else {
		divide(x1, y1, (x1 + x2) / 2, (y1 + y2) / 2);
		divide((x1 + x2) / 2 + 1, y1, x2, (y1 + y2) / 2);
		divide(x1, (y1 + y2) / 2 + 1, (x1 + x2) / 2, y2);
		divide((x1 + x2) / 2 + 1, (y1 + y2) / 2 + 1, x2, y2);
	}
	cout << x1 << " " << y1 << " "
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	paper.resize(N);

	int temp;
	for (auto& i : paper)
		for (int j = 0; j < N; j++) {
			cin >> temp;
			i.push_back(temp);
		}

	divide(0, 0, N - 1, N - 1);
	cout << white << '\n' << blue;

	return 0;
}