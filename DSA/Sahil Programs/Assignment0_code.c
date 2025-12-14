/*
Question 1:
Write a C Program to create a simple Student Record System using an array of structures. 
Each student record should contain Roll Number, Name, Percentage. The program should provide the following menu options: Insert, Display, Search, Update, Delete a student record, and Exit
*/

#include <stdio.h>
#include <conio.h>

struct Student {
    int rollNumber;
    char name[50];
    float percentage;
};

struct Student Students[100];
int StudentCount = 0;

void insertData() {
    printf("Enter Roll Number: ");
    scanf("%d", &Students[StudentCount].rollNumber);

    printf("Enter Name: ");
    scanf("%s", Students[StudentCount].name);

    printf("Enter Percentage: ");
    scanf("%f", &Students[StudentCount].percentage);

    StudentCount++;
}

void displayData() {
    for (int i = 0; i < StudentCount; i++) {
        printf("\nRoll Number: %d\n", Students[i].rollNumber);
        printf("Name: %s\n", Students[i].name);
        printf("Percentage: %.2f\n", Students[i].percentage);
    }
}

void search() {
    int roll;
    int found = 0;

    printf("Enter roll number: ");
    scanf("%d", &roll);

    for (int i = 0; i < StudentCount; i++) {
        if (Students[i].rollNumber == roll) {
            printf("\nRecord Found!\n");
            printf("Name: %s\nPercentage: %.2f\n", Students[i].name, Students[i].percentage);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Record Not Found!\n");
}

void update() {
    int roll;
    printf("Enter Roll Number to Update: ");
    scanf("%d", &roll);

    for (int i = 0; i < StudentCount; i++) {
        if (Students[i].rollNumber == roll) {
            printf("Enter new Name: ");
            scanf("%s", Students[i].name);

            printf("Enter new Percentage: ");
            scanf("%f", &Students[i].percentage);
        }
    }
}

void deleteData() {
    int roll, found = 0;
    printf("Enter Roll Number to Delete: ");
    scanf("%d", &roll);

    for (int i = 0; i < StudentCount; i++) {
        if (Students[i].rollNumber == roll) {
            for (int j = i; j < StudentCount - 1; j++) {
                Students[j] = Students[j + 1];
            }
            StudentCount--;
            found = 1;
            printf("Record Deleted!\n");
            break;
        }
    }

    if (!found)
        printf("Record Not Found!\n");
}

int main() {
    int choice;

    do {
        printf("\n1. Insert Data\n2. Display Data\n3. Search\n4. Update\n5. Delete\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertData(); break;
            case 2: displayData(); break;
            case 3: search(); break;
            case 4: update(); break;
            case 5: deleteData(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid Choice!\n");
        }
    } while (choice != 6);

    return 0;
}

