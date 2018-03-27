#include <bits/stdc++.h>
#define mem(ar,num) memset(ar,num,sizeof(ar))
#define me(ar) memset(ar,0,sizeof(ar))
#define lowbit(x) (x&(-x))
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int    prime = 999983;
const int    INF = 0x7FFFFFFF;
const LL     INFF =0x7FFFFFFFFFFFFFFF;
const double pi = acos(-1.0);
const double inf = 1e18;
const double eps = 1e-6;
const LL     mod = 1e9 + 7;

char M[85][1005];
bool visited[85][1005];

int w, h;

bool judge(int x, int y) {
    if (visited[x][y] == true) {
        return false;
    }
    if (x < 0 || x >= h || y < 0 || y >= w) {
        return false;
    }
    if (M[x][y] == '.') {
        return false;
    }
    return true;
}

int go[8][2] = {
    -1, 0,
    1, 0,
    0, -1,
    0, 1,
    1, 1,
    1, -1,
    -1, 1,
    -1, -1,
};

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 8; i++) {
        int tx, ty;
        tx = x + go[i][0];
        ty = y + go[i][1];
        if (judge(tx, ty)) {
            dfs(tx, ty);
        }
    }
}


int main(void) {
    while (scanf("%d %d", &w, &h) != EOF) {
        for (int i = 0; i < h; i++) {
            getchar();
            for (int j = 0; j < w; j++) {
                scanf("%c", &M[i][j]);
                visited[i][j] = false;
            }
        }
        int ans = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (judge(i, j)) {
                    ans++;
                    dfs(i, j);
                }
            }
        }
        cout << ans << endl;

    }
    return 0;
}
