#include "iostream"

using namespace std;

#define LL long long

LL Muti(LL A, LL B, LL MOD) {
    LL Ans = 0;
    A = A % MOD;
    B = B % MOD;
    if (B < 0) {
        A = -A;
        B = -B;
    }
    while (B) {
        if (B & 1) Ans = (Ans + A) % MOD;
        B >>= 1;
        A = (A + A) % MOD;
    }
    Ans = (Ans + MOD) % MOD;
    return Ans;
}

int main(void) {
    LL a, b;
    while (1) {
        cin >> a >> b;
        cout << Muti(a, b, 1000007) << endl;
    }

    return 0;
}
