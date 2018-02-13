#include "iostream"
using namespace std;

#define MAX 10000

int Prime[MAX];
bool IsPrime[MAX];
int Count;
void GetPrime(){
    Count = 1;
    for (int i = 2; i < MAX; i++) {
        if (!IsPrime[i]) {
            Prime[Count++] = i;
        }
        for (int j = 1; j < Count && Prime[j] * i < MAX; j++) {
            IsPrime[i * Prime[j]] = true;
            if (i % Prime[j] == 0) {
                break;
            }
        }
    }
}


int main(void) {
    GetPrime();
    for (int i = 0; i < 10000; i++) {
        cout << i << "->" << Prime[i] << endl;
    }
    return 0;
}
