#include <stdio.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d numbers:\n", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    clock_t start, end;

    start = clock();

    insertionSort(arr, n);

    end = clock();

    printf("\nSorted array:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    double runtime_ms = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;

    printf("\n\nRuntime: %.6f ms\n", runtime_ms);

    return 0;
}
