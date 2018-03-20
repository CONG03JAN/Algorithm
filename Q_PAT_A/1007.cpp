#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

int seq[10010];

int main(void) {
    int n;
    while (~scanf("%d", &n) && n) {
        for (int i = 0; i < n; i++) {
            scanf("%d", seq + i);
        }
        int dp[10010] = {0};
        dp[0] = seq[0];
        int max = dp[0];
        int a = 0, b = 0;
        for (int i = 1; i < n; i++) {
            if (dp[i - 1] >= 0) {
                dp[i] = dp[i - 1] + seq[i];
                if (dp[i] > max) {
                    max = dp[i];
                    if (seq[i] != 0) {
                        b = i;
                    }
                }
            } else {
                dp[i] = seq[i];
                if (dp[i] > max) {
                    max = dp[i];
                    a = i;
                    b = i;
                }
            }
        }
        if (max < 0) {
            printf("0 %d %d\n", seq[0], seq[n - 1]);
        } else {
            printf("%d %d %d\n",max ,seq[a], seq[b]);
        }

    }
    return 0;
}
