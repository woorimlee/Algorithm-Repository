#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1234567890

int n, m;
// Dist[i][k] + Dist[k][j] �� �� INF���� ���ϸ� 
// �����÷ΰ� �߻��ϱ� ������ long long���� ����
long long Dist[101][101];
int a, b, c;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    // �÷��̵� ���� ���� �� �׷��� �ʱ�ȭ
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                Dist[i][j] = 0;
            else
                Dist[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (Dist[a][b] > c)
            Dist[a][b] = c;
    }

    // �÷��̵� ���� ����
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j || k == i || k == j)
                    continue;
                Dist[i][j] = min(Dist[i][j], (Dist[i][k] + Dist[k][j]));
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (Dist[i][j] == INF)
                cout << 0 << " ";
            else
                cout << Dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
