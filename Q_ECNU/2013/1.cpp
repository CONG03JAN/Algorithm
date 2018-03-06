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


