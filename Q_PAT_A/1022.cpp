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

map<string, string> title, author, key, pub, year;

void query(map<string, string> m, string s) {
    if (m.find(s) != m.end()) {

    } else {
        cout << "Not Found\n" << endl;
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    string tid, ttitle, tauthor, tkey, tpub, tyear;
    while (n--) {
        cin >> tid;
        getchar();
        getline(cin, ttitle);
        title.insert(pair<string, string>(ttitle, tid));
        getline(cin, tauthor);
        while (cin >> tkey) {
            key.insert(pair<string, string>(tkey, tid));
            char c = getchar();
            if (c == '\n') {
                break;
            }
        }
        author.insert(pair<string, string>(tauthor, tid));
        getline(cin, tpub);
        pub.insert(pair<string, string>(tpub, tid));
        getline(cin, tyear);
        year.insert(pair<string, string>(tyear, tid));
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int q;
        scanf("%d: ", &q);
        string s;
        getline(cin, s);
    }

    return 0;
}
