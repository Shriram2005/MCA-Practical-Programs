#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for attendance record
struct Attendance {
    int empID;
    char empName[50];
    char date[20];
    char status[15];
    struct Attendance *next;
};

struct Attendance *head = NULL;

// Create a new node
struct Attendance* createNode(int id, char name[], char date[], char status[]) {
    struct Attendance *newNode = (struct Attendance*)malloc(sizeof(struct Attendance));
    newNode->empID = id;
    strcpy(newNode->empName, name);
    strcpy(newNode->date, date);
    strcpy(newNode->status, status);
    newNode->next = NULL;
    return newNode;
}

// Insert attendance record
void insertRecord() {
    int id;
    char name[50], date[20], status[15];

    printf("\nEnter Employee ID: ");
    scanf("%d", &id);

    printf("Enter Employee Name: ");
    scanf("%s", name);

    printf("Enter Date (DD/MM/YYYY): ");
    scanf(" %[^\n]", date);

    printf("Enter Status (Present/Absent): ");
    scanf("%s", status);

    struct Attendance *newNode = createNode(id, name, date, status);

    if (head == NULL)
        head = newNode;
    else {
        struct Attendance *temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }

    printf("\n✔ Record Inserted Successfully!\n");
}

// Remove a record by employee ID
void removeRecord() {
    if (head == NULL) {
        printf("\nNo records to delete.\n");
        return;
    }

    int id;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &id);

    struct Attendance *temp = head, *prev = NULL;

    // Delete at head
    if (temp != NULL && temp->empID == id) {
        head = temp->next;
        free(temp);
        printf("\n✔ Record Deleted Successfully!\n");
        return;
    }

    // Search in list
    while (temp != NULL && temp->empID != id) {
        prev = temp;
        temp = temp->next;
    }

    // If not found
    if (temp == NULL) {
        printf("\nRecord Not Found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("\n✔ Record Deleted Successfully!\n");
}

// Change status for a specific employee & date
void changeStatus() {
    int id;
    char date[20];

    printf("\nEnter Employee ID: ");
    scanf("%d", &id);

    printf("Enter Date (DD/MM/YYYY): ");
    scanf(" %[^\n]", date);

    struct Attendance *temp = head;

    while (temp != NULL) {
        if (temp->empID == id && strcmp(temp->date, date) == 0) {
            printf("Current Status = %s\n", temp->status);
            printf("Enter New Status (Present/Absent): ");
            scanf("%s", temp->status);

            printf("\n✔ Status Updated Successfully!\n");
            return;
        }
        temp = temp->next;
    }

    printf("\nRecord Not Found!\n");
}

// Show all attendance records
void showAll() {
    if (head == NULL) {
        printf("\nNo attendance records found.\n");
        return;
    }

    struct Attendance *temp = head;

    printf("\n========== ALL ATTENDANCE RECORDS ==========\n");

    while (temp != NULL) {
        printf("\nEmployee ID   : %d", temp->empID);
        printf("\nEmployee Name : %s", temp->empName);
        printf("\nDate          : %s", temp->date);
        printf("\nStatus        : %s\n", temp->status);
        printf("--------------------------------------------\n");
        temp = temp->next;
    }
}

// Search attendance history by employee ID
void searchHistory() {
    int id;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);

    struct Attendance *temp = head;
    int found = 0;

    printf("\n======= ATTENDANCE HISTORY FOR EMP ID %d =======\n", id);

    while (temp != NULL) {
        if (temp->empID == id) {
            found = 1;
            printf("\nEmployee Name : %s", temp->empName);
            printf("\nDate          : %s", temp->date);
            printf("\nStatus        : %s\n", temp->status);
            printf("--------------------------------------------\n");
        }
        temp = temp->next;
    }

    if (!found)
        printf("\nNo records found for this employee.\n");
}

// Main Menu
int main() {
    int choice;

    while (1) {
        printf("\n========== EMPLOYEE ATTENDANCE SYSTEM ==========\n");
        printf("1. Insert Attendance Record\n");
        printf("2. Remove Attendance Record\n");
        printf("3. Change Attendance Status\n");
        printf("4. Show All Records\n");
        printf("5. Search Attendance History\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertRecord(); break;
            case 2: removeRecord(); break;
            case 3: changeStatus(); break;
            case 4: showAll(); break;
            case 5: searchHistory(); break;
            case 6: exit(0);
            default: printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}

