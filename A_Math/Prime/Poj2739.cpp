#include <iostream>
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
    int n;
    while (scanf("%d", &n) != EOF && n) {
        int cnt = 0;
        for (int i = 1; Prime[i] <= n; i++) {
            int tmp = Prime[i];
            int j = i + 1;
            while(tmp < n){
                tmp += Prime[j++];
            }
            if(tmp == n) cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
