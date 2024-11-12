#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void create(struct node *head) {
    char choice;
    struct node *curr, *temp;
    int data;

    temp = head;
    do {
        curr = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data of node: ");
        scanf("%d", &data);
        curr->data = data; 
        curr->next = NULL; 
        temp->next = curr; 
        temp = temp->next;    
    
        printf("Add another node? (y/n): ");
        scanf(" %c", &choice);
    } while(choice == 'y' || choice == 'Y');
}

void display(struct node *head) {
    struct node *curr;

    if (head->next == NULL) {
        printf("List is empty\n");
    } else {
        curr = head->next;
        while (curr != NULL) {
            printf("Node: Address=%d, Data=%d, Next=%d\n", curr, curr->data, curr->next);
            curr = curr->next;
        }
    }
}

void length(struct node *head){
  struct node *curr;
  curr = head->next;
  int i=0;
  while(curr!=NULL)
  {
    i++;
    curr=curr->next;
  }
  printf("the length is %d", i);
  return(i);
}
/*void insertbypos(struct node *head){
  int i;
  i=1;
  curr=
}*/
int main() {
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;

    create(head);
    display(head);
    length(head);

    return 0;
}
