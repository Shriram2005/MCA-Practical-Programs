#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    char phone[20];
    struct Node *left, *right;
};

struct Node* createNode(const char *name, const char *phone) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    strcpy(n->name, name);
    strcpy(n->phone, phone);
    n->left = n->right = NULL;
    return n;
}

struct Node* insert(struct Node *root, const char *name, const char *phone) {
    if (!root) return createNode(name, phone);
    int cmp = strcmp(name, root->name);
    if (cmp < 0) root->left = insert(root->left, name, phone);
    else if (cmp > 0) root->right = insert(root->right, name, phone);
    else strcpy(root->phone, phone);
    return root;
}

struct Node* findMin(struct Node *root) {
    while (root && root->left) root = root->left;
    return root;
}

struct Node* deleteNode(struct Node *root, const char *name) {
    if (!root) return NULL;
    int cmp = strcmp(name, root->name);
    if (cmp < 0) root->left = deleteNode(root->left, name);
    else if (cmp > 0) root->right = deleteNode(root->right, name);
    else {
        if (!root->left) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        } else {
            struct Node *temp = findMin(root->right);
            strcpy(root->name, temp->name);
            strcpy(root->phone, temp->phone);
            root->right = deleteNode(root->right, temp->name);
        }
    }
    return root;
}

struct Node* search(struct Node *root, const char *name) {
    if (!root) return NULL;
    int cmp = strcmp(name, root->name);
    if (cmp == 0) return root;
    else if (cmp < 0) return search(root->left, name);
    else return search(root->right, name);
}

void inorder(struct Node *root) {
    if (!root) return;
    inorder(root->left);
    printf("%s : %s\n", root->name, root->phone);
    inorder(root->right);
}

int main() {
    struct Node *root = NULL, *temp;
    int ch;
    char name[50], phone[20];
    do {
        printf("\n1.Insert 2.Search 3.Delete 4.Print All 5.Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("Enter name and phone: ");
            scanf("%s %s", name, phone);
            root = insert(root, name, phone);
            break;
        case 2:
            printf("Enter name to search: ");
            scanf("%s", name);
            temp = search(root, name);
            if (temp) printf("Found: %s -> %s\n", temp->name, temp->phone);
            else printf("Not found.\n");
            break;
        case 3:
            printf("Enter name to delete: ");
            scanf("%s", name);
            root = deleteNode(root, name);
            break;
        case 4:
            printf("Phone list (inorder):\n");
            inorder(root);
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (ch != 5);
    return 0;
}
