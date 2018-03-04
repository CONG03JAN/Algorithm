#include <iostream>
#include <cstdio>
using namespace std;

char s[3] = {'A', 'S', 'B'};

int main(void) {
    int num;
    while (~scanf("%d", &num) && num) {
        int ans[3];
        int len = 0;
        while (num != 0) {
            ans[len++] = num % 10;
            num /= 10;
        }

        for (int i = len - 1; i > 0; i--) {
            for (int j = 1; j <= ans[i] ; j++) {
                printf("%c", s[i]);
            }
        }
        for (int i = 1; i <= ans[0]; i++) {
            printf("%d", i);
        }
        printf("\n");

    }
    return 0;
}
