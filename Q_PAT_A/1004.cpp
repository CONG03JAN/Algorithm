#include <iostream>
#include <cstdio>
#include <limits>
#include <vector>
#include <algorithm>
using namespace std;

int ans[101];
vector<int> nodes[101];
int maxDepth = -1;

void dfs(int node, int depth) {
    if (nodes[node].empty()) {
        maxDepth = max(depth, maxDepth);
        ans[depth]++;
        return;
    } else {
        int len = nodes[node].size();
        for (int i = 0; i < len; i++) {
            dfs(nodes[node][i], depth + 1);
        }
    }
}

int main(void) {
    int n, m;
    while (scanf("%d %d", &n, &m)!= EOF && n) {
        maxDepth = -1;
        for (int i = 0; i < n; i++) {
            ans[i] = 0;
            nodes[i].clear();
        }
        for (int i = 0; i < m; i++) {
            int node, k;
            int tmp;
            scanf("%d %d", &node, &k);
            for (int j = 0; j < k; j++) {
                scanf("%d", &tmp);
                nodes[node].push_back(tmp);
            }
        }
        dfs(1, 0);
        for (int i = 0; i < maxDepth; i++) {
            printf("%d ", ans[i]);
        }
        printf("%d\n", ans[maxDepth]);
    }

    return 0;
}

