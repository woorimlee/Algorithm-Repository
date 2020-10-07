#include <iostream>
#include <string>
#include <vector>
using namespace::std;

int k;
int T;
vector <string> s;

string palindrome(string added_s) {
    for (int i = 0; i * 2 < added_s.size(); i++)
        if (added_s[i] != added_s[added_s.size() - i - 1])
            return "";
    return added_s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T--) {
        s.clear();
        cin >> k;
        string temp;
        string ans = "";
        for (int i = 0; i < k; i++) {
            cin >> temp;
            s.push_back(temp);
        }
        for (int i = 0; i < k && ans.empty(); i++) {
            for (int j = 0; j < k && ans.empty(); j++) {
                if (i != j) {
                    ans = palindrome(s[i] + s[j]);
                }
            }
        }
        if (!ans.empty()) 
            cout << ans << "\n";
        else 
            cout << 0 << "\n";
    }

    return 0;
}
