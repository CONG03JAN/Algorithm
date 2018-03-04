#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

struct Student {
    char name[11];
    char num[11];
    int score;
};

int main(void) {
    int n;
    while (~scanf("%d", &n) && n) {
        Student minS;
        Student maxS;
        minS.score = 101;
        maxS.score = -1;
        char name[11];
        char num[11];
        int score;
        for (int i = 0; i < n; i++) {
            scanf("%s %s %d", name, num, &score);
            if (score > maxS.score) {
                maxS.score = score;
                strcpy(maxS.name, name);
                strcpy(maxS.num, num);
            }
            if (score < minS.score) {
                minS.score = score;
                strcpy(minS.name, name);
                strcpy(minS.num, num);
            }
        }
        printf("%s %s\n", maxS.name, maxS.num);
        printf("%s %s\n", minS.name, minS.num);
    }
    return 0;
}
