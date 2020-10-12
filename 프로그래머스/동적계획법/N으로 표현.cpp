#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

int getNN(int N, int idx) {
    int result = N;
    for (int i = 1; i <= idx; i++) {
        result = result * 10 + N;
    }
    return result;
}

int solution(int N, int number) {
    if (N == number)
        return 1;

    vector<unordered_set<int> > cache(8);
    cache[0].insert(N);

    for (int i = 1; i < 8; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < i; k++) {
                if (j + k + 1 != i) continue;
                for (int it1 : cache[j]) {
                    for (int it2 : cache[k]) {
                        cache[i].insert(it1 + it2);
                        if (it1 - it2 > 0) {
                            cache[i].insert(it1 - it2);
                        }
                        if (it1 != 0 && it2 != 0) {
                            cache[i].insert(it1 * it2);
                            cache[i].insert(it1 / it2);
                        }
                    }
                }
            }
        }
        cache[i].insert(getNN(N, i));
        if (cache[i].count(number))
            return i + 1;
    }
    return -1;
}

int main() {
    //cout << solution(6, 65) << "\n";
    cout << solution(5, 4) << "\n";
    return 0;
}