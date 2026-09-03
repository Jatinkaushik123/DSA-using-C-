/*Experiment 1: Write a C program to understand the concept
    of arrays and implement basic array operations including traversal, insertion,
    deletion, searching, and updating. Also implement Linear Search and Binary
    Search on arrays.*/

#include <stdio.h>

#define MAX 100

void display(int arr[], int n);
int insert(int arr[], int n);
int deleteElement(int arr[], int n);
void update(int arr[], int n);
int linearSearch(int arr[], int n, int key);
int binarySearch(int arr[], int n, int key);
void sortArray(int arr[], int n);

int main()
{
    int arr[MAX];
    int n, choice, key, result;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n < 0 || n > MAX)
    {
        printf("Invalid array size.\n");
        return 0;
    }

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    do
    {
        printf("\n--- Array Operations ---\n");
        printf("1. Display array\n");
        printf("2. Insert element\n");
        printf("3. Delete element\n");
        printf("4. Update element\n");
        printf("5. Linear search\n");
        printf("6. Binary search\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                display(arr, n);
                break;

            case 2:
                n = insert(arr, n);
                break;

            case 3:
                n = deleteElement(arr, n);
                break;

            case 4:
                update(arr, n);
                break;

            case 5:
                printf("Enter the element to search: ");
                scanf("%d", &key);

                result = linearSearch(arr, n, key);

                if (result == -1)
                    printf("Element not found.\n");
                else
                    printf("Element found at position %d.\n", result + 1);

                break;

            case 6:
                if (n == 0)
                {
                    printf("Array is empty.\n");
                    break;
                }

                sortArray(arr, n);

                printf("Sorted array: ");
                display(arr, n);

                printf("Enter the element to search: ");
                scanf("%d", &key);

                result = binarySearch(arr, n, key);

                if (result == -1)
                    printf("Element not found.\n");
                else
                    printf("Element found at position %d.\n", result + 1);

                break;

            case 7:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 7);

    return 0;
}

void display(int arr[], int n)
{
    if (n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int insert(int arr[], int n)
{
    int position, value;

    if (n == MAX)
    {
        printf("Array is full.\n");
        return n;
    }

    printf("Enter the position: ");
    scanf("%d", &position);

    if (position < 1 || position > n + 1)
    {
        printf("Invalid position.\n");
        return n;
    }

    printf("Enter the value: ");
    scanf("%d", &value);

    for (int i = n; i >= position; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[position - 1] = value;

    printf("Element inserted successfully.\n");

    return n + 1;
}

int deleteElement(int arr[], int n)
{
    int position;

    if (n == 0)
    {
        printf("Array is empty.\n");
        return n;
    }

    printf("Enter the position to delete: ");
    scanf("%d", &position);

    if (position < 1 || position > n)
    {
        printf("Invalid position.\n");
        return n;
    }

    for (int i = position - 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    printf("Element deleted successfully.\n");

    return n - 1;
}

void update(int arr[], int n)
{
    int position, value;

    if (n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    printf("Enter the position to update: ");
    scanf("%d", &position);

    if (position < 1 || position > n)
    {
        printf("Invalid position.\n");
        return;
    }

    printf("Enter the new value: ");
    scanf("%d", &value);

    arr[position - 1] = value;

    printf("Element updated successfully.\n");
}

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }

    return -1;
}

int binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

void sortArray(int arr[], int n)
{
    int temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}