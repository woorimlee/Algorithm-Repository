#include <regex>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// P의 각 인덱스에서 접미사 == 접두사가 되는 문자열 최대 길이를 구해서 반환
vector <int> getPartialMatch(string P) {
    // 가장 쉽게 구하려면 문자열 두 개를 직접 비교하는 O(P^2)
    // 아래의 코드는 KMP 알고리즘을 응용한 것

    int m = P.size();
    // P의 실패 함수 값을 저장할 배열을 0으로 초기화
    vector <int> ret(m, 0); 
    // begin을 0부터 하면 F(0) = 1이 되어버림
    int begin = 1, matched = 0; 
    while (begin + matched < m) {
        // 찾는 위치에서 글자 일치
        if (P[begin + matched] == P[matched]) {
            matched++;
            ret[begin + matched - 1] = matched;
        }
        // 글자 불일치한 경우
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
   
// S에서 찾을 수 있는 부분 문자열 P의 시작 위치를 모두 반환
vector <int> kmpSearch(string S, string P) { // S가 긴 문자열, P는 부분 문자열
    int n = S.size(), m = P.size();
    vector <int> ret;

    vector <int> pi = getPartialMatch(P); // pi = F(k) 값을 저장할 배열

    int begin = 0, matched = 0;
    while (begin <= n - m) {
        // 찾는 위치에서 글자 일치
        if (matched < m && S[begin + matched] == P[matched]) {
            matched++;
            // matched의 길이가 P.size()와 일치한다면 부분 문자열을 모두 찾음
            if (matched == m)
                ret.push_back(begin);
        }
        // 글자 불일치한 경우
        else {
            // 예외 : matched가 0인 경우에는 다음칸부터 검사 시작
            if (matched == 0)
                begin++;
            else {
                // P 문자열 시작 위치 begin을 다음 검사 위치로 갱신
                begin = begin + (matched - pi[matched - 1]);
                // 문자열 이미 일치하는 부분 건너뛰고 검사
                matched = pi[matched - 1];
            }
        }
    }
    return ret;
}




int main() {
    
    return 0;
}
