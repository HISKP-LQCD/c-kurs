#include <stdio.h>

void swap_int(int *x, int *y) {
    int tmp = *x;
    *x = *y; *y = tmp;
}

int main() {
    int a=2, b=3;
    swap_int(&a, &b);
    printf("%i\n", a);
    return 0;
}
