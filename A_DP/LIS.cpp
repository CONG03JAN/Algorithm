#include <iostream>
#include <cstdio>

using namespace std;

int max(int a, int b){
    return a > b? a: b;
}

int main(void) {
    int n;
    while (~scanf("%d", &n) && n) {
        int dp[30];
        int list[30];
        for (int i = 0; i < n; i++) {
            scanf("%d", list + i);
        }
        for (int i = 0; i < n; i++) {
            int tmax = 1;
            for (int j = 0; j < i; j++) {
                if (list[j] >= list[i]) {
                    tmax = max(tmax, dp[j] + 1);
                }
            }
            dp[i] = tmax;
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
