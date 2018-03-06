#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
    int n, m;
    while (scanf("%d %d", &n, &m) == 2 && n && m) {
        int M[10][10];
        int N[10][10];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &M[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &N[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                M[i][j] += N[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            bool mark = true;
            for (int j = 0; j < m; j++) {
                if(M[i][j] != 0) {
                    mark = false;
                    break;
                }
            }
            if (mark) {
                ans++;
            }
        }
        for (int i = 0; i < m; i++) {
            bool mark = true;
            for (int j = 0; j < n; m++) {
                if(M[j][i] != 0) {
                    mark = false;
                    break;
                }
            }
            if (mark) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
