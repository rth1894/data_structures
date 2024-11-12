#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
int top = -1;

typedef struct node {
	int data;
	struct node *lchild, *rchild;
} Treenode;

Treenode* stack[SIZE];

void push (Treenode* node);
Treenode* pop ();
void create_r (Treenode* root);
void create_nr (Treenode* root);
void inorder_r(Treenode* root);
void preorder_r(Treenode* root);
void preorder_nr(Treenode* root);
void postorder_r(Treenode* root);
void inorder_nr(Treenode* root);
void preorder_nr(Treenode* root);
void postorder_nr(Treenode* root);

int main() {
	struct node *root = (struct node*) malloc(sizeof(struct node));
	int choice;

	printf("Enter data for root node: ");
	scanf("%d", &root->data);
	root->lchild = NULL;
	root->rchild = NULL;

	do {
		printf("\n1. Recursive tree\n2. Non recursive tree\n3. Inorder recursive\n4. Inorder non-recursive\n5. Preorder recursive\n6. Preorder non-recursive\n7. Postorder recursive\n8. Postorder non-recursive\n9. Exit\n> ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				create_r(root);
				break;
			case 2:
				create_nr(root);
				break;
			case 3:
				inorder_r(root);
				break;
			case 4:
				inorder_nr(root);
				break;
			case 5:
				preorder_r(root);
				break;
			case 6:
				preorder_nr(root);
				break;
			case 7:
				postorder_r(root);
				break;
			case 8:
				postorder_nr(root);
				break; case 9:
				free(root);
				printf("exited!\n");
				break;
			default:
				printf("Enter valid choice!\n");
		}
	} while (choice != 9);
	return 0;
}

void push (Treenode* node) {
	if (top == SIZE-1)
		printf("Stack is full\n");
	else
		stack[++top] = node;
}

Treenode* pop () {
	if (top == -1) return NULL;
	return stack[top--];
}

void create_r (Treenode* root) {
	struct node *temp = root;
	char ch;

	printf("Do you want to fill left of %d (y/n): ", temp->data);
	scanf(" %c", &ch);
	if (ch == 'y' || ch=='Y') {
		struct node *curr = (struct node*) malloc(sizeof(struct node));
		printf("Enter data: ");
		scanf("%d", &curr->data);
		curr->lchild = NULL;
		curr->rchild = NULL;
		temp->lchild= curr;
		create_r(curr);
	}

	printf("Do you want to fill right of %d (y/n): ", temp->data);
	scanf(" %c", &ch);
	if (ch =='y' || ch == 'Y') {
		struct node *curr = (struct node*) malloc(sizeof(struct node));
		printf("Enter data: ");
		scanf("%d", &curr->data);
		curr->lchild = NULL;
		curr->rchild = NULL;
		temp->rchild= curr;
		create_r(curr);
	}
}

void create_nr(Treenode* root) {
	char ch;
	struct node *temp;
	do {
		temp = root;
		int flag = 0;
		struct node *curr = (struct node *) malloc(sizeof(struct node));

		while (flag == 0) {
			printf("Enter data for %d: ", temp->data);
			scanf("%d", &curr->data);
			printf("Do you want to insert data to the left or right of %d? (l/r): ", temp->data);
			scanf(" %c", &ch);

			if (ch == 'l' || ch == 'L') {
				if (temp->lchild == NULL) {
					temp->lchild = curr;
					flag = 1;
				}
				temp = temp->lchild;
			}
			else {
				if (ch == 'r' || ch == 'R') {
					if (temp->rchild == NULL) {
						temp->rchild = curr;
						flag = 1;
					}
					temp = temp->rchild;
				}
				else 
					printf("Invalid input. Please enter 'l' or 'r'.\n");
			}
		}
		printf("Do you want to continue? (y/n): ");
		scanf(" %c", &ch);
	}
	while (ch == 'y' || ch == 'Y');
}

void inorder_r(Treenode* root) {
	Treenode* temp = root;
	if (temp != NULL) {
		inorder_r(temp->lchild);
		printf("%d ", temp->data);
		inorder_r(temp->rchild);
	}
}

void preorder_r(Treenode* root) {
	Treenode* temp = root;
	if (temp != NULL) {
		printf("%d ", temp->data);
		preorder_r(temp->lchild);
		preorder_r(temp->rchild);
	}
}

void preorder_nr(Treenode* root) {
	Treenode* temp = root;
	while (1) {
		while (temp != NULL) {
			printf("%d ", temp->data);
			push(temp);
			temp = temp->lchild;
		}
		if (top == -1) break;
		temp = pop();
		temp = temp->rchild;
	}
}

void postorder_r(Treenode* root) {
	Treenode* temp = root;
	if (temp != NULL) {
		postorder_r(temp->lchild);
		postorder_r(temp->rchild);
		printf("%d ", temp->data);
	}
}

void inorder_nr (Treenode* root) {
	Treenode* temp = root;
	while (1) {
		while (temp != NULL) {
			push(temp);
			temp = temp->lchild;
		}
		if (top == -1) break;
		temp = pop();
		printf("%d ", temp->data);
		temp = temp->rchild;
	}
}

void postorder_nr (Treenode* root) {
	Treenode* temp = root;
	while (1) {
		while (temp != NULL) {
			push(temp);
			temp = temp->lchild;
		}
		if (stack[top]->rchild == NULL) {
			temp = pop();
			printf("%d ", temp->data);
		}
		while ((top != -1) && (stack[top]->rchild == temp)) {
			temp = pop();
			printf("%d ", temp->data);
		}
		if (top == -1) break;
		temp = stack[top]->rchild;
	}
}

