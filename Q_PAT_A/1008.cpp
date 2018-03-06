#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
    int n;
    int list[101];
    while (~scanf("%d", &n) && n) {
        int now = 0;
        int time = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", list + i);
        }
        for (int i = 0; i < n; i++) {
            if(list[i] > now) {
                time += ((list[i] - now) * 6);
                now = list[i];
            } else {
                time += ((now - list[i]) * 4);
                now = list[i];
            }
        }
        time += (n * 5);
        cout << time << endl;
    }
    return 0;
}
