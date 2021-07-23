#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;
using namespace std;

int prime[] = { 2,3,5,7,11,13,17 };
double perA, perB;
double cache[19][19][19];

double dp(int a, int b, int cnt) {
    if (cnt == 18) {
        for (int i = 0; i < 7; i++) {
            if (a == prime[i] || b == prime[i]) {
                return (double)1.0;
            }
        }
        return 0;
    }

    double& ret = cache[a][b][cnt];
    if (ret != -1.0) {
        return ret;
    }

    double ans = 0;
    ans += (1 - perA) * (1 - perB) * dp(a, b, cnt + 1);
    ans += (1 - perA) * perB * dp(a, b + 1, cnt + 1);
    ans += perA * (1 - perB) * dp(a + 1, b, cnt + 1);
    ans += perA * perB * dp(a + 1, b + 1, cnt + 1);

    return ret = ans;
}

int main()
{
    cin >> perA >> perB;
    perA = perA / 100;
    perB = perB / 100;
    fill(&cache[0][0][0], &cache[18][18][19], (double)-1.0);

    printf("%.6lf", dp(0, 0, 0));
    return 0;
}