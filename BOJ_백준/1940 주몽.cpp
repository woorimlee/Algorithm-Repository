#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, ans = 0;
    cin >> N >> M;

    vector <int> material(N, 0);
    for (int& it : material)
        cin >> it;

    for (int i = 0; i < N - 1; i++)
        for (int j = i + 1; j < N; j++)
            if (material[i] + material[j] == M)
                ans++;

    cout << ans;
    return 0;
}