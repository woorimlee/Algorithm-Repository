#include <iostream>
#include <stack>
using namespace std;

int main() {
    int max = 0, n, m, cnt = 0;
    stack <int> st;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        st.push(m);
    }
    while (st.size())
    {
        if (max < st.top())
        {
            max = st.top();
            cnt++;
        }
        st.pop();
    }
    cout << cnt;
    return 0;
}