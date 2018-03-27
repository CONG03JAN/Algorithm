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

int dp[510][510];
char strA[510];
char strB[510];

int f(int i, int j) {
    if (strA[i - 1] == strB[j - 1]) {
        return 0;
    } else {
        return 1;
    }
}

int mmin(int x, int y) {
    if (x > y) return y;
    else return x;
}

int main(void) {
    int n;
    int i, j;
    scanf("%d", &n);
    getchar();
    while (n--) {
        gets(strA);
        gets(strB);
        int lenA = strlen(strA);
        int lenB = strlen(strB);
        for (i = 1; i <= lenA; i++) {
            dp[i][0] = i;
        }
        for (i = 1; i <= lenB; i++) {
            dp[0][i] = i;
        }
        dp[0][0] = 0;
        for (i = 1; i <= lenA; i++) {
            for (j = 1; j <= lenB; j++) {
                if (strA[i] == strB[j - 1] && strB[j] == strA[i - 1]) {
                    dp[i][j] = min(dp[i - 1][j - 1] + f(i, j), dp[i - 2][j - 2] + 1);
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + f(i, j);
                }
            }
        }
        printf("%d\n", dp[lenA][lenB]);
    }
    return 0;
}
