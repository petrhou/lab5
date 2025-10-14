#include <stdio.h>
#include <math.h>

int main() {
    double arr[10], sum = 0;
    
    for (int i = 0; i < 10; i++) {
        scanf("%lf", &arr[i]);
        sum += arr[i];
    }
    
    // Используем точное округление
    double average = sum / 10;
    
    // Прибавляем очень маленькое значение для правильного округления
    if (average > 0) {
        average += 0.0000001;
    } else {
        average -= 0.0000001;
    }
    
    printf("%.2f\n", average);
    return 0;
}