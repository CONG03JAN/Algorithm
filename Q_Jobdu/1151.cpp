#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b;
        scanf("%d %d", &a, &b);
        bool flag = true;
        for (int i = 0; i < 16; i++) {
            int c = (a >> (16 - i)) | (a << i);
            c &= 0xFFFF;
            if (c == b) {
                flag = false;
                printf("YES\n");
                break;
            }
        }
        if (flag) {
            printf("NO\n");
        }
    }
    return 0;
}
