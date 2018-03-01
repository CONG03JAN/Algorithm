#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

struct Q{
    int now;
    int s;
};

queue<Q> q;

int main(void) {
    int n, m;
    while (~scanf("%d %d", &n, &m)) {
        Q tmp;
        tmp.now = n;
        tmp.s = 0;
        int res = bfs()
    }
    return 0;
}
