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
    char s1[10001];
    while (gets(s1)) {
        int s2[200] = {0};
        char c = 0;
        while (c != '\n') {
            s2[c]++;
            c = getchar();
        }
        int len = strlen(s1);
        for (int i = 0; i < len; i++) {
            if (s2[s1[i]] == 0) {
                printf("%c", s1[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
