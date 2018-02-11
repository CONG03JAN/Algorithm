// 畅通工程

#include <iostream>
#include <cstdlib>

using namespace std;

int findRoot(int *S, int e) {
    if (S[e] == -1) {
        return e;
    } else {
        int tmp = findRoot(S, S[e]);
        S[e] = tmp;
        return tmp;
    }
}

int main(void) {
    int n, m;
    while (scanf("%d", &n) != EOF && n != 0) {
        scanf("%d", &m);
        int uSet[1010] = {0};
        int a, b;
        for (int i = 1; i <= n; i++) {
            uSet[i] = -1;
        }
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            a = findRoot(uSet, a);
            b = findRoot(uSet, b);
            if (a != b) {
                uSet[a] = b;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (uSet[i] == -1) {
                ans++;
            }
        }
        //for (int i = 1; i <= n; i++) {
            //cout << i << "->" << uSet[i] << endl;
        //}
        printf("%d\n", ans - 1);
    }
    return 0;
}
