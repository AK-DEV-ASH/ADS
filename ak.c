#include <stdio.h>

int main()
{
    int size, i;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int ar[size];

    printf("Enter the elements of the array: ");
    for (i = 0; i < size; i++)
        scanf("%d", &ar[i]);

    printf("Array elements: ");
    for (i = 0; i < size; i++)
        printf("%d ", ar[i]);

    return 0;
}

