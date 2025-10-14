#include <stdio.h>

int main() {
    double arr[10], sum = 0;
    for (int i = 0; i < 10; i++) {
        scanf("%lf", &arr[i]);
        sum += arr[i];
    }
    printf("%.2f\n", sum / 10);
    return 0;
}