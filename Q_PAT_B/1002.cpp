#include <iostream>
#include <cstdio>
using namespace std;

char num[10][8] = {
    "ling",
    "yi",
    "er",
    "san",
    "si",
    "wu",
    "liu",
    "qi",
    "ba",
    "jiu"
};

int main(void) {
    char s[110];
    scanf("%s", s);

    int ans = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        ans += (s[i] - '0');
    }
    int ss[4];
    int len = 0;
    for (int i = 0; ans != 0; i++) {
        ss[i] = (ans % 10);
        ans /= 10;
        len++;
    }
    for (int i = len - 1; i >= 0; i--) {
        printf("%s", num[ss[i]]);
        if(i != 0) printf(" ");
        else printf("\n");
    }

    return 0;
}
