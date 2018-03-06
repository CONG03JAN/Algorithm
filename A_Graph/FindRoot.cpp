#include <iostream>

using namespace std;

int findroot(int x) {
    if(Tree[x] == -1) return x;
    else {
        int tmp = findroot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

int findroot2(int x) {
    int ret;
    int tmp = x;
    while(Tree[x] != -1) x = Tree[x];
    ret = x;
    x = tmp;
    while(Tree[x] != -1) {
        int t = Tree[x];
        Tree[x] = ret;
        x = t;
    }
    return ret;
}

int main(void) {

    return 0;
}
