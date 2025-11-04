#include "../include/advanced_array_function.h"

int max_subarray_sum(int* nums, int size) {
    if (size == 0) {
        return 0;
    }
    
    int max_sum = nums[0];
    int sum = nums[0];

    for (int i = 1; i < size; i++) {
        if (sum + nums[i] > nums[i]) {
            sum += nums[i];
        } else {
            sum = nums[i];
        }

        if (max_sum < sum) {
            max_sum = sum;
        }
    }
    return max_sum;
}

int length_of_lis(int* nums, int numsSize) {
    #include <stdlib.h>

    if (numsSize == 0) {
        return 0;
    }

    if (numsSize == 1) {
        return 1;
    }

    int* lens = (int*)malloc(numsSize * sizeof(int));
    if (lens == NULL) {
        printf("ERROR");
        return 1;
    }
    
    for (int i = 0; i < numsSize; i++) {
        lens[i] = 1;
    }

    int max_lens = 1;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1]) {
            lens[i] = lens[i - 1] + 1;
        }

        if (lens[i] > max_lens) {
            max_lens = lens[i];
        }
    }

    free (lens);
    return max_lens;
}

int* merge(int* intervals, int intervalsSize, int* returnSize) {
    #include <stdlib.h>

    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int* sorted = (int*)calloc(intervalsSize * 2, sizeof(int));
    for (int i = 0; i < intervalsSize * 2; i++) {
        sorted[i] = intervals[i];
    }

    for (int i = 0; i < intervalsSize - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < intervalsSize; j++) {
            if (sorted[j * 2] < sorted[min_index * 2]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            int start = sorted[i * 2];
            int end = sorted[i * 2 + 1];
            sorted[i * 2] = sorted[min_index * 2];
            sorted[i * 2 + 1] = sorted[min_index * 2 + 1];
            sorted[min_index * 2] = start;
            sorted[min_index * 2 + 1] = end;
        }
    }

    int* result = (int*)calloc(intervalsSize * 2, sizeof(int));
    result[0] = sorted[0];
    result[1] = sorted[1];
    int count = 1;

    for (int i = 1; i < intervalsSize; i++) {
        int start = sorted[i * 2];
        int end = sorted[i * 2 + 1];
        int final_end = result[(count - 1) * 2 + 1];

        if (start <= final_end) {
            if (end > final_end) {
                result[(count - 1) * 2 + 1] = end;
            }
        } else {
            result[count * 2] = start;
            result[count * 2 + 1] = end;
            count++;
        }
    }

    *returnSize = count;
    free(sorted);
    return result;
}