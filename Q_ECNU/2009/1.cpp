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

struct Edge {
    int a, b;
    int cost;
}E[15010];

int Tree[1010];

int findRoot(int x) {
    if (Tree[x] == -1) return x;
    else {
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

bool Cmp(Edge a, Edge b) {
    return a.cost < b.cost;
}

int main() {
    int n;
    int m;
    int i;
    while (scanf("%d", &n) != EOF) {
        scanf("%d", &m);
        for (int i = 1; i <= m; i++) {
            scanf("%d %d %d", &E[i].a, &E[i].b, &E[i].cost);
        }
        sort(E + 1, E + 1 + m, Cmp);
        for (int i = 1; i <= m; i++) {
            Tree[i] = -1;
        }
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            int a = findRoot(E[i].a);
            int b = findRoot(E[i].b);
            if (a != b) {
                Tree[a] = b;
                ans += E[i].cost;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
