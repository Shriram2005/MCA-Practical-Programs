#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    struct Book *next;
};

struct Book *head = NULL;

struct Book* createNode(int id, const char *title) {
    struct Book *temp = (struct Book*)malloc(sizeof(struct Book));
    temp->id = id;
    strcpy(temp->title, title);
    temp->next = NULL;
    return temp;
}

void addBook() {
    int id;
    char title[50];
    printf("Enter book id and title: ");
    scanf("%d", &id);
    scanf("%s", title);

    struct Book *newNode = createNode(id, title);
    newNode->next = head;
    head = newNode;
}

void removeBook() {
    int id;
    printf("Enter book id to remove: ");
    scanf("%d", &id);
    struct Book *temp = head, *prev = NULL;
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Book not found.\n");
        return;
    }
    if (prev == NULL)
        head = head->next;
    else
        prev->next = temp->next;
    free(temp);
    printf("Book removed.\n");
}

void displayBooks() {
    struct Book *temp = head;
    if (!temp) {
        printf("No books.\n");
        return;
    }
    printf("\nBooks:\n");
    while (temp) {
        printf("ID: %d, Title: %s\n", temp->id, temp->title);
        temp = temp->next;
    }
}

void searchBook() {
    int id;
    printf("Enter book id to search: ");
    scanf("%d", &id);
    struct Book *temp = head;
    while (temp && temp->id != id)
        temp = temp->next;
    if (!temp)
        printf("Book not found.\n");
    else
        printf("Found: ID: %d, Title: %s\n", temp->id, temp->title);
}

void countBooks() {
    int count = 0;
    struct Book *temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    printf("Total books: %d\n", count);
}

int main() {
    int ch;
    do {
        printf("\n1.Add 2.Remove 3.Display 4.Search 5.Count 6.Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1: addBook(); break;
        case 2: removeBook(); break;
        case 3: displayBooks(); break;
        case 4: searchBook(); break;
        case 5: countBooks(); break;
        case 6: printf("Exiting...\n"); break;
        default: printf("Invalid choice.\n");
        }
    } while (ch != 6);
    return 0;
}
