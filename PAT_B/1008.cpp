#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
    int n, m;
    while (~scanf("%d %d", &n, &m)) {
        int num[101];
        for (int i = 0; i < n; i++) {
            scanf("%d", num + i);
        }
        m %= n;
        if(m == 0 || m == n) {
            for (int i = 0; i < n; i++) {
                if (i != n - 1) {
                    printf("%d ", num[i]);
                } else {
                    printf("%d\n", num[i]);
                }
            }
            continue;
        }
        int len = n - m;
        for (int i = len; i < n; i++) {
            printf("%d ", num[i]);
        }
        len--;
        for (int i = 0; i < len ; i++) {
            printf("%d ", num[i]);
        }
        printf("%d\n", num[len]);
    }
    return 0;
}
