#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 300 + 1;

int N, M;

int company[MAX][20 + 1]; // ���� �׼��� ȸ�� ��ȣ�� 1���� ����
int invested[MAX][20 + 1]; // ���� ��� ��¿�
int cache[MAX][20 + 1];

// money : ���� �ݾ�, compNum : ������ ȸ��
// invest(money, compNum) : money��ŭ compNum�� �������� �� ���� �� �ִ� �ִ� ������ return
int invest(int money, int compNum) { 
    if (compNum > M)
        return 0;

    int& ret = cache[money][compNum];
    if (ret != -1)
        return ret;

    ret = 0;

    int bestCase = 0; // ���� ��� �����
    for (int i = 0; i <= money; i++) {
        int profit = company[i][compNum] + invest(money - i, compNum + 1); // ���� ȸ�� ����

        if (profit > ret) { // �ִ� ���ͱ� ����
            ret = profit;
            bestCase = i; // i �ݾ׸�ŭ ������
        }
    }

    // money �ں������� compNum ȸ�翡 i �ݾ׸�ŭ ������
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