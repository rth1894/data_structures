#include <stdio.h>

void print(int size, int array[]);
void sort(int size, int array[]);
void swap(int* x, int* y);

int main() {
        int n;
        printf("Enter number of array elements: ");
        scanf("%d", &n);
 
        int a[n];
        for (int i=0; i<n; i++) {
                printf("Element %d of array: ", i+1);
                scanf("%d", &a[i]);
        }
        printf("Initial: ");
        print(n, a);
        printf("Sorted: ");
        sort(n, a);
        return 0;
}

void print(int size, int array[]) {
        for(int i=0; i<size; i++) {
                printf("%d ", array[i]);
        }
        printf("\n");
}

void sort(int size, int array[]) {
        int gap = size / 2;
        int swapped;
        do {
                do {
                swapped = 0;
                for ( int i=0; i<size-gap;i++)
                        if (array[i] > array[i+gap]) {
                                swap(&array[i], &array[i+gap]);
                                swapped = 1;
                        }
                } while (swapped == 1);
        } while (gap=(gap/2) >= 1);
        print(size, array);
}

void swap(int* x, int* y) {
        int temp = *x;
        *x = *y;
        *y = temp;
}
