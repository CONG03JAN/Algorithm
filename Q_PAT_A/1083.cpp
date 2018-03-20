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

struct Student {
    char name[11];
    char id[11];
    int score;
};

int cmp(Student s1, Student s2) {
    return s1.score > s2.score;
}

Student s[100001];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char name[11], id[11];
        int score;
        scanf("%s %s %d", name, id, &score);
        s[i].score = score;
        strcpy(s[i].name, name);
        strcpy(s[i].id, id);
    }
    sort(s, s + n, cmp);
    int a, b;
    scanf("%d %d", &a, &b);
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (s[i].score >= a && s[i].score <= b) {
            flag = true;
            printf("%s %s\n", s[i].name, s[i].id);
        }
    }
    if (!flag) {
        printf("NONE\n");
    }


    return 0;
}
