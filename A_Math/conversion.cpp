// 十进制转化为m进制

#include "iostream"

using namespace std;

int main(void) {
    long long int num;
    int n;
    while (~scanf("%lld", &num)) {
        scanf("%d", &n);
        int ans[50];
        int cnt = 0;
        do {
            ans[cnt++] = num % n;
            num /= n;
        } while(num != 0);
        for (int i = cnt - 1; i >= 0; i--) {
              cout << ans[i];
        }
        cout << endl;
    }

    return 0;
}
