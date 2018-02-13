#include "iostream"
#include "cstdio"

using namespace std;

int main(void) {
    int n;
    while (scanf("%d", &n), n) {
        int a1[6];
        int a2[6];
        for (int i = 0; i < 6; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < 6; i++) {
            cin >> a2[i];
        }
        int ans[4] = {0};
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                ans[(a1[i] + a2[j]) % n]++;
            }
        }
        bool mark = true;
        for (int i = 1; i < n; i++) {
            if (ans[i] != ans[i - 1]) {
                mark = false;
            }
        }
        printf(mark == true? "YES\n": "No\n");
    }
    return 0;
}
