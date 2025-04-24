/* C (Procedural Approach) */
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

float mean(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) sum += arr[i];
    return (float)sum / size;
}

float median(int arr[], int size) {
    qsort(arr, size, sizeof(int), compare);
    if (size % 2 == 0)
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    else
        return arr[size / 2];
}

void mode(int arr[], int size) {
    int maxCount = 0, count;
    printf("Mode: ");
    for (int i = 0; i < size; i++) {
        count = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) count++;
        }
        if (count > maxCount) maxCount = count;
    }
    for (int i = 0; i < size; i++) {
        count = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) count++;
        }
        if (count == maxCount) {
            printf("%d ", arr[i]);
            i += count - 1;
        }
    }
    printf("\n");
}

int main() {
    int data[] = {1, 2, 2, 3, 4, 5, 5, 5};
    int size = sizeof(data) / sizeof(data[0]);
    printf("Mean: %.2f\n", mean(data, size));
    printf("Median: %.2f\n", median(data, size));
    mode(data, size);
    return 0;
}
