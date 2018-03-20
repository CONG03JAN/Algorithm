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
    map<string, set<int> > student;
    while (m--) {
        int course, num;
        scanf("%d %d", &course, &num);
        string name;
        for (int i = 0; i < num; i++) {
            cin >> name;
            student[name].insert(course);
        }
    }
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        map<string, set<int> >::iterator iter = student.find(name);
        if (iter == student.end()) {
            cout << name << " 0" << endl;
        } else {
            cout << name;
            cout << " " << student[name].size();
            for (set<int>::iterator it = student[name].begin(); it != student[name].end(); it++) {
                cout << " " << *it;
            }
            cout << endl;
        }
    }
    return 0;
}
