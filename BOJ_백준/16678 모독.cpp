#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 0, pivot = 1;
    long long ans = 0;

    cin >> N;
    vector <int> mp (N, 0);
    for (int i = 0; i < N; i++)
        cin >> mp[i];

    sort(mp.begin(), mp.end());

    for (int i = 0; i < N; i++) {
        if (mp[i] >= pivot) {
            ans += mp[i] - pivot;
            pivot++;
        }
    }
    cout << ans;

    return 0;
}