#include <iostream>
#include <cstdio>
using namespace std;

char list[3] = {'W', 'T', 'L'};

int main(void) {
    double x[3][3];
    while (~scanf("%lf %lf %lf", x[0], x[0] + 1, x[0] + 2)) {
        scanf("%lf %lf %lf", x[1], x[1] + 1, x[1] + 2);
        scanf("%lf %lf %lf", x[2], x[2] + 1, x[2] + 2);
        double ans = 1;
        for (int i = 0; i < 3; i++) {
            double max = -1;
            int pos = 0;
            for (int j = 0; j < 3; j++) {
                if (x[i][j] > max) {
                    max = x[i][j];
                    pos = j;
                }
            }
            ans *= max;
            printf("%c ", list[pos]);
        }
        printf("%.2lf\n", (ans * 0.65 - 1) * 2);
    }
    return 0;
}
