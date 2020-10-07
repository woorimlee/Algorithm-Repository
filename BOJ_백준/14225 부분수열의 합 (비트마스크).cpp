#include <iostream>

#define loop(i, n, m) for(int i = n; i < m; i++)

using namespace std;

int  N, sum;
int seq[20]; //5, 1, 2
bool can_num[20 * 100000 + 1] = { false }; //ÀüºÎ 100,000

int main() {
    cin >> N;
    loop(i, 0, N)
        cin >> seq[i];

    loop(i, 1, (1 << N)) {
        sum = 0;
        loop(j, 0, N) {
            if (i & (1 << j)) {
                sum += seq[j];
            }
        }
        can_num[sum] = true;
    }

    loop(i, 1, 20 * 100000 + 1) {
        if (!can_num[i]) {
            cout << i;
            break;
        }
    }

    return 0;
}