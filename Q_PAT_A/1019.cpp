#include <iostream>
#include <cstdio>
using namespace std;
int ans[1000000];

int main(void) {
    int n, d;
    while (~scanf("%d %d", &n, &d)) {
        int size = 0;
        do {
            int x = n % d;
            ans[size++] = x;
            n /= d;
        } while(n);
        int x = 0;
        int y = size - 1;
        bool flag = true;
        while (x < y) {
            if (ans[x] == ans[y]) {
                x++;
                y--;
            } else {
                flag = false;
                break;
            }
        }
        printf(flag? "Yes\n": "No\n");
        for (int i = size - 1; i > 0; i--) {
            printf("%d ", ans[i]);
        }
        printf("%d\n", ans[0]);
    }
    return 0;
}
