#include <iostream>
#include <cstdio>
using namespace std;

#define MAX 1000000
int Prime[800000]; // 总共 78499 个素数
bool IsPrime[MAX]; // 最大的素数为 999983
int Count;
void GetPrime(int n) {
    Count = 1;
    for(int i = 2; i <= n; i++) {
        if(!IsPrime[i])
            Prime[Count++] = i;
        for(int j = 1; j < Count && Prime[j] * i <= n; j++) {
            IsPrime[i * Prime[j]] = true;
            if(i % Prime[j] == 0) break;
        }
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    GetPrime(n);
    int ans = 0;
    for (int i = 2; i <= Count; i++) {
        if (Prime[i] - Prime[i - 1] == 2) {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}


