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
    char orign[22];
    while (scanf("%s", orign) != EOF) {
        int mark[10] = {0};
        int len = strlen(orign);
        for (int i = 0; i < len; i++) {
            mark[orign[i] - '0']++;
        }
        char ans[22];
        int cnt = 0;
        int tmp;
        int flag = 0;
        for (int i = len - 1; i >= 0; i--) {
            tmp = (orign[i] - '0') * 2;
            ans[cnt++] = (tmp + flag) % 10 + '0';
            flag = (tmp + flag) / 10;
        }
        if (flag != 0) {
            ans[cnt++] = '1';
        }
        if(cnt != len) {
            printf("No\n");
            for (int i = cnt - 1; i >= 0 ; i--) {
                printf("%c", ans[i]);
            }
            printf("\n");
            continue;
        }
        for (int i = cnt - 1; i >= 0; i--) {
            mark[ans[i] - '0']--;
        }
        bool isOk = true;
        for (int i = 0; i < 10; i++) {
            if (mark[i] != 0) {
                printf("No\n");
                isOk = false;
                break;
            }
        }
        if (isOk) {
            printf("Yes\n");
        }
        for (int i = cnt - 1; i >= 0 ; i--) {
            printf("%c", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
