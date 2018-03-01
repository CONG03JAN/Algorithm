#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

struct N{
    int x, y, z;
    int s;
};

int go[][3] = {
    1, 0, 0,
    -1, 0, 0,
    0, 1, 0,
    0, -1, 0,
    0, 0, 1,
    0, 0, -1
};

int main(void) {
    int a, b, c, t;
    while (~scanf("%d %d %d %d", &a, &b, &c, &t)) {
        int m[50][50][50] = {0};
        bool mark[50][50][50];
        queue<N> q;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                for (int k = 0; k < c; k++) {
                    int tmp;
                    scanf("%d", &m[i][j][k]);
                    mark[i][j][k] = false;
                }
            }
        }
        N start;
        start.x = 0;
        start.y = 0;
        start.z = 0;
        start.s = 0;
        q.push(start);
        bool isok = false;
        while (!q.empty() && !isok) {
            N now = q.front();
            q.pop();
            for (int i = 0; i < 6; i++) {
                int nx = now.x + go[i][0];
                int ny = now.y + go[i][1];
                int nz = now.z + go[i][2];
                if(nx == a - 1 && ny == b - 1 && nz == c - 1){
                     isok = true;
                     if(now.s < t)
                         printf("%d\n", now.s + 1);
                     else
                         printf("-1\n");
                     break;
                }
                if(nx < 0 || nx >= a || ny < 0 || ny >= b || nz < 0 || nz >= c)
                    continue;
                if(m[nx][ny][nz] == 1)
                    continue;
                if(mark[nx][ny][nz] == true)
                    continue;
                N tmp;
                tmp.x = nx;
                tmp.y = ny;
                tmp.z = nz;
                tmp.s = now.s + 1;
                q.push(tmp);
            }
        }
    }
    return 0;
}
