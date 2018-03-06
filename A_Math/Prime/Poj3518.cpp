#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 1300000
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
    int num;
    while (~scanf("%d", &num) && num) {
        int bd = lower_bound(Prime + 1, Prime + Count + 1, num) - Prime;
        if(Prime[bd] == num) printf("0\n");
        else printf("%d\n", Prime[bd] - Prime[bd - 1]);
    }
    return 0;
}
