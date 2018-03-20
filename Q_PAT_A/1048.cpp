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
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        int coin[100005] = {0};
        int tmp;
        for (int i = 0; i < n; i++) {
            scanf("%d", &tmp);
            coin[tmp]++;
        }
        bool flag = false;
        for (int i = 0; i < 501; i++) {
            if (coin[i] > 0) {
                coin[i]--;
                if (m - i > 0 && coin[m - i] > 0) {
                    printf("%d %d\n", i, m - i);
                    flag = true;
                    break;
                }
            }
        }
        if (flag == false) {
            printf("No Solution\n");
        }
    }
    return 0;
}
