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
        int dp[10010];
        dp[0] = seq[0];
        int max = seq[0];

    }
    return 0;
}
