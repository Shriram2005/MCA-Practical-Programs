#include <stdio.h>
#include <string.h>

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

void sortByRoll(struct Student s[], int n) {
    int i, j;
    struct Student temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (s[j].roll > s[j+1].roll) {
                temp = s[j]; s[j] = s[j+1]; s[j+1] = temp;
            }
        }
    }
}

int binarySearch(struct Student s[], int n, int roll) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (s[mid].roll == roll) return mid;
        else if (roll < s[mid].roll) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main() {
    struct Student s[MAX];
    int n, roll, pos;
    inputStudents(s, &n);
    sortByRoll(s, n);
    printf("Enter roll to search: ");
    scanf("%d", &roll);
    pos = binarySearch(s, n, roll);
    if (pos == -1) printf("Student not found.\n");
    else printf("Found: %d %s %.2f\n", s[pos].roll, s[pos].name, s[pos].percentage);
    return 0;
}
