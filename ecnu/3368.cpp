#include "iostream"
#include "cstdlib"
#include "cstdio"
#include "cstring"
using namespace std;

struct course{
    char name[10];
    int time;
};

int cmp(course a, course b){
    if (strcmp(a.name, b.name) == 0) {
        return a.time > b.time;
    } else {
        return strcmp(a.name, b.name) > 0;
    }
}

int main(void) {
    int n;

    while (scanf("%d\n", &n), n) {
        course courses[10010];
        for (int i = 0; i < n; i++) {
            cin >> courses[i].name;
            cin >> courses[i].time;
        }
        sort(courses, courses + n, cmp);
        int mark = true;
        int ans = courses[0].time;
        for (int i = 0; i < n; i++) {
            cout << courses[i].name << "->" << courses[i].time << endl;
        }
        for (int i = 1; i < n; i++) {
            if (strcmp(courses[i].name, courses[i - 1].name) == 0) {
                if (mark) {
                    ans += courses[i].time;
                    mark = false;
                }
            } else {
                mark = true;
                ans += courses[i].time;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
