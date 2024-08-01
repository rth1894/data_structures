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
	int key, j;
	for (int i=0; i<size; i++) {
		key = array[i];
		j = i - 1;
		while (j>=0 && array[j]>key) {
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = key;
	}
	print(size, array);
}

void swap(int* x, int* y) {
        int temp = *x;
        *x = *y;
        *y = temp;
}
