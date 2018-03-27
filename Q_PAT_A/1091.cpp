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

int slices[1300][130][80] = {0};
bool visited[1300][130][80] = {false};

int n, m, l, t;
struct Node {
    int x, y, z;
};

int arr[6][3] = {
    1, 0, 0,
    -1, 0, 0,
    0, 1, 0,
    0, -1, 0,
    0, 0, 1,
    0, 0, -1
};

bool judge(int x, int y, int z) {
    if(x < 0 || x >= n || y < 0 || y >= m || z < 0 || z >= l) return false;
    if(slices[x][y][z] == 0 || visited[x][y][z] == true) return false;
    return true;
}

int bfs(int x, int y, int z) {
    int ans = 0;
    queue<Node> Q;
    Node node;
    node.x = x;
    node.y = y;
    node.z = z;
    Q.push(node);
    visited[x][y][z] = true;
    while (Q.empty() == false) {
        Node now = Q.front();
        Q.pop();
        ans++;
        for (int i = 0; i < 6; i++) {
            Node tmp;
            tmp.x = now.x + arr[i][0];
            tmp.y = now.y + arr[i][1];
            tmp.z = now.z + arr[i][2];
            if (judge(tmp.x, tmp.y, tmp.z)) {
                Q.push(tmp);
                visited[tmp.x][tmp.y][tmp.z] = true;
            }
        }
    }
    if (ans >= t) {
        return ans;
    } else {
        return 0;
    }
}

int main(void) {
    scanf("%d %d %d %d", &n, &m, &l, &t);
    int pix;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                scanf("%d", &pix);
                slices[i][j][k] = pix;
            }
        }
    }
    queue<Node> Q;
    int ans = 0;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (slices[j][k][i] == 1 && visited[j][k][i] == false) {
                    int tmp = bfs(j, k, i);
                    cout << tmp << endl;
                    ans += tmp;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}


