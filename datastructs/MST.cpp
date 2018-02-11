// Mininum Spanning Tree
//

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Edge {
    int a, b;
    int cost;
};

int findRoot(int *S, int e) {
    if (S[e] == -1) {
        return e;
    } else {
        S[e] = findRoot(S, S[e]);
        return S[e];
    }
}

bool cmp(Edge e1, Edge e2) {
    return e1.cost < e2.cost;
}

int main(void) {
    int n;
    while (scanf("%d", &n) != EOF && n) {
        Edge edge[5000];
        for (int i = 0; i < n * (n - 1) / 2; i++) {
            scanf("%d %d %d", &edge[i].a, &edge[i].b, &edge[i].cost);
        }
        int uSet[110];
        for (int i = 1; i <= n; i++) {
            uSet[i] = -1;
        }
        sort(edge, edge + n * (n - 1) / 2, cmp);
        int ans = 0;
        for (int i = 0; i < n * (n - 1) / 2; i++) {
            int a = findRoot(uSet, edge[i].a);
            int b = findRoot(uSet, edge[i].b);
            if (a != b) {
                uSet[a] = b;
                ans += edge[i].cost;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
