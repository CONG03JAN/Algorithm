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
    char num[13];
    int score;
    int local_rank;
    int local_num;
};

int cmp(Student s1, Student s2) {
    if (s1.score != s2.score) {
        return s1.score > s2.score;
    } else {
        return strcmp(s2.num, s1.num) > 0;
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    Student s[30001];
    int a = 0;
    int b = 0;
    int count = 0;
    for (int nn = 1; nn <= n; nn++) {
        a = b;
        int k;
        scanf("%d", &k);
        count += k;
        char num[14];
        int score;
        for (int i = 0; i < k; i++) {
            scanf("%s %d", num, &score);
            strcpy(s[b].num, num);
            s[b].local_num = nn;
            s[b++].score = score;
        }
        sort(s + a, s + b, cmp);
        int cnt = 1;
        for (int i = a; i < b; i++) {
            if (i != a && s[i].score == s[i - 1].score) {
                s[i].local_rank = s[i - 1].local_rank;
            } else {
                s[i].local_rank = cnt;
            }
            cnt++;
        }
    }

    sort(s, s + count, cmp);
    cout << count << endl;
    int cnt = 1;
    int now = 1;
    for (int i = 0; i < count; i++) {
        if (i != 0 && s[i].score != s[i - 1].score) {
            now = cnt;
        }
        printf("%s %d %d %d\n", s[i].num, now, s[i].local_num, s[i].local_rank);
        cnt++;
    }
    return 0;
}
