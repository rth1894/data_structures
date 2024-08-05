#include <stdio.h>

//global declarations
int queue[10], rear = -1, front = -1;

//functions
int isFull();
int isEmpty();
void addElement();
void deleteElement();
void display();

int main() {
	int choice, element;

	do {
		printf("Enter operation to perform:\n1. Add element to queue\n2. Delete element from queue\n3. Display queue\n4. Exit\n> ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				addElement();
				break;
			case 2:
				deleteElement();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Exited\n");
				break;
			default:
				printf("Invalid choice\n");
		}
	} while (choice != 4);
}

int isFull() {
	if (rear == 10-1)
		return 1;
	return 0;
}

int isEmpty() {
	if (front == rear)
		return 1;
	return 0;
}

void addElement() {
	if (isFull())
		printf("Queue is full\n");
	else {
		int elem;
		printf("Enter element to be added: ");
		scanf("%d", &elem);
		++ rear;
		queue[rear] = elem;
	}
}

void deleteElement() {
	if (isEmpty())
		printf("Queue is empty\n");
	else
		front ++;
}

void display() {
	if (isEmpty())
		printf("Queue is empty\n");
	else {
		for (int i=front+1; i<=rear; i++)
			printf("%d ", queue[i]);
		printf("\n");
	}
}
