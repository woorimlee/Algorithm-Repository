#include <regex>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// P�� �� �ε������� ���̻� == ���λ簡 �Ǵ� ���ڿ� �ִ� ���̸� ���ؼ� ��ȯ
vector <int> getPartialMatch(string P) {
    // ���� ���� ���Ϸ��� ���ڿ� �� ���� ���� ���ϴ� O(P^2)
    // �Ʒ��� �ڵ�� KMP �˰����� ������ ��

    int m = P.size();
    // P�� ���� �Լ� ���� ������ �迭�� 0���� �ʱ�ȭ
    vector <int> ret(m, 0); 
    // begin�� 0���� �ϸ� F(0) = 1�� �Ǿ����
    int begin = 1, matched = 0; 
    while (begin + matched < m) {
        // ã�� ��ġ���� ���� ��ġ
        if (P[begin + matched] == P[matched]) {
            matched++;
            ret[begin + matched - 1] = matched;
        }
        // ���� ����ġ�� ���
        else {
            if (matched == 0)
                begin++;
            else {
                begin += matched - ret[matched - 1];
                matched = ret[matched - 1];
            }
        }
    }
    return ret;
}
   
// S���� ã�� �� �ִ� �κ� ���ڿ� P�� ���� ��ġ�� ��� ��ȯ
vector <int> kmpSearch(string S, string P) { // S�� �� ���ڿ�, P�� �κ� ���ڿ�
    int n = S.size(), m = P.size();
    vector <int> ret;

    vector <int> pi = getPartialMatch(P); // pi = F(k) ���� ������ �迭

    int begin = 0, matched = 0;
    while (begin <= n - m) {
        // ã�� ��ġ���� ���� ��ġ
        if (matched < m && S[begin + matched] == P[matched]) {
            matched++;
            // matched�� ���̰� P.size()�� ��ġ�Ѵٸ� �κ� ���ڿ��� ��� ã��
            if (matched == m)
                ret.push_back(begin);
        }
        // ���� ����ġ�� ���
        else {
            // ���� : matched�� 0�� ��쿡�� ����ĭ���� �˻� ����
            if (matched == 0)
                begin++;
            else {
                // P ���ڿ� ���� ��ġ begin�� ���� �˻� ��ġ�� ����
                begin = begin + (matched - pi[matched - 1]);
                // ���ڿ� �̹� ��ġ�ϴ� �κ� �ǳʶٰ� �˻�
                matched = pi[matched - 1];
            }
        }
    }
    return ret;
}




int main() {
    
    return 0;
}
