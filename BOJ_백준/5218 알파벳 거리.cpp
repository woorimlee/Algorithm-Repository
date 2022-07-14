#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    string a, b;
    cin >> T;

    while (T--) {
        cin >> a >> b;
        vector <int> arr(a.size(), 0);
        for (int i = 0; i < a.size(); i++)
        {
            if (b[i] >= a[i])
                arr[i] = b[i] - a[i];
            else if (b[i] < a[i])
                arr[i] = b[i] + 26 - a[i];
        }
        cout << "Distances: ";
        for (int i = 0; i < a.size(); i++)
            cout << arr[i] << ' ';
        cout << "\n";
    }
}