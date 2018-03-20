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

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    map<int, set<string> > course;
    string name;
    int tcourse;
    for (int i = 0; i < n; i++) {
        cin >> name;
        int num;
        scanf("%d", &num);
        for (int j = 0; j < num; j++) {
            scanf("%d", &tcourse);
            course[tcourse].insert(name);
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << i << " " << course[i].size() << endl;
        for (set<string>::iterator iter = course[i].begin(); iter != course[i].end(); iter++) {
            cout << *iter << endl;
        }
    }

    return 0;
}
