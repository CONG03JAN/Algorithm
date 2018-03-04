#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int main(void) {
    char s[100];
    while (~scanf("%s", s)) {
        int ans = 0;
        stack<int> st;
        for (int i = 0; s[i] != '\0'; i++) {
            if(s[i] == '(') st.push(0);
            if(s[i] == ')') {
                if(st.empty()) continue;
                else {
                    ans += 2;
                    st.pop();
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
