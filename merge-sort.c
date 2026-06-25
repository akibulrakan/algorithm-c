#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *b;

void Merge(int A[], int lb, int mid, int ub) {
    int i = lb;
    int j = mid + 1;
    int k = lb;

    while (i <= mid && j <= ub) {
        if (A[i] <= A[j]) {
            b[k] = A[i];
            i++;
            k++;
        } else {
            b[k] = A[j];
            j++;
            k++;
        }
    }

    if (i > mid) {
        while (j <= ub) {
            b[k] = A[j];
            k++;
            j++;
        }
    } else {
        while (i <= mid) {
            b[k] = A[i];
            k++;
            i++;
        }
    }

    for (k = lb; k <= ub; k++) {
        A[k] = b[k];
    }
}

void MergeSort(int A[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;

        MergeSort(A, lb, mid);
        MergeSort(A, mid + 1, ub);

        Merge(A, lb, mid, ub);
    }
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1)
        return 1;

    int *A = (int *)malloc(n * sizeof(int));
    b = (int *)malloc(n * sizeof(int));

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &A[i]) != 1)
            return 1;
    }

    clock_t start = clock();

    MergeSort(A, 0, n - 1);

    clock_t end = clock();

    double time_taken_ms =
        ((double)(end - start) * 1000.0) / CLOCKS_PER_SEC;

    printf("\nSorting complete.\n");
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    printf("Execution time: %f ms\n", time_taken_ms);

    free(A);
    free(b);

    return 0;
}
