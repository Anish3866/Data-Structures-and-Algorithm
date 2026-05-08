#include <stdio.h>

int getMax(int arr[], int n);
void radixSort(int arr[], int n);
void countingSort(int arr[], int n, int exp);

int main() {
    int arr[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    radixSort(arr, n);

    printf("Sorted array in ascending order:\n");

    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

int getMax(int arr[], int n) {
    int i, max = arr[0];

    for(i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

void countingSort(int arr[], int n, int exp) {
    int output[100];
    int count[10] = {0};
    int i;

    for(i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for(i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for(i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for(i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int exp;
    int max = getMax(arr, n);

    for(exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}
