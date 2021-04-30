#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int N, num;
    stack <int> st;
    queue <int> que;
    cin >> N;
    while (N--) {
        cin >> num;
        que.push(num);
    }

    int i = 1;
    while (!que.empty()) {
        if (que.front() == i) {
            i++;
            que.pop();
        }
        else {
            st.push(que.front());
            que.pop();
        }
        while (!st.empty() && st.top() == i) {
            st.pop();
            i++;
        }
    }

    if (st.empty())
        cout << "Nice";
    else
        cout << "Sad";
    
    return 0;
}