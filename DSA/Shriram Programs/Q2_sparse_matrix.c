#include <stdio.h>

#define MAX 100

struct Term {
    int row, col, val;
};

void readSparse(struct Term a[], int *n) {
    int rows, cols, nonZero, i;
    printf("Enter rows, cols, non-zero elements: ");
    scanf("%d%d%d", &rows, &cols, &nonZero);
    a[0].row = rows;
    a[0].col = cols;
    a[0].val = nonZero;
    for (i = 1; i <= nonZero; i++) {
        printf("Enter row, col, value for element %d: ", i);
        scanf("%d%d%d", &a[i].row, &a[i].col, &a[i].val);
    }
    *n = nonZero + 1;
}

void simpleTranspose(struct Term a[], struct Term b[]) {
    int i, j, n = a[0].val;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = n;
    int current = 1;
    for (i = 0; i < a[0].col; i++) {
        for (j = 1; j <= n; j++) {
            if (a[j].col == i) {
                b[current].row = a[j].col;
                b[current].col = a[j].row;
                b[current].val = a[j].val;
                current++;
            }
        }
    }
}

void fastTranspose(struct Term a[], struct Term b[]) {
    int rowTerms[MAX], startingPos[MAX];
    int i, j, numCols = a[0].col, numTerms = a[0].val;

    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = numTerms;

    if (numTerms > 0) {
        for (i = 0; i < numCols; i++)
            rowTerms[i] = 0;
        for (i = 1; i <= numTerms; i++)
            rowTerms[a[i].col]++;
        startingPos[0] = 1;
        for (i = 1; i < numCols; i++)
            startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
        for (i = 1; i <= numTerms; i++) {
            j = startingPos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].val = a[i].val;
        }
    }
}

void printSparse(struct Term a[]) {
    int i, n = a[0].val;
    printf("\nRow Col Val\n");
    for (i = 0; i <= n; i++) {
        printf("%d   %d   %d\n", a[i].row, a[i].col, a[i].val);
    }
}

int main() {
    struct Term a[MAX], b[MAX];
    int n;
    readSparse(a, &n);
    printf("\nOriginal sparse matrix (triplet form):\n");
    printSparse(a);

    simpleTranspose(a, b);
    printf("\nAfter simple transpose:\n");
    printSparse(b);

    fastTranspose(a, b);
    printf("\nAfter fast transpose:\n");
    printSparse(b);

    return 0;
}
