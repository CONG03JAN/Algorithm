// Topological Sorting
//

#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>

using namespace std;

int main(void) {
    int n, m;
    vector<int> edge[501];
    queue<int> q;
    int inDegree[501];

    while (scanf("%d %d", &n, &m) && n && m) {
        for (int i = 0; i < m; i++) {
            edge[i].clear();
            inDegree[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            edge[a].push_back(b);
            inDegree[b]++;
        }
        while (q.empty() == false) q.pop();
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) q.push(i);
        }
        int cnt = 0;
        while (q.empty() == false) {
            int nowP = q.front();
            q.pop();
            cnt++;
            for (int i = 0; i < edge[nowP].size(); i++) {
                int tmp = --inDegree[edge[nowP][i]];
                if (tmp == 0) {
                    q.push(edge[nowP][i]);
                }
            }
        }
        if(cnt == n) puts("YES");
        else puts("NO");
    }
    return 0;
}
