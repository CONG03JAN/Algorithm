#include "iostream"
#include "cstring"

using namespace std;

int main(void) {
    int a, b;
    char str[50];
    while (~scanf("%d %s %d", &a, str, &b)) {
        int c = 1;
        int len = strlen(str);
        int tmp = 0;
        char ans[50];
        int size = 0;
        for (int i = len - 1; i >= 0; i--) {
            int x;
            if (str[i] >= '0' && str[i] <= '9') {
                x = str[i] - '0';
            } else if (str[i] >= 'a' && str[i] <= 'f') {
                x = str[i] - 'a' + 10;
            } else {
                x = str[i] - 'A' + 10;
            }
            tmp += (x * c);
            c *= a;
        }
        do {
            int x = tmp % b;
            ans[size++] = (x < 10) ? x + '0': x - 10 + 'A';
            tmp /= b;
        } while(tmp);
        for (int i = size - 1; i >= 0; i--) {
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
