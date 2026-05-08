#include <stdio.h>

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main() {
    int arr[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("Sorted array in ascending order:\n");

    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void quickSort(int arr[], int low, int high) {
    int pivotIndex;

    if(low < high) {
        pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot, i, j, temp;

    pivot = arr[high];
    i = low - 1;

    for(j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;

            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}
