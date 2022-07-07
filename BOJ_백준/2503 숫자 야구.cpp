#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 질문 갯수
int N;
bool ans_comb[999];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    fill(ans_comb, &ans_comb[998 + 1], true);
    string temp;
    for (int i = 123; i <= 987; i++) {
        temp = to_string(i);
        if (temp[0] == '0' || temp[1] == '0' || temp[2] == '0')
            ans_comb[i] = false;

        if (temp[0] == temp[1] || temp[1] == temp[2] || temp[2] == temp[0])
            ans_comb[i] = false;
    }

    int number, s, b, s_cnt, b_cnt;
    string number_1st, number_2nd;
    for (int i = 0; i < N; i++) {
        // N 번 for구문 돌리면서 불가능한 정답을 false로 바꾼다.
        cin >> number >> s >> b;
        for (int j = 123; j <= 987; j++) {
            if (ans_comb[j]) {
                number_1st = to_string(number);
                number_2nd = to_string(j);
                s_cnt = 0;
                b_cnt = 0;

                // ball과 strike 가능한 경우를 검사
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        if (x == y && number_1st[x] == number_2nd[y])
                            s_cnt++;
                        if (x != y && number_1st[x] == number_2nd[y])
                            b_cnt++;
                    }
                }

                // 안되는 경우 제거
                if (s_cnt != s || b_cnt != b)
                    ans_comb[j] = false;
            }
        }
    }

    // 불가능한거 다 찾고나면 true 갯수만 찾아서 정답을 출력한다.
    int ans = 0;
    for (int i = 123; i <= 987; i++)
        if (ans_comb[i])
            ans++;
    cout << ans;
    return 0;
}
