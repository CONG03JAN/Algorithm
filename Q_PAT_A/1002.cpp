#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
    int n;
    while (~scanf("%d", &n)) {
        double num1[1010] = {0};
        double num2[1010] = {0};
        int mark[1010] = {0};
        double a;
        int b;
        for (int i = 0; i < n; i++) {
            scanf("%d %lf", &b, &a);
            num1[b] = a;
        }
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %lf", &b, &a);
            num2[b] = a;
        }
        for (int i = 0; i < 1001; i++) {
            num1[i] += num2[i];
        }
        int cnt = 0;
        for (int i = 0; i < 1001; i++) {
            if(num1[i] != 0) {
                mark[cnt++] = i;
            }
        }
        printf("%d", cnt);
        for (int i = cnt - 1; i >= 0; i--) {
            printf("% d %.1lf", mark[i], num1[mark[i]]);
        }
        printf("\n");


    }
    return 0;
}
