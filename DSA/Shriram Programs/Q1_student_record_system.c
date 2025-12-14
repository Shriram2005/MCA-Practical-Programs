#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int roll;
    char name[50];
    float percentage;
};

void insertStudent(struct Student s[], int *n) {
    if (*n >= MAX_STUDENTS) {
        printf("\nRecord full!\n");
        return;
    }
    printf("\nEnter Roll, Name, Percentage: ");
    scanf("%d", &s[*n].roll);
    scanf("%s", s[*n].name);
    scanf("%f", &s[*n].percentage);
    (*n)++;
}

void displayStudents(struct Student s[], int n) {
    int i;
    if (n == 0) {
        printf("\nNo records.\n");
        return;
    }
    printf("\n%-10s %-20s %-10s\n", "Roll", "Name", "Percent");
    for (i = 0; i < n; i++) {
        printf("%-10d %-20s %-10.2f\n", s[i].roll, s[i].name, s[i].percentage);
    }
}

int searchStudent(struct Student s[], int n, int roll) {
    int i;
    for (i = 0; i < n; i++) {
        if (s[i].roll == roll)
            return i;
    }
    return -1;
}

void updateStudent(struct Student s[], int n) {
    int roll, pos;
    printf("\nEnter roll to update: ");
    scanf("%d", &roll);
    pos = searchStudent(s, n, roll);
    if (pos == -1) {
        printf("Record not found.\n");
        return;
    }
    printf("Enter new Name and Percentage: ");
    scanf("%s", s[pos].name);
    scanf("%f", &s[pos].percentage);
}

void deleteStudent(struct Student s[], int *n) {
    int roll, pos, i;
    printf("\nEnter roll to delete: ");
    scanf("%d", &roll);
    pos = searchStudent(s, *n, roll);
    if (pos == -1) {
        printf("Record not found.\n");
        return;
    }
    for (i = pos; i < *n - 1; i++) {
        s[i] = s[i + 1];
    }
    (*n)--;
    printf("Record deleted.\n");
}

int main() {
    struct Student s[MAX_STUDENTS];
    int n = 0, ch, roll, pos;

    do {
        printf("\n--- Student Record System ---\n");
        printf("1. Insert\n2. Display\n3. Search\n4. Update\n5. Delete\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            insertStudent(s, &n);
            break;
        case 2:
            displayStudents(s, n);
            break;
        case 3:
            printf("Enter roll to search: ");
            scanf("%d", &roll);
            pos = searchStudent(s, n, roll);
            if (pos == -1)
                printf("Not found.\n");
            else
                printf("Found: %d %s %.2f\n", s[pos].roll, s[pos].name, s[pos].percentage);
            break;
        case 4:
            updateStudent(s, n);
            break;
        case 5:
            deleteStudent(s, &n);
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (ch != 6);

    return 0;
}
