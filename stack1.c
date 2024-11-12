#include <stdio.h>

#define SIZE 5

int top = -1;
char stack[SIZE];

int isEmpty();
int isFull();
void push(char elem);
int pop();
void display();

int main() {
	int choice;
	char element;
	do {
		printf("1. Push element\n2. Pop element\n3. Display stack\n4. Exit\n> ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				printf("Enter number to push: ");
				scanf("%s", &element);
				push(element);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Exited!\n");
				break;
			default:
				printf("Invalid choice\n");
		}
	}while (choice != 4);
}

int isEmpty() {
	return (top == -1);
}

int isFull() {
	return (top == SIZE-1);
}

void push(char elem) {
	if (!isFull()) {
		top += 1;
		stack[top] = elem;
	}
	else
		printf("Stack is Full!\n");
}

int pop() {
	if (!isEmpty()) {
		top -= 1;
		return stack[top];
	}
	else {
		printf("Stack is Empty\n");
		return -1;
	}
}

void display() {
	if (isEmpty())
		printf("Stack is Empty\n");
	else {
		for (int i=0; i<top+1; i++)
			printf("%c ", stack[i]);
		printf("\n");
	}
}
