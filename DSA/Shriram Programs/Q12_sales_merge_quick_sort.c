#include <stdio.h>
#include <string.h>

#define MAX 100

struct Sale {
    int id;
    char customer[50];
    char product[50];
    int qty;
    float total;
};

void inputSales(struct Sale a[], int *n) {
    int i;
    printf("Enter number of sales: ");
    scanf("%d", n);
    for (i = 0; i < *n; i++) {
        printf("Enter id, customer, product, qty, total: ");
        scanf("%d %s %s %d %f", &a[i].id, a[i].customer, a[i].product, &a[i].qty, &a[i].total);
    }
}

void merge(struct Sale a[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    struct Sale L[MAX], R[MAX];
    int i, j, k;
    for (i = 0; i < n1; i++) L[i] = a[l + i];
    for (j = 0; j < n2; j++) R[j] = a[m + 1 + j];
    i = j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i].total >= R[j].total) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void mergeSort(struct Sale a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int partition(struct Sale a[], int low, int high) {
    float pivot = a[high].total;
    int i = low - 1, j;
    struct Sale temp;
    for (j = low; j < high; j++) {
        if (a[j].total >= pivot) {
            i++;
            temp = a[i]; a[i] = a[j]; a[j] = temp;
        }
    }
    temp = a[i+1]; a[i+1] = a[high]; a[high] = temp;
    return i + 1;
}

void quickSort(struct Sale a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

void printSales(struct Sale a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d %s %s %d %.2f\n", a[i].id, a[i].customer, a[i].product, a[i].qty, a[i].total);
    }
}

int main() {
    struct Sale a[MAX];
    int n, ch;
    inputSales(a, &n);
    printf("1.Merge Sort 2.Quick Sort\nEnter choice: ");
    scanf("%d", &ch);
    if (ch == 1) mergeSort(a, 0, n - 1);
    else quickSort(a, 0, n - 1);
    printf("Sorted sales (by total desc):\n");
    printSales(a, n);
    return 0;
}
