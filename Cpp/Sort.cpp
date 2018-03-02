#include <iostream>
#include <cstdlib>

using namespace std;

struct N{
    int a;
    int b;
};

int cmp(N a, N b){
    if(a.a != b.a){
        return a.a < b.a;
    } else {
        return a.b < b.b;
    }
}

int main(void) {
    N n[10];
    n[0].a = 4; n[0].b = 4;
    n[1].a = 3; n[1].b = 4;
    n[2].a = 2; n[2].b = 2;
    n[3].a = 2; n[3].b = 1;
    sort(n, n + 4, cmp);
    for (int i = 0; i < 4; i++) {
        cout << n[i].a << " " << n[i].b << endl;
    }

    return 0;
}
