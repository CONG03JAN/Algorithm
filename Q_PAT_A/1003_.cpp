#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct E {
    int next;
    int c;
    int cost;
};

#define MAX 1001
vector<E> edge[MAX];
int mens[MAX];
int Dis[MAX];
int cost[MAX];
bool mark[MAX];
int num[MAX];

int main(void) {
    int n, m;
    int S, T;
    while (scanf("%d %d", &n, &m) != EOF) {
        if(n == 0 && m == 0) break;
        for(int i = 1; i <= n; i++) edge[i].clear();
        for(int i = 1; i <= n; i++) {
            scanf("%d", mens + i);
        }
        while (m--) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            E tmp;
            tmp.c = c;
            tmp.next = b;
            edge[a].push_back(tmp);
            tmp.next = a;
            edge[b].push_back(tmp);
        }
    }
    return 0;
}

