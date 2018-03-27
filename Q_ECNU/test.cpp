#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int ans = 0;
    char c;
    while(scanf("%c", &c) && c != '\n'){
        if (c >= '0' && c <= '9') {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
