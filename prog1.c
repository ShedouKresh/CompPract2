#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Vvedite N: ");
    scanf("%d", &n);

    int a = 0, b = 1, c;
    int step = 0;

    while (b < n) {
        c = a + b;
        a = b;
        b = c;
        step++;
    }

    int ans;
    if (abs(n - a) <= abs(b - n)) {
        ans = a;
    } else {
        ans = b;
    }

    printf("Shagov: %d\n", step);
    printf("Blizhayshee chislo Fibonachchi: %d\n", ans);
    return 0;
}