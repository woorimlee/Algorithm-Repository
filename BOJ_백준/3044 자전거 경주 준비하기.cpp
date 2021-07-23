#include <iostream>
#include <vector>

using namespace std;

class item {
public:
    int A, B;
    item();
    item(int A, int B) : A(A), B(B) {};
};

int N, M;
vector<item> way;
int map[10001][10001];
int visited[10001];

int result = -1;

void DFS(int current) {
    if (current == 2) {
        result++;
        return;
    }

    if (visited[current]) {
        cout << "inf" << endl;
        return;
    }

    for (int next = 1; next <= N; next++) {
        if (visited[next]) continue;
        if (!map[current][next]) continue;
        visited[next] = true;
        DFS(next);
        visited[next] = false;
    }

}

void solution() {
    DFS(1);
}

int main() {
    cin >> N >> M;
    int A, B;
    for (int m = 1; m <= M; m++) {
        cin >> A >> B;
        item input(A, B);
        way.push_back(input);
        map[A][B] = true;
    }

    solution();
    if (result != -1) cout << result + 1 << endl;


    return 0;
}