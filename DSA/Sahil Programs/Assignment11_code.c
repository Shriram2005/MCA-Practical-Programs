/*
Question 12:
Write a program to sort a list of sales data for a retail company. Each record represents a sale and contains the following information: sales ID, customer name, product name, quantity sold, and total sale amount. sort the sales data based on the total sale amount in descending order using the Merge Sort algorithm./ Quick sort method
*/

#include <stdio.h>

struct Sales {
    int id;
    char cust[20];
    char product[20];
    int qty;
    float amt;
} s[50], temp[50];

void merge(int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high) {
        if (s[i].amt > s[j].amt)      
            temp[k++] = s[i++];
        else
            temp[k++] = s[j++];
    }

    while (i <= mid) temp[k++] = s[i++];
    while (j <= high) temp[k++] = s[j++];

    for (i = low; i <= high; i++)
        s[i] = temp[i];
}

void mergeSort(int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main() {
    int n;
    printf("Enter number of records: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter ID, Customer, Product, Qty, Amount: ");
        scanf("%d %s %s %d %f",
              &s[i].id, s[i].cust, s[i].product, &s[i].qty, &s[i].amt);
    }

    mergeSort(0, n - 1);

    printf("\n--- Sorted Sales Records (by Amount DESC) ---\n");
    for (int i = 0; i < n; i++)
        printf("%d %s %s %d %.2f\n",
               s[i].id, s[i].cust, s[i].product, s[i].qty, s[i].amt);

    return 0;
}


