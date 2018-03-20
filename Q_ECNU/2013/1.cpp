#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
char ex[110];
int indexx;
bool A();
bool B();
bool C();

bool A() {
    if (ex[indexx] == 'x') {
        indexx++;
        while (ex[indexx] == ' ')
            indexx++;
        return true;
    }
    if (ex[indexx] == '(') {
        indexx++;
        while (ex[indexx] == ' ')
            indexx++;
        if (B() && ex[indexx] == ')') {
            indexx++;
            while (ex[indexx] == ' ')
                indexx++;
            return true;
        }
    }
    return false;
}
bool B() {
    return A() && C();
}

bool C() {
    while (ex[indexx] == '+') {
        indexx++;
        while (ex[indexx] == ' ')
            indexx++;
        if (!A())
            return false;
    }
    return true;
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();
    while (N--) {
        gets(ex);
        indexx = 0;
        printf("%s\n", A() && ex[indexx] == '\0' ? "Good" : "Bad");
    }
    return 0;
}
