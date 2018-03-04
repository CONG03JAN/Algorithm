#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main(void) {
    int num1, num2;
    while (~scanf("%d %d", &num1, &num2)) {
        int ans[3];
        bool flag;
        int cnt = 0;
        int n = num1 + num2;
        n < 0? flag = true: flag = false;
        n = abs(n);
        while (n >= 1000) {
            ans[cnt++] = n % 1000;
            n /= 1000;
        }
        printf(flag? "-": "");
        printf("%d", n);
        for (int i = cnt - 1; i >= 0; i--) {
            printf(",%03d", ans[i]);
        }
        printf("\n");

    }
    return 0;
}
