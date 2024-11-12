#include <complex.h>
#include <stdio.h>
struct student {
	int roll;
	char name[10];
	float percentage;
};

void print(int size, struct student s[]);
void accept(int size, struct student s[]);
void bubble(int size, struct student s[]);
void selection(int size, struct student s[]);
void insertion(int size, struct student s[]);
void shell(int size, struct student s[]);

int main() {
	int n;
	printf("Enter number of students: ");
	scanf("%d", &n);
	struct student s[n];
	accept(n, s);
	int choice;
	printf("Enter choice\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Shell Sort\n> ");
	scanf("%d", &choice);

	printf("Name\tRoll\tPercentage\n");
	switch(choice) {
		case 1:
			bubble(n, s);
			break;
		case 2: 
			selection(n,s);
			break;
		case 3:
			insertion(n, s);
			break;
		case 4:
			shell(n,s);
			break;
		default:
			printf("Enter valid choice!\n");
			break;
	}
}

void print(int size, struct student s[]) {
	for (int i=0; i<size; i++) {
		printf("%s\t", s[i].name);
		printf("%d\t", s[i].roll);
		printf("%.2f\t\n", s[i].percentage);
	}
	printf("\n");
}

void bubble(int size, struct student s[]) {
	struct student temp;
	for (int i=0; i<size; i++) {
		for (int j=0; j<size-i-1; j++) {
			if (s[j].percentage > s[j+1].percentage) {
			temp = s[j];
			s[j] = s[j+1];
			s[j+1] = temp;
			}
		print(size, s);
		}
	}
}

void selection(int size, struct student s[]) {
	int minpos;
	struct student temp;
	for (int i=0; i<size; i++) {
		minpos = i;
		for (int j=i+1; j<size; j++) {
			if (s[j].percentage < s[minpos].percentage)
				minpos = j;
			if (minpos != i) {
				temp = s[i];               
        	                s[i] = s[minpos];
	                        s[minpos] = temp;
			}
		}
	print(size, s);
	}
}

void insertion(int size, struct student s[]) {
	float temp = 0;
	int j;
	for (int i = 0; i<size; i++) {
		temp = s[i].percentage;
		j = i - 1;
		while (j >= 0 && s[j].percentage > temp) {
			s[j+1] = s[j];
			j--;
		}
		s[j+1].percentage = temp;
		print(size, s);
	}
}

void accept(int size, struct student s[]) {
	for (int i=0; i<size; i++) {
	        printf("Name: ");
        	scanf("%s", s[i].name);
	        printf("Roll number: ");
        	scanf("%d", &s[i].roll);
	        printf("Percentage: ");
        	scanf("%f", &s[i].percentage);
        }
}

void shell(int size, struct student s[]) {
	struct student temp;
	int gap = size / 2;
	int swapped;
	do {
		do {
			swapped = 0;
			for (int i=0; i<size-gap; i++)
				if (s[i].percentage > s[i+1].percentage) {
					temp = s[i];
					s[i] = s[i+1];
					s[i+1] = temp;
					swapped = 1;
				}
			print(size, s);
		} while (swapped == 1);
	} while (gap = (gap/2) >= 1);
}
