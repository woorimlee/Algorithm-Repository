#include <iostream>
#include <deque>

using namespace std;

int main() {
    int T, N;
    cin >> T;

    while(T--) {
        cin >> N;
        deque <char> card(N);
        deque <char> que;
        for (auto& i : card)
            cin >> i;

        que.push_front(card.front());
        card.pop_front();

        while (!card.empty()) {
            char c = card.front();
            card.pop_front();
            if (c - 'A' <= que.front() - 'A')
                que.push_front(c);
            else
                que.push_back(c);
        }

        for (char i : que)
            cout << i;
        cout << "\n";
    }

    return 0;
}