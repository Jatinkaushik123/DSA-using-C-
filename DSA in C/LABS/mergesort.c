#include <stdio.h>

// Function to merge two sorted subarrays
void merge(int arr[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = 0;
    int temp[high - low + 1];

    // Merge elements in sorted order into temp array
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // Copy remaining elements from left subarray
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements from right subarray
    while (j <= high) {
        temp[k++] = arr[j++];
    }

    // Copy sorted elements back to original array
    for (i = low, k = 0; i <= high; i++, k++) {
        arr[i] = temp[k];
    }
}

// Function to implement merge sort recursively
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        // Divide and sort first and second halves
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // Combine the two halves
        merge(arr, low, mid, high);
    }
}

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("Sorted array (Merge Sort):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}