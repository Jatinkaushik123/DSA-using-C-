#include <stdio.h>
void traversal(int arr[], int n)
{
    if (n == 0)
    {
        printf("The array is empty.\n");
        return;
    }
    printf("Array Elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main()
{
    int numbers[]={10, 20, 30, 40, 50};
    int n = 5;
    traversal(numbers , n) ;
    return 0 ;
}