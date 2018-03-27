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

char str[10010];
int num[5010];
int main() {
    int T;
    int n;
    int i;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        getchar();
        gets(str);
        int l = strlen(str);
        int cn = 0;
        int k = 0;
        i = 0;
        while (i < l) {
            if (str[i] == '.' || str[i] == '?' || str[i] == '!') {
                cn++;
                i+=2;
                num[k] = cn;
                k++;
                cn = 0;
            } else {
                cn++;
                i++;
            }
        }
        int flag = 1;
        for (int i = 0; i < k; i++) {
            if (num[i] > n) {
                flag = 0;
                break;
            }
        }
        if (flag == 0) {
            printf("Impossible\n");
        } else {
            int h = 1;
            int sum = 0;
            for (int i = 0; i < k; i++) {
                if (sum + num[i] <= n) {
                    sum += num[i];
                } else {
                    h++;
                    sum = num[i];
                }
            }
            printf("%d\n", h);
        }
    }
    return 0;
}

