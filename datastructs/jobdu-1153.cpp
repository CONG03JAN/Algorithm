// 括号匹配

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;

int main(void) {
    char str[1000];
    bool mark[1000];
    while (scanf("%s", str), str[0]) {
        int len = strlen(str);
        memset(mark, false, sizeof(bool) * len);
        int a = 0;
        stack<char> s;
        for (int i = 0; i < len; i++) {
            if (str[i] == '(') {
                s.push('(');
                a++;
            }
            if (str[i] == ')') {
                a++;
                if (s.top() == '(') {
                    s.pop();
                    mark[a - 1] = true;
                    mark[a - 2] = true;
                } else {

                }
            }
        }
    }
    return 0;
}
