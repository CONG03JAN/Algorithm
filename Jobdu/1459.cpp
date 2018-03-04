#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int prime[] = {2, 3, 5, 7, 11, 13, 17};
int isPrime[19] = {0};
int visit[20];
int ans[20];

void dfs(int x, int n) {
    if(x == n + 1) {
        if(isPrime[ans[x - 1] + 1] == 1) {
            for (int i = 1; i <= n; i++) {
                printf("%d ", ans[i]);
            }
            printf("\n");
        }
        //return;
    } else {
        for (int i = 2; i <= n; i++) {
            if(visit[i] == 0 && isPrime[i + ans[x - 1]] == 1) {
                visit[i] = 1;
                ans[x] = i;
                dfs(x + 1, n);
                visit[i] = 0;
            }
        }
    }
}

int main(void) {
    int n;
    int caseN = 1;
    for (int i = 0; i < 7; i++) {
        isPrime[prime[i]] = 1;
    }
    while (~scanf("%d", &n) && n) {
        printf("Case: %d\n", caseN);

        memset(visit, 0, sizeof(visit));
        memset(ans, 0, sizeof(ans));

        ans[1] = 1;
        visit[1] = 1;
        dfs(2, n);

        printf("\n");
        caseN++;
    }
    return 0;
}
