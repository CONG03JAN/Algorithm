#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

string list[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main(void) {
    char s[101];
    while (~scanf("%s", s)) {
        int n;
        for (int i = 0; s[i] != '\0'; i++) {
            n += (s[i] - '0');
        }
        string ans;
        ans = to_string(n);
        int len = ans.length();
        for (int i = 0; i < len - 1; i++) {
            cout << list[ans[i] - '0'] << " ";
        }
        cout << list[ans[len - 1] - '0'] << endl;

    }
    return 0;
}
