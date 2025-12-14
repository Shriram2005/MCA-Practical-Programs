#include <stdio.h>

#define MAX 100

struct Student {
    int roll;
    char name[50];
    float percentage;
};

void inputStudents(struct Student s[], int *n) {
    int i;
    printf("Enter number of students: ");
    scanf("%d", n);
    for (i = 0; i < *n; i++) {
        printf("Enter roll, name, percentage: ");
        scanf("%d %s %f", &s[i].roll, s[i].name, &s[i].percentage);
    }
}

void bubbleSort(struct Student s[], int n) {
    int i, j;
    struct Student temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (s[j].percentage < s[j+1].percentage) {
                temp = s[j]; s[j] = s[j+1]; s[j+1] = temp;
            }
        }
    }
}

int main() {
    struct Student s[MAX];
    int n, i, limit;
    inputStudents(s, &n);
    bubbleSort(s, n);
    limit = n < 10 ? n : 10;
    printf("Top %d students:\n", limit);
    for (i = 0; i < limit; i++) {
        printf("%d %s %.2f\n", s[i].roll, s[i].name, s[i].percentage);
    }
    return 0;
}
