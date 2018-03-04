#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxDigits 100

struct bigInteger {
    int digit[maxDigits];
    int size;
    void init() {
        for(int i = 0; i < maxDigits; i++) {
            digit[i] = 0;
        }
        size = 0;
    }

    void set(int x) {
        init();
        do {
            digit[size++] = x % 10000;
            x /= 10000;
        } while(x != 0);
    }

    int operator % (int x) const {
        int remainder = 0;
        for(int i = size - 1; i >= 0; i--) {
            int t = (remainder * 10000 + digit[i]) / x;
            int r = (remainder * 10000 + digit[i]) % x;
            remainder = r;
        }
        return remainder;
    }
};

int main(void) {
    char str[30];
    while(~scanf("%s", str)) {
        bigInteger Integer;
        Integer.set()
    }
    return 0;
}
