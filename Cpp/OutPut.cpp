#include <cstdio>

int main(void) {
    int outPutBuf[82][82];
    char a, b;
    int n;
    while (scanf("%d %c %c", &n, &a, &b) == 3) {
        for(int i = 1, j = 1; i <= n; i += 2, j++) {
            int x = n / 2 + 1, y = x;
             x -= j - 1; y -= j - 1;
                 char c = j % 2 == 1? a: b;
             for(int k = 1; k <= i; k++) {
                 outPutBuf[x + k - 1][y] = c;
                 outPutBuf[x][y + k - 1] = c;
                 outPutBuf[x + i - 1][y + k - 1] = c;
                 outPutBuf[x + k - 1][y + i - 1] = c;
             }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                printf("%c", outPutBuf[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
