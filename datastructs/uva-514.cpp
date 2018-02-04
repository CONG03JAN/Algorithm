#include <cstdio>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    int n;
    while (scanf("%d", &n), n) {
        int l[1010] = {0};
        while (scanf("%d", l), l[0]) {
            for (int i = 1; i < n; i++) {
                scanf("%d", l+i);
            }
            int a = 1;
            int b = 0;
            stack<int> s;
            while (a <= n || ((!s.empty()) && (s.top() == l[b]))) {
                if (s.empty() || s.top() != l[b]) {
                    //cout << "Push" << a << endl;
                    s.push(a++);
                } else {
                    //cout << "Pop" << s.top() << endl;
                    s.pop();
                    b++;
                }
            }
            //cout << "b = " << b << endl;
            printf(b == n? "Yes": "No");
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
