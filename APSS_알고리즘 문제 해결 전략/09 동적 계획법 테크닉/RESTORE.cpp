
int cache[1 << N];
int dfs(int visited) {
    //base case
    if (visited == (1 << N) - 1)
        return 0;

        int& ret = cache[visited];

    for (int i = 0; i < N; i++) {
        if (�湮 ������ ���̸�) {
            int cand = dfs(visited + (1 << i)) + dist ��;
            ret = min(ret, cand)
        }
    }
    return ret;

}