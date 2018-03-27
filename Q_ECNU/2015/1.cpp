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
    int n;
    while (scanf("%d", &n) != EOF) {
        int a[100], maxhigh = 0, b[100];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            b[n - 1 - i] = a[i];
            if (a[i] > maxhigh) {
                maxhigh = a[i];
            }
        }
        int startA, startB;
        for (int i = 0; i < n; i++) {
            if (a[i] > maxhigh / 2) {
                startA = i;
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (b[i] > maxhigh / 2) {
                startB = i;
                break;
            }
        }
        int ans = 0;

    }
    return 0;
}
