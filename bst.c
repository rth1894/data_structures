#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int f = -1;
int r = -1;
int n = 40;

typedef struct binary_tree {
    char word[20];
    char meaning[20];
    struct binary_tree *left;
    struct binary_tree *right;
} bst;

struct binary_tree *q[40];

int isfull() {
    return (r == n - 1);
}

int isempty() {
    return (f == r);
}

bst *delequeue() {
    if (isempty()) {
        printf("Queue is empty\n");
        return NULL;
    } else {
        f++;
        return q[f];
    }
}

void addqueue(bst *temp) {
    if (isfull())
        printf("Queue is full\n");
    else {
        r++;
        q[r] = temp;
    }
}

void bft(bst *root) {
    int p = 1;
    int q = 0;
    bst *temp = root;
    addqueue(temp);
    printf("\n");
    while (!isempty()) {
        for (int i = 0; i < p; i++) {
            temp = delequeue();
            if (temp == NULL)
                printf("BST is empty!\n");
            printf("word: %s meaning: %s\n", temp->word, temp->meaning);
            if (temp->left != NULL) {
                addqueue(temp->left);
                q++;
            }
            if (temp->right != NULL) {
                addqueue(temp->right);
                q++;
            }
        }
        p = q;
        q = 0;
    }
}

void create(bst *root) {
    int flag;
    char choice;
    do {
        bst *temp = root;
        flag = 0;
        bst *current = (bst *)malloc(sizeof(bst));
        current->left = NULL;
        current->right = NULL;
        
        printf("Enter word: ");
        scanf(" %s", current->word);
        printf("Enter meaning: ");
        scanf(" %s", current->meaning);
       
        while (flag == 0) {
            if (strcmp(current->word, temp->word) < 0) {
                if (temp->left == NULL) {
                    temp->left = current;
                    flag = 1;
                } else {
                    temp = temp->left;
                }
            } else {
                if (temp->right == NULL) {
                    temp->right = current;
                    flag = 1;
                } else {
                    temp = temp->right;
                }
            }
        }
        printf("Do you want to add a new node? (y/n)");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
}

bst* search_nr(bst *root, char *key, bst **parent) {
    bst *temp = root;
    *parent = NULL;
    while (temp != NULL) {
        if (strcmp(key, temp->word) == 0) {
            return temp;
        }
        *parent = temp;
        if (strcmp(key, temp->word) < 0) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    printf("Keyword not found.\n");
    return NULL;
}

bst* delete(bst *root, char *key) {
    bst *parent = NULL;
    bst *curr = search_nr(root, key, &parent);

    if (curr == NULL) {
        return root;
    }

    if (curr == root) {
        if (curr->right == NULL) {
            root = root->left;
        } else if (curr->left == NULL) {
            root = root->right;
        } else {
            bst *temp = curr->left;
            root = curr->right;
            bst *s = curr->right;
            while (s->left != NULL) {
                s = s->left;
            }
            s->left = temp;
        }
        free(curr);
        return root;
    }

    if (curr != root) {
        if (curr->left == NULL && curr->right == NULL) {
            if (parent->left == curr) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
        } else if (curr->left == NULL) {
            if (parent->left == curr) {
                parent->left = curr->right;
            } else {
                parent->right = curr->right;
            }
        } else if (curr->right == NULL) {
            if (parent->left == curr) {
                parent->left = curr->left;
            } else {
                parent->right = curr->left;
            }
        } else {
            bst *temp = curr->left;
            bst *s = curr->right;
            while (s->left != NULL) {
                s = s->left;
            }
            s->left = temp;

            if (parent->left == curr) {
                parent->left = curr->right;
            } else {
                parent->right = curr->right;
            }
        }
        free(curr);
    }
    return root;
}

void mirror_r(bst *root) {
    bst *temp = root->left;
    root->left = root->right;
    root->right = temp;

    if (root->left != NULL) {
        mirror_r(root->left);
    }
    if (root->right != NULL) {
        mirror_r(root->right);
    }
}

bst *copy_r(bst *root) {
    bst *temp = NULL;
    if (root != NULL) {
        temp = (bst *)malloc(sizeof(bst));
        strcpy(temp->word, root->word);
        strcpy(temp->meaning, root->meaning);
        temp->left = copy_r(root->left);
        temp->right = copy_r(root->right);
    }
    return temp;
}

int main() {
    bst *root = NULL;
    root = (bst *)malloc(sizeof(bst));
    
    printf("Enter root: ");
    scanf(" %s", root->word);
    printf("Enter meaning: ");
    scanf(" %s", root->meaning);

    root->left = root->right = NULL;
    int choice;
    char value[20];

    do {
        printf("1. Add Node\n2. Delete Node\n3. Display (BFS)\n4. Mirror Tree\n5. Copy Tree\n6. Exit\n> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create(root);
                break;
            case 2:
                printf("Enter the node you want to delete: ");
                scanf(" %s", value);
                root = delete(root, value);
                bft(root);
                break;
            case 3:
                printf("Breadth-First Traversal:\n");
                bft(root);
                break;
            case 4:
                mirror_r(root);
                printf("Tree mirrored successfully!\n");
                bft(root);
                break;
            case 5:
                bst *copy = copy_r(root);
                printf("Tree copied successfully!\n");
                bft(copy);
                break;
            case 6:
                printf("Exited!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
