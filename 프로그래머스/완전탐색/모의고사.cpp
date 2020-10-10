#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int give_up_1[5] = { 1, 2, 3, 4, 5 };
int give_up_2[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
int give_up_3[10] = { 3,3,1,1,2,2,4,4,5,5 };

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector <pair<int, int> > ans(3, { 0, 0 });

    for (auto it : answers) {
        if (it == give_up_1[ans[0].second])
            ans[0].first++;
        if (it == give_up_2[ans[1].second])
            ans[1].first++;
        if (it == give_up_3[ans[2].second])
            ans[2].first++;
        ans[0].second = (ans[0].second + 1) % 5;
        ans[1].second = (ans[1].second + 1) % 8;
        ans[2].second = (ans[2].second + 1) % 10;
    }

    int max_correct = max(ans[0].first, max(ans[1].first, ans[2].first));
    if (max_correct == ans[0].first)
        answer.push_back(1);
    if (max_correct == ans[1].first)
        answer.push_back(2);
    if (max_correct == ans[2].first)
        answer.push_back(3);

    return answer;
}

int main() {
    vector <int> s = solution(vector<int>() = { 1, 3, 2, 4, 2 });
    for (auto it : s)
        cout << it << " ";
    return 0;
}