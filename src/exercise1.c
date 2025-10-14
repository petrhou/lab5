#include <stdio.h>

int main() {
    double arr[10], sum = 0;
    
    for (int i = 0; i < 10; i++) {
        scanf("%lf", &arr[i]);
        sum += arr[i];
    }
    
    // Округление без math.h
    double average = sum / 10;
    average = (int)(average * 100 + 0.5) / 100.0;
    printf("%.2f\n", average);
    
    return 0;
}