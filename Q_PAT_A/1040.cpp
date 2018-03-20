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

int main(void) {
    char s[1005];
    gets(s);
    int len = strlen(s);
    int max = 1;
    int dp[1005] = {0};
    dp[0] = 1;
    for (int i = 1; i < len; i++) {
        if (i - dp[i - 1] - 1 >= 0 && s[i] == s[i - dp[i - 1] - 1]) {
            dp[i] = dp[i - 1] + 2;
        } else if (s[i] == s[i - dp[i - 1]]) {
            dp[i] = dp[i - 1] + 1;
        } else {
            dp[i] = 1;
        }
        if (dp[i] > max) {
            max = dp[i];
        }
    }
    cout << max << endl;

    return 0;
}
