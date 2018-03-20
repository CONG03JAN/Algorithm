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

int main(void) {
    int n;
    scanf("%d", &n);
    int fav[222] = {0};
    int m;
    scanf("%d", &m);
    int k = 0;
    int tmp;
    for (int i = 1; i <= m; i++) {
        scanf("%d", &tmp);
        fav[tmp] = i;
    }
    int dp[10010] = {0};
    int l;
    scanf("%d", &l);
    int color[10010];
    k = 0;
    for (int i = 0; i < l; i++) {
        scanf("%d", &tmp);
        if (fav[tmp] > 0) {
            color[k++] = tmp;
        }
    }
    int maxn = 0;
    for (int i = 0; i < k; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (fav[color[i]] >= fav[color[j]]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxn = max(dp[i], maxn);
    }
    cout << maxn << endl;
    return 0;
}
