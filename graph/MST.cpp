#include <cstdio>
#include <algorithm>

using namespace std;

#define N 101
int Tree[N];

int findroot(int x) {
    if(Tree[x] == -1) return x;
    else {
        int tmp = findroot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

struct Edge{
    int a, b;
    int cost;
    bool operator < (const Edge &A) const {
        return cost < A.cost;
    }
} edge[6000];

int main(void) {
    int n;
    while(scanf("%d", &n)) {
        for (int i = 1; i <= n * (n - 1) / 2; i++) {
            scanf("%d %d %d", &edge[i].a, &edge[i].b, &edge[i].cost);
        }
        sort(edge + 1, edge + n * (n - 1) / 2 + 1);
        for (int i = 1; i <= n; i++) {
            Tree[i] = -1;
        }
        int ans = 0;
        for (int i = 1; i <= n * (n - 1) / 2; i++) {
            int a = findroot(edge[i].a);
            int b = findroot(edge[i].b);
            if(a != b){
                Tree[a] = b;
                ans += edge[i].cost;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
