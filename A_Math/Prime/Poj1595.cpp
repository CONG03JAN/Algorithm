#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

#define MAX 1000000
int Prime[MAX];
bool IsPrime[MAX];
int Count;
void GetPrime(){
    Count = 1;
    for(int i = 2; i < MAX; i++){
        if(!IsPrime[i])
            Prime[Count++] = i;
        for(int j = 1; j < Count && Prime[j] * i < MAX; j++){
            IsPrime[i * Prime[j]] = true;
            if(i % Prime[j] == 0) break;
        }
    }
}

int main(void) {
    GetPrime();
    Prime[0] = 1;
    int n, c;
    while (~scanf("%d %d", &n, &c) && n && c) {
        int bd = lower_bound(Prime, Prime + Count + 1, n) - Prime;
        cout << bd << endl;
        int cnt = bd + 1;
        int st;
        if(cnt % 2 == 0){
            st = n / 2 - c;
        } else {
            st =
        }
    }
    return 0;
}
