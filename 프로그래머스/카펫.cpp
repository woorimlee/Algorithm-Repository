#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int max_width = (brown + yellow) / 2; //정사각형
    int carpet = brown + yellow;
    for (int i = 3; i <= max_width; i++) { //가로 길이
        if (carpet % i == 0) { //소인수 분해 가능
            int width = i;
            int height = carpet / i;
            if (width >= height) { //가로 >= 세로
                int cal_yel = (width - 2) * (height - 2);
                //brown과 yellow 값이 소인수분해된 값으로 계산한 값과 같다면
                if ( (cal_yel == yellow) && ((carpet - cal_yel) == brown)) {
                    answer.push_back(width);
                    answer.push_back(height);
                    return answer;
                }
            }
        }
    }
}

int main() {
    vector<int> ans = solution(10, 2);
    cout << ans[0] << " " << ans[1];
    return 0;
}