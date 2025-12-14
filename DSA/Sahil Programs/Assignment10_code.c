/*
Question 11:
Write a program to arrange list of students to find out first ten toppers from a class using Bubble sort. (refer the student database given in assignment 10)
*/

#include <stdio.h>

struct Student {
    int roll;
    char name[20];
    float marks;
} s[50];

int main() {
    int n, i, j;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Roll, Name, Marks: ");
        scanf("%d %s %f", &s[i].roll, s[i].name, &s[i].marks);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (s[j].marks < s[j + 1].marks) {
                struct Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    printf("\n--- Top 10 Toppers ---\n");

    int limit = (n < 10) ? n : 10; 

    for (i = 0; i < limit; i++) {
        printf("%d. %s (Marks: %.2f)\n", i + 1, s[i].name, s[i].marks);
    }

    return 0;
}

