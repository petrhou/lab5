#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    double arr[10], result[10];
    int k = atoi(argv[1]);
    
    for (int i = 0; i < 10; i++) {
        scanf("%lf", &arr[i]);
    }
    
    for (int i = 0; i < 10; i++) {
        result[(i + k % 10 + 10) % 10] = arr[i];
    }
    
    for (int i = 0; i < 10; i++) {
        printf("%g ", result[i]);
    }
    printf("\n");
    
    return 0;
}