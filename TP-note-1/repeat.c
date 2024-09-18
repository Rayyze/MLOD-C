#include <stdlib.h>
#include <stdio.h>

int *repeat(int t1[], int t2[], int n);

int main(void) {
    int t1[]= {1, 2, 4};
    int t2[]={10, 3, 8};
    int expected_result[]={10,3,3,8,8,8,8};
    int *actual_result=repeat(t1, t2, 3);
    int expected_len = sizeof(expected_result) / sizeof(expected_result[0]);

    printf("Actual result: ");
    for (int i = 0; i < expected_len; i++) {
        printf("%d ", actual_result[i]);
    }
    printf("\n");

    printf("Expected result: ");
    for (int i = 0; i < expected_len; i++) {
        printf("%d ", expected_result[i]);
    }
    printf("\n");

    free(actual_result);
}

int *repeat(int t1[], int t2[], int n) {
    int total_size = 0;
    for (int i = 0; i < n; i++) {
        total_size += t1[i];
    }

    int *result = malloc(sizeof(int) * total_size);

    int current_index=0;
    for(int i = 0; i<n; i++) {
        for(int j = 1; j<=t1[i]; j++) {
            result[current_index] = t2[i];
            current_index++;
        }
    }
    return result;
}
