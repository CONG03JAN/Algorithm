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

#define MAX 40
char pattern[MAX], str[MAX];

bool DFS(int p, int s) {
    if (pattern[p] == '\0' && str[s] == '\0') {
        return true;
    }
    if (pattern[p] != '*' && pattern[p] != '?') {
        if (pattern[p] == str[s]) {
            return DFS(p + 1, s + 1);
        } else return false;
    } else if (pattern[p] == '?') {
        if (str[s] != '\0') {
            return DFS(p + 1, s + 1);
        } else {
            return false;
        }
    } else {
        for (int i = 0; s + i < MAX; i++) {
            if (DFS(p + 1, s + i)) {
                return true;
            }
        }
        return false;
    }
}

int main(void) {
    while (scanf("%s%s", str, pattern) != EOF) {
        if (DFS(0, 0)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
