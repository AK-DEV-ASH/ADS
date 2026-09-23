#include <stdio.h>

int main() {
    int ar[50], size, i, pos, ele;

    printf("Enter the size: ");
    scanf("%d", &size);

    printf("Enter the elements: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &ar[i]);
    }

    printf("Enter the position to insert: ");
    scanf("%d", &pos);

    if (pos <= 0 || pos > size + 1) {
        printf("Invalid position\n");
    } else {
        printf("Enter the element to insert: ");
        scanf("%d", &ele);

       for (i = size; i >= pos; i--) {
            ar[i] = ar[i - 1];
        }

        ar[pos - 1] = ele;
        size++;

        printf("Array after insertion: ");
        for (i = 0; i < size; i++) {
            printf("%d ", ar[i]);
        }
        printf("\n");
    }

    return 0;
}
