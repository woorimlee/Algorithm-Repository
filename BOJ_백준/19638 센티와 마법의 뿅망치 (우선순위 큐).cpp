#include <iostream>
#include <vector>
#include <queue>
#define INF 1234567890

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, centi, T;
    cin >> N >> centi >> T;

    priority_queue <int> giant;

    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        giant.push(temp);
    }

    for (int i = 0; i < T + 1; i++) {
        int tallest = giant.top();
        if (tallest < centi) { // 답찾고 바로 끝
            cout << "YES\n" << i << "\n";
            return 0;
        }
        else if (i < T && tallest > 1) {
            giant.pop();
            giant.push(tallest / 2);
        }
    }

    cout << "NO\n" << giant.top() << "\n";
    return 0;
}