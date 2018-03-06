#include "iostream"

using namespace std;


long long modexp(long long a, long long b, int mod) {
    long long res = 1;
    while (b > 0) {
        //a=a%mod;
        if (b & 1)
            res = res * a % mod;
        b = b >> 1;
        a = a * a % mod;
    }
    return res;
}

int main(void) {
    int a, b;
    while (1) {
        cin >> a >> b;
        cout << modexp(a, b, 100007) << endl;
    }
    return 0;
}
