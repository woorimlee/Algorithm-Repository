#include<iostream>
#include<vector>

#define INF 1234567890
using namespace std;

int N, M;
int A, B, C;
long long Dist[501];
vector <pair<pair<int, int>, int> > edges;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        edges.push_back({ { A, B }, C });
    }
   
    // 1�� ���ÿ��� �׻� ���
    for (int i = 2; i <= N; i++) 
        Dist[i] = INF;

    for (int i = 1; i <= N - 1; i++) {
        for (int j = 0; j < edges.size(); j++) {
            int from = edges[j].first.first;
            int to = edges[j].first.second;
            int cost = edges[j].second;

            // ��� ���ʿ�
            if (Dist[from] == INF) 
                continue;

            if (Dist[to] > Dist[from] + cost) 
                Dist[to] = Dist[from] + cost;
        }
    }

    // ���� ����Ŭ�� �Ǵ��ϱ� ���ؼ�
    // N-1�� Ž�� ���� �� �� �� ��� �������� Ž���Ѵ�.
    // �̶�, ������Ʈ �Ǵ� ������ �ִٸ�, ���� ����Ŭ�� �ִٴ� ��
    for (int i = 0; i < edges.size(); i++) {
        int from = edges[i].first.first;
        int to = edges[i].first.second;
        int cost = edges[i].second;

        if (Dist[from] == INF) 
            continue;

        if (Dist[to] > Dist[from] + cost) {
            cout << -1 << "\n"; // ���� ����Ŭ : ��ΰ� ����
            return 0;
        }
    }

    for (int i = 2; i <= N; i++) {
        if (Dist[i] == INF) 
            cout << -1 << "\n";
        else 
            cout << Dist[i] << endl;
    }

    return 0;
}
