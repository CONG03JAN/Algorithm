const int len = 60;
const int maxN = 20;
int array[len];
int numArr[maxN];
int visit[maxN];

void dfs(int start, int n) {
    int i, j;

    if (start == n + 1) {
        if (isok(1 + numArr[n]) {
            for (i = 1; i < n; i++) {
                printf("%d ", numArr[i]);
            }
            printf("%d\n", numArr[n]);
        }
        return;
    }
    for (i = 2; i < n + 1; i++) {
        if (visit[i] == 0 && isok(i + numArr[start - 1])) {
            visit[i] = 1;
            numArr[start] = i;
            dfs(start + 1, n);
            visit[i] = 0;
        }
    }
}

int main() {
    int seq = 1;
    while (scanf("%d", &n) != EOF) {
        printf("Case %d:\n", seq);
        memset(numArr, 0, sizeof(numArr));
        memset(visit, 0, sizeof(visit));
        numArr[1] = 1;
        dfs(2, n);
        printf("\n");
        seq++;
    }
    return 0;
}
/**************************************************************
    Problem: 1459
    User: wzqwsrf
    Language: C++
    Result: Accepted
    Time:400 ms
    Memory:1020 kb
****************************************************************/
