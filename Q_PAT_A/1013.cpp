#include <bits/stdc++.h>
#define mem(ar,num) memset(ar,num,sizeof(ar))
#define me(ar) memset(ar,0,sizeof(ar))
#define lowbit(x) (x&(-x))
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int    prime = 999983;
const int    INF = 0x7FFFFFFF;
const LL     INFF =0x7FFFFFFFFFFFFFFF;
const double pi = acos(-1.0);
const double inf = 1e18;
const double eps = 1e-6;
const LL     mod = 1e9 + 7;

int v[1010][1010] = {0};
int ans;
bool visited[1010];

void dfs(int now, int n) {
    visited[now] = true;
    for (int i = 1; i <= n; i++) {
        if (v[now][i] == 1 && visited[i] == false) {
            dfs(i, n);
        }
    }
}

int main(void) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        v[a][b] = 1;
        v[b][a] = 1;
    }
    int city;
    for (int i = 0; i < k; i++) {
        scanf("%d", &city);
        ans = 0;
        for (int x = 1; x <= n; x++) {
            visited[x] = false;
        }
        visited[city] = true;
        for (int y = 1; y <= n; y++) {
            if (visited[y] == false) {
                ans++;
                dfs(y, n);
            }
        }
        printf("%d\n", ans - 1);
    }
    return 0;
}
