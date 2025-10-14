#include <stdio.h>

int main() {
    double arr[10], sum = 0;
    
    for (int i = 0; i < 10; i++) {
        scanf("%lf", &arr[i]);
        sum += arr[i];
    }
    
    
    double average = sum / 10;
    long long value = (long long)(average * 1000 + 0.5);  
    
    
    int last_digit = value % 10;
    value /= 10;
    if (last_digit >= 5) value++;
    
    printf("%lld.%02lld\n", value / 100, value % 100);
    return 0;
}