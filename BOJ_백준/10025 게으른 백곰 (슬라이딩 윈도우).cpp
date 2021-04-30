#include <iostream>
using namespace std;

int arr[1000001] = { 0, };
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N, K, g, x;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> g >> x;
        arr[x] = g;
    }

    K = 2 * K + 1;
    int ans = 0, sum = 0;
    for (int i = 0; i <= 1000000; i++) {
        if (i >= K) 
            sum -= arr[i - K];
        sum += arr[i];

        ans = ans > sum ? ans : sum;
    }

    cout << ans << "\n";
    return 0;
}
