#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int max_width = (brown + yellow) / 2; //���簢��
    int carpet = brown + yellow;
    for (int i = 3; i <= max_width; i++) { //���� ����
        if (carpet % i == 0) { //���μ� ���� ����
            int width = i;
            int height = carpet / i;
            if (width >= height) { //���� >= ����
                int cal_yel = (width - 2) * (height - 2);
                //brown�� yellow ���� ���μ����ص� ������ ����� ���� ���ٸ�
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