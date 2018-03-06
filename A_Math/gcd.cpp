#include "iostream"
#include "cstdio"

using namespace std;

int gcd(int a, int b) {
    return b == 0? a: gcd(b, a % b);
}

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    cout << "GCD: " << gcd(a, b) << endl;
    cout << "LCM: " << a * b / gcd(a, b) << endl;
    return 0;
}
