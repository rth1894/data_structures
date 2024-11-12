#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void create(struct node *h);
void display(struct node *h);
int length(struct node *h);
void insert(struct node *h);
void delete(struct node *h);

int main() {
    struct node *head = (struct node *) malloc(sizeof(struct node));
    head->next = NULL;
    struct node *temp;
    int choice;

    do {
        printf("\n1. Create linked list\n2. Display Linked list\n3. Length of linked list\n4. Insert in linked list\n5. Delete linked list\n6. Exit\n> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create(head);
                break;
            case 2:
                display(head);
                break;
            case 3:
                length(head);
                break;
            case 4:
                insert(head);
                break;
            case 5:
                delete(head);
                break;
            case 6:
                printf("Exited!\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    while (choice != 6);

    return 0;
}

void create(struct node *h) {
    struct node *temp = h;
    struct node *curr;
    char choice;

    do {
        printf("Enter choice (Y/N): ");
        scanf(" %c", &choice);

        if (choice == 'N' || choice == 'n')
            break;

        curr = (struct node *) malloc(sizeof(struct node));
        curr = (struct node *) malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &curr->data);

        curr->next = NULL;
        temp->next = curr;
        temp = curr;
    }
    while (choice == 'Y' || choice == 'y');
}

void display(struct node *h) {
    if (h->next == NULL)
        printf("List is empty\n");

    else {
        struct node *curr = h->next;
        printf("\nAdress\t\tData\tNext\n");
        while (curr != NULL) {
            printf("%p\t%d\t%p\n", curr, curr->data, curr->next);
            curr = curr-> next;
        }
    }

    printf("\n");
}

int length(struct node *h) {
    int count = 0;
    struct node *curr = h->next;

    while (curr != NULL) {
        count ++;
        curr = curr->next;
    }

    printf("\nLength is: %d\n", count);
    return count;
}

void insert (struct node *h) {
    int i = 1, pos;
    struct node *curr = h, *nnode;
    nnode = (struct node *) malloc(sizeof(struct node));

    printf("Enter new data: ");
    scanf("%d", &nnode->data);
    printf("Enter position for new data: ");
    scanf("%d", &pos);

    if (pos > (length(h)) + 1) {
        printf("Cannot be inserted\n");
        free(nnode);
        return;
    }

    while (curr != NULL && i < pos - 1) {
        i++;
        curr = curr->next;
    }

    nnode->next = curr->next;
    curr->next = nnode;
}

void delete(struct node *h) {
    struct node *prev = h, *curr;
    int counter = 1, position, l;
    curr = h->next;
    printf("Enter position to delete: ");
    scanf("%d", &position);

    l = length(h);

    if (l < position)
        printf("Cannot be deleted\n");

    else {
        while (counter < position && curr != NULL) {
            counter ++;
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        free(curr);
    }
}
