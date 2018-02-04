#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main(void) {
    int a[10] = {1, 2, 2, 4, 5, 5, 7, 8, 9, 10};
    sort(a, a + 10, cmp);
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
