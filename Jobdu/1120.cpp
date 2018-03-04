#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char ans[8];
bool visited[8];

void dfs(char c, int n, int len, char *s) {
    //cout << s << endl;
    ans[n] = c;
    if (n == len - 1) {
        for (int i = 0; i < len; i++) {
            printf("%c", ans[i]);
        }
        printf("\n");
        return;
    } else {
        for (int i = 0; i < len; i++) {
            if (visited[i] == false) {
                visited[i] = true;
                dfs(s[i], n + 1, len, s);
                visited[i] = false;
            }
        }
    }
}

int main(void) {
    char s[8];
    while (~scanf("%s", s)) {
        //cout << strlen(s) << endl;
        memset(ans, '\0', sizeof(ans));
        memset(visited, false, sizeof(visited));
        int len = strlen(s);
        for (int i = 0; i < len; i++) {
            visited[i] = true;
            dfs(s[i], 0, len, s);
            visited[i] = false;
        }
    }
    return 0;
}
