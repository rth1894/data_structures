#include <stdio.h>
#include <stdlib.h>
#define size 100

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int lbit;
    int rbit;
};

void create(struct Node* head) {
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    char yesno;
    printf("Enter data for root: ");
    scanf("%d", &root->data);
    head->lbit = 1;
    root->left = head;
    root->right = head;
    root->lbit = 0;
    root->rbit = 0;
    head->left = root;

    do {
        int flag = 0;
        char choice;
        struct Node* temp = root;
        struct Node* curr = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data: %d", temp->data);
        scanf("%d", &curr->data);
        curr->lbit = 0;
        curr->rbit = 0;
        while (flag == 0) {
            printf("Do you want to enter to left or right of %d? (l/r): ", temp->data);
            scanf(" %c", &choice);
            if (choice == 'l' || choice == 'L') {
                if (temp->lbit == 0) {
                    curr->right = temp;
                    curr->left = temp->left;
                    temp->left = curr;
                    temp->lbit = 1;
                    flag = 1;
                }
                else
                    temp = temp->left;
            }
            if (choice == 'r' || choice == 'R') {
                if (temp->rbit == 0) {
                    curr->left= temp;
                    curr->right = temp->right;
                    temp->right= curr;
                    temp->rbit = 1;
                    flag = 1;
                }
                else
                    temp = temp->right;
            }
        }
        printf("do you want to continue? (y/n): ");
        scanf(" %c", &yesno);
    } while (yesno == 'y' || yesno == 'Y');
}

struct Node* inorderSuccesor(struct Node* temp) {
    struct Node* x = temp->right;
    if (temp->rbit == 1)
        while (x->lbit == 1)
            x = x->left;
    return x;
}


void inorder(struct Node* head) {
    struct Node* temp = head;
    while (1) {
        temp = inorderSuccesor(temp);
        if (temp == head)
            break;
        printf("%d\t", temp->data);
    }
    printf("\n");
}


void preorder(struct Node* head){
    struct Node* temp = head->left;
    while (temp != head){
        printf("%d\t", temp->data);
        while (temp->lbit == 1){
            temp = temp->left;
            printf("%d\t", temp->data);
        }
        while (temp->rbit == 0)
            temp = temp->right;
        temp=temp->right;
    }
    printf("\n");
}

int main(){
    struct Node* head = (struct Node*) malloc(sizeof(struct Node));
    head->lbit = 0;
    head->rbit = 1;
    head->left = head->right = head;

    char choice;
    do {
        printf("\n1. Create tree\n2. Inorder Display\n3. Preorder Display\n4. Exit\n> ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                create(head);
                break;
            case '2':
                inorder(head);
                break;
            case '3':
                preorder(head);
                break;
            case '4':
                printf("Exited!\n");
                break;
            default:
                printf("Enter valid choice\n");
        }
    } while (choice != '4');
    return 0;
}
