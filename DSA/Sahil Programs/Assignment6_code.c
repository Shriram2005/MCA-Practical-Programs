/*
Question 7:
Write a program that reads a list of names and telephone numbers from user and insert into a BST tree. Once the tree has been built, present the user with a menu that allows him to search the list for a specified name, insert a new name, delete an existing name or print the entire phone list.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[50];
    char phone[15];
    struct node *left, *right;
};

struct node* createNode(char name[], char phone[])
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, char name[], char phone[])
{
    if (root == NULL)
        return createNode(name, phone);

    if (strcmp(name, root->name) < 0)
        root->left = insert(root->left, name, phone);
    else if (strcmp(name, root->name) > 0)
        root->right = insert(root->right, name, phone);
    else
        printf("Duplicate name not allowed!\n");

    return root;
}

struct node* search(struct node* root, char name[])
{
    if (root == NULL || strcmp(root->name, name) == 0)
        return root;

    if (strcmp(name, root->name) < 0)
        return search(root->left, name);
    else
        return search(root->right, name);
}

struct node* findMin(struct node* root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct node* deleteNode(struct node* root, char name[])
{
    if (root == NULL)
        return root;

    if (strcmp(name, root->name) < 0)
        root->left = deleteNode(root->left, name);
    else if (strcmp(name, root->name) > 0)
        root->right = deleteNode(root->right, name);
    else
    {
        if (root->left == NULL)
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = findMin(root->right);
        strcpy(root->name, temp->name);
        strcpy(root->phone, temp->phone);
        root->right = deleteNode(root->right, temp->name);
    }
    return root;
}

void inorder(struct node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("Name: %-20s Phone: %s\n", root->name, root->phone);
        inorder(root->right);
    }
}

int main()
{
    struct node* root = NULL;
    int choice;
    char name[50], phone[15];

    do
    {
        printf("\n--- Phone Book Menu ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Print Phone List\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone: ");
                scanf("%s", phone);
                root = insert(root, name, phone);
                break;

            case 2:
            {
                printf("Enter name to search: ");
                scanf("%s", name);
                struct node* result = search(root, name);
                if (result)
                    printf("Phone Number: %s\n", result->phone);
                else
                    printf("Name not found!\n");
                break;
            }

            case 3:
                printf("Enter name to delete: ");
                scanf("%s", name);
                root = deleteNode(root, name);
                break;

            case 4:
                printf("\n--- Phone List ---\n");
                inorder(root);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}  



