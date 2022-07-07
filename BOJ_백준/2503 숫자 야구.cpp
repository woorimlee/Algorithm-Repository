#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// ���� ����
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
        // N �� for���� �����鼭 �Ұ����� ������ false�� �ٲ۴�.
        cin >> number >> s >> b;
        for (int j = 123; j <= 987; j++) {
            if (ans_comb[j]) {
                number_1st = to_string(number);
                number_2nd = to_string(j);
                s_cnt = 0;
                b_cnt = 0;

                // ball�� strike ������ ��츦 �˻�
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        if (x == y && number_1st[x] == number_2nd[y])
                            s_cnt++;
                        if (x != y && number_1st[x] == number_2nd[y])
                            b_cnt++;
                    }
                }

                // �ȵǴ� ��� ����
                if (s_cnt != s || b_cnt != b)
                    ans_comb[j] = false;
            }
        }
    }

    // �Ұ����Ѱ� �� ã���� true ������ ã�Ƽ� ������ ����Ѵ�.
    int ans = 0;
    for (int i = 123; i <= 987; i++)
        if (ans_comb[i])
            ans++;
    cout << ans;
    return 0;
}
