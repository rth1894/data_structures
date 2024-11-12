#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int prn;
    char name[50];
    struct Node *next;
};

struct Node* createNode(int prn, char name[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->prn = prn;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

void addMember(struct Node** head, int prn, char name[]) {
    struct Node* newNode = createNode(prn, name);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void addPresident(struct Node** head, int prn, char name[]) {
    struct Node* newNode = createNode(prn, name);
    newNode->next = *head;
    *head = newNode;
}

void addSecretary(struct Node** head, int prn, char name[]) {
    addMember(head, prn, name);
}

void deleteMember(struct Node** head, int prn) {
    struct Node *temp = *head, *prev = NULL;
    if (temp != NULL && temp->prn == prn) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->prn != prn) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Member not found.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void display(struct Node* head) {
    struct Node* temp = head;
    printf("Club Members:\n");
    while (temp != NULL) {
        printf("PRN: %d, Name: %s\n", temp->prn, temp->name);
        temp = temp->next;
    }
}

int countMembers(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void sortList(struct Node** head) {
    struct Node *i, *j;
    int tempPrn;
    char tempName[50];

    for (i = *head; i != NULL && i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->prn > j->prn) {
                tempPrn = i->prn;
                strcpy(tempName, i->name);

                i->prn = j->prn;
                strcpy(i->name, j->name);

                j->prn = tempPrn;
                strcpy(j->name, tempName);
            }
        }
    }
}

struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    if (head1->prn < head2->prn) {
        head1->next = mergeLists(head1->next, head2);
        return head1;
    } else {
        head2->next = mergeLists(head1, head2->next);
        return head2;
    }
}

void reverseList(struct Node** head) {
    struct Node *prev = NULL, *current = *head, *next = NULL;

    while (current != NULL) {
        next = current->next; 
        current->next = prev; 
        prev = current;       
        current = next;
    }
    *head = prev; 
}

int main() {
    struct Node* club = NULL;
    int choice, prn;
    char name[50];
    
    printf("Welcome to Pinnacle Club Membership Management System\n");

    
    printf("Enter PRN for President: ");
    scanf("%d", &prn);
    printf("Enter name of President: ");
    scanf(" %[^\n]s", name); 
    addPresident(&club, prn, name);

    while (1) {
        printf("\n1. Add Member\n2. Add Secretary\n3. Delete Member\n4. Display Members\n5. Sort Members\n6. Reverse List\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter PRN for Member: ");
                scanf("%d", &prn);
                printf("Enter name of Member: ");
                scanf(" %[^\n]s", name); 
                addMember(&club, prn, name);
                break;
            case 2:
                printf("Enter PRN for Secretary: ");
                scanf("%d", &prn);
                printf("Enter name of Secretary: ");
                scanf(" %[^\n]s", name); 
                addSecretary(&club, prn, name);
                break;
            case 3:
                printf("Enter PRN of the member to delete: ");
                scanf("%d", &prn);
                deleteMember(&club, prn);
                break;
            case 4:
                display(club);
                break;
            case 5:
                sortList(&club);
                printf("List sorted by PRN.\n");
                display(club);
                break;
            case 6:
                reverseList(&club);
                printf("List reversed.\n");
                display(club);
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    
    return 0;
}
