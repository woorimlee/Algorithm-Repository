#include<iostream>
#include<vector>

#define MOD 987654321

using namespace std; 
typedef long long ll;

int main() {
    int N;
    cin >> N;
    // 카탈란 수열 기준 N = 3일때 값이 5
    // 미팅의 저주에선 N을 2로 나눠줘야 수열 적용 가능
    N = N / 2;

    vector <ll> cache(N + 1);
    cache[0] = cache[1] = 1;

    for (int i = 2; i <= N; i++) {
        // 점화식 : cn+1=c0cn+c1cn−1+⋯+cnc0 
        // (n+2)cn+1+(−4n−2)cn=0
        for (int j = 0; j < i; j++) {
            // c2 = c0c1 + c1c0
            // c3 = c0c2 + c1c1 + c2c0
            cache[i] = (cache[i] + 1LL * cache[j] * cache[i - j - 1]) % MOD;
        }
    }

    cout << cache[N];

    return 0;
}