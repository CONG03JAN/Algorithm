#include <bits/stdc++.h>
#define mem(ar,num) memset(ar,num,sizeof(ar))
#define me(ar) memset(ar,0,sizeof(ar))
#define lowbit(x) (x&(-x))
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int    prime = 999983;
const int    INF = 0x7FFFFFFF;
const LL     INFF =0x7FFFFFFFFFFFFFFF;
const double pi = acos(-1.0);
const double inf = 1e18;
const double eps = 1e-6;
const LL     mod = 1e9 + 7;

#define MAX 1000000
int Prime[800000]; // 总共 78499 个素数
bool IsPrime[MAX]; // 最大的素数为 999983
int Count;
void GetPrime() {
    Count = 1;
    for(int i = 2; i < MAX; i++) {
        if(!IsPrime[i])
            Prime[Count++] = i;
        for(int j = 1; j < Count && Prime[j] * i < MAX; j++) {
            IsPrime[i * Prime[j]] = true;
            if(i % Prime[j] == 0) break;
        }
    }
}


int main(void) {
    int n;
    GetPrime();
    IsPrime[0] = true;
    while (~scanf("%d", &n) && n >= 0) {
        int d;
        scanf("%d", &d);
        if (IsPrime[n]) {
            printf("No\n");
            continue;
        }
        char ans[50];
        int size = 0;
        do {
            int x = n % d;
            ans[size++] = x + '0';
            n /= d;
        } while(n);
        int tmp = 0;
        int c = 1;
        for (int i = size - 1; i >= 0; i--) {
            int x;
            x  = ans[i] - '0';
            tmp += (x * c);
            c *= d;
        }
        if (IsPrime[tmp] == false) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

}
