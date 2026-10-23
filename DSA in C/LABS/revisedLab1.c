#include <stdio.h>

#define MAX 100

// 1. Traversal: Visit and print every element
void traverse(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 2. Insertion: Shift elements to the right to make room
int insertAt(int arr[], int n, int element, int index) {
    if (n >= MAX) {
        printf("Overflow! Array is full.\n");
        return n;
    }
    if (index < 0 || index > n) {
        printf("Invalid index!\n");
        return n;
    }

    // Shift from right to left
    for (int i = n - 1; i >= index; i--) {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return n + 1; // return new size
}

// 3. Deletion: Shift elements to the left to close the gap
int deleteAt(int arr[], int n, int index) {
    if (n <= 0) {
        printf("Underflow! Array is empty.\n");
        return n;
    }
    if (index < 0 || index >= n) {
        printf("Invalid index!\n");
        return n;
    }

    // Shift from left to right
    for (int i = index; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return n - 1; // return new size
}

// 4. Update: Overwrite value at index
void updateAt(int arr[], int n, int index, int newVal) {
    if (index < 0 || index >= n) {
        printf("Invalid index!\n");
        return;
    }
    arr[index] = newVal;
}

// 5. Linear Search: Unsorted array, O(n)
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // found at index i
        }
    }
    return -1; // not found
}

// 6. Binary Search: MUST be sorted array, O(log n)
int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // prevents integer overflow

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1; // target is in right half
        } else {
            high = mid - 1; // target is in left half
        }
    }
    return -1; // not found
}

int main() {
    int arr[MAX];
    int n = 0;

    // Initialize with 5 elements: {10, 20, 30, 40, 50}
    n = 5;
    arr[0] = 10; arr[1] = 20; arr[2] = 30; arr[3] = 40; arr[4] = 50;
    traverse(arr, n);

    // Insert 25 at index 2 (position 3)
    n = insertAt(arr, n, 25, 2);
    printf("After inserting 25 at index 2:\n");
    traverse(arr, n);

    // Delete element at index 4
    n = deleteAt(arr, n, 4);
    printf("After deleting element at index 4:\n");
    traverse(arr, n);

    // Update element at index 1 to 99
    updateAt(arr, n, 1, 99);
    printf("After updating index 1 to 99:\n");
    traverse(arr, n);

    // Search tests
    int target = 25;
    int lsResult = linearSearch(arr, n, target);
    printf("Linear Search for %d: %s (Index: %d)\n", 
           target, (lsResult != -1 ? "Found" : "Not Found"), lsResult);

    // Binary search demonstration (using a sorted array)
    int sortedArr[] = {5, 12, 19, 27, 34, 45, 60};
    int sortedSize = 7;
    int bsTarget = 27;
    int bsResult = binarySearch(sortedArr, sortedSize, bsTarget);
    printf("Binary Search for %d in sorted array: %s (Index: %d)\n", 
           bsTarget, (bsResult != -1 ? "Found" : "Not Found"), bsResult);

    return 0;
}