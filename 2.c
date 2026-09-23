#include <stdio.h>

int main()
{
    int ar[50], size, i, ele, found = 0;

    printf("Enter the size: ");
    scanf("%d", &size);

    printf("Enter the elements: ");
    for (i = 0; i < size; i++)
        scanf("%d", &ar[i]);

    printf("Enter the element to be searched: ");
    scanf("%d", &ele);

    for (i = 0; i < size; i++)
    {
        if (ar[i] == ele)
        {
            found = 1;
            break;
        }
    }

    if (found == 1)
        printf("Element found %d",(i+1));
    else
        printf("Element not found");

    return 0;
}

