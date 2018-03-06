#include<iostream>
using namespace std;
#define MAX 1000000
int Prime[800000];
bool IsPrime[MAX];
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
    GetPrime();
    cout << Count << endl;
    cout << Prime[Count - 1] << endl;
    cout << Prime[Count] << endl;
    return 0;
}
