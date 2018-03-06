// Union Find Set Example
//

#include <iostream>

using namespace std;

// Recursion
int findRoot1(int *S, int e) {
    if (S[e] == -1) {
        return e;
    } else {
        int tmp = findRoot1(S, S[e]);
        S[e] = tmp;
        return tmp;
    }
}

// No-Recursion
int findRoot2(int *S, int e) {
    int ret;
    int tmp = e;
    while(S[e] != -1) {
        e = S[e];
    }
    ret = e;
    e = tmp;
    while(S[e] != -1) {
        S[e] = ret;
        e = S[e];
    }
    return ret;
}


int main(void) {
    int uSet[100] = {0};
    uSet[0] = 4;
    uSet[1] = -1;
    uSet[2] = 3;
    uSet[3] = 1;
    uSet[4] = -1;

    // Recursion

    // No-Recursion
    for (int i = 0; i < 5; i++) {
        cout << i << " -> " << findRoot2(uSet, i) << endl;
    }
    for (int i = 0; i < 5; i++) {
        cout << uSet[i] << endl;
    }

    return 0;
}
