#include <stdio.h>

void merge(int a[], int p, int mid, int q)
{
    int i = p, j = mid + 1, k = p;
    int b[20];

    while (i <= mid && j <= q)
    {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    while (i <= mid)
        b[k++] = a[i++];

    while (j <= q)
        b[k++] = a[j++];

    for (i = p; i <= q; i++)
        a[i] = b[i];
}

void mergesort(int a[], int p, int q)
{
    int mid;

    if (p < q)
    {
        mid = (p + q) / 2;

        mergesort(a, p, mid);
        mergesort(a, mid + 1, q);

        merge(a, p, mid, q);
    }
}

int main()
{
    int a[] = {7, 6, 4, 2, 9, 8, 3, 5};
    int n = 8;
    int i;

    mergesort(a, 0, n - 1);

    printf("Sorted array: ");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}