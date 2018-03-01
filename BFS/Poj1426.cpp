#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

struct N{
    long long n;
};

int main(void) {
    int n;
    while (~scanf("%d", &n) && n) {
        queue<N> q;
        N tmp;
        tmp.n = 1;
        q.push(tmp);
        while(!q.empty()){
            N t = q.front();
            q.pop();
            if(t.n % n == 0){
                printf("%lld\n", t.n);
                break;
            } else {
                N t1, t2;
                t1.n = t.n * 10;
                t2.n = t.n * 10 + 1;
                q.push(t1);
                q.push(t2);
            }
        }
    }
    return 0;
}
