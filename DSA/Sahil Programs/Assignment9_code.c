/*
Question 10:
Write a program to create student database. Database contains different fields of student like Roll No, Name and percentage. Search a particular student according to roll number using binary search.
*/

#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[20];
    float marks;
} s[50];

int n = 0;

void insert() {
    printf("Enter Roll, Name, Marks: ");
    scanf("%d %s %f", &s[n].roll, s[n].name, &s[n].marks);
    n++;
}

void display() {
    printf("\nRoll\tName\tMarks\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%s\t%.2f\n", s[i].roll, s[i].name, s[i].marks);
}

void sort() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].roll > s[j + 1].roll) {
                struct Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

void search() {
    int r, low = 0, high = n - 1, mid;
    printf("Enter roll to search: ");
    scanf("%d", &r);

    while (low <= high) {
        mid = (low + high) / 2;

        if (s[mid].roll == r) {
            printf("\nRecord Found:\n");
            printf("%d %s %.2f\n", s[mid].roll, s[mid].name, s[mid].marks);
            return;
        }
        else if (r < s[mid].roll)
            high = mid - 1;
        else
            low = mid + 1;
    }

    printf("Record not found\n");
}

int main() {
    int ch;

    do {
        printf("\n1. Insert\n2. Display\n3. Search\n4. Exit\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insert();
                sort(); 
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
        }

    } while (ch != 4);

    return 0;
}




