#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
    int k;
    scanf("%d", &k);
    int list[381] = {0};
    for (int i = 0; i < k; i++) {
        int tmp;
        scanf("%d", &tmp);
        list[tmp] = 1;
    }
    for (int i = 2; i <= 100; i++) {
        if (list[i] == 1) {
            int tmp = i;
            while(tmp != 1) {
                if (tmp % 2 == 0) {
                    tmp /= 2;
                } else {
                    tmp = (3 * tmp + 1) / 2;
                }
                list[tmp] = 0;
            }
        }
    }
    int ansN = 0;
    int ans[381];
    for (int i = 2; i < 161; i++) {
        if (list[i] == 1) {
            ans[ansN++] = i;
        }
    }
    for (int i = ansN - 1; i > 0 ; i--) {
        printf("%d ", ans[i]);
    }
    printf("%d\n", ans[0]);

    return 0;
}
