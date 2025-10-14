#include <stdio.h>

int main() {
    double arr[10];
    for (int i = 0; i < 10; i++) {
        scanf("%lf", &arr[i]);
    }
    for (int i = 9; i >= 0; i--) {
        printf("%g ", arr[i]);
    }
    printf("\n");
    return 0;
}