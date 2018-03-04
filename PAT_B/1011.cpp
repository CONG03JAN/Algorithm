#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int step = 1;
    while (step <= n) {
        long long int a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        printf("Case #%d: ", step);
        step++;
        printf(a + b > c? "true\n": "false\n");
    }
    return 0;
}
