#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
    char s[90];
    int p[90];
    while (gets(s)) {
        int len = strlen(s);
        int cnt = 1;
        for (int i = 0; i < len; i++) {
            if (s[i] == ' ') {
                p[cnt++] = i;
            }
        }
        p[cnt] = len;
        for (int i = cnt - 1; i > 0; i--) {
            for (int j = p[i] + 1; j < p[i + 1]; j++) {
                printf("%c", s[j]);
            }
            printf(" ");
        }
        for (int i = 0; i < p[1]; i++) {
            printf("%c", s[i]);
        }
        printf("\n");

    }
    return 0;
}
