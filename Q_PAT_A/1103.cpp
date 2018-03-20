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

int l[400];

void dfs(int nowN, int cnt, int step, int k);

int main(void) {
    int n, k, p;
    while (~scanf("%d %d %d", &n, &k, &p)) {
        int tmp = 0;
        int cnt = 0;
        for (int i = 1; tmp <= n; i++) {
            l[cnt++] = tmp;
            tmp = pow(i, p);
        }

    }
    return 0;
}
