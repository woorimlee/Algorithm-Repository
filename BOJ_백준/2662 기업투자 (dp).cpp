#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 300 + 1;

int N, M;

int company[MAX][20 + 1]; // 투자 액수와 회사 번호는 1부터 시작
int invested[MAX][20 + 1]; // 투자 결과 출력용
int cache[MAX][20 + 1];

// money : 투자 금액, compNum : 투자한 회사
// invest(money, compNum) : money만큼 compNum에 투자했을 때 얻을 수 있는 최대 이익을 return
int invest(int money, int compNum) { 
    if (compNum > M)
        return 0;

    int& ret = cache[money][compNum];
    if (ret != -1)
        return ret;

    ret = 0;

    int bestCase = 0; // 투자 결과 저장용
    for (int i = 0; i <= money; i++) {
        int profit = company[i][compNum] + invest(money - i, compNum + 1); // 다음 회사 선택

        if (profit > ret) { // 최대 이익금 갱신
            ret = profit;
            bestCase = i; // i 금액만큼 투자함
        }
    }

    // money 자본금으로 compNum 회사에 i 금액만큼 투자함
    invested[money][compNum] = bestCase; 
    return ret;
}

void invest_record() {
    int total = N;
    for (int i = 1; i <= M; i++)
    {
        cout << invested[total][i] << " ";
        total -= invested[total][i];
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    int invest_money, comp_profit;
    for (int i = 0; i < N; i++) {
        cin >> invest_money;
        for (int j = 1; j <= M; j++) {
            cin >> comp_profit;
            company[invest_money][j] = comp_profit;
        }
    }
    
    fill(&cache[0][0], &cache[MAX - 1][20 + 1], -1);
    cout << invest(N, 1) << "\n";
    invest_record();
}