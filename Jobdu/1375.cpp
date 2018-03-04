#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

bool list[100009];

int main(void) {
    char s[110];
    int n;
    while (~scanf("%d", &n) && n) {
        int ans = 0;
        memset(list, false, sizeof(list));
        for (int i = 0; i < n; i++) {
            scanf("%s", s);
            if (strlen(s) >= 6) {
                ans++;
                continue;
            }
            int x = atoi(s);
            if (x > 0 && x < 100000) {
                if (list[x] == false) {
                    list[x] = true;
                } else {
                    ans++;
                }
            } else {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

