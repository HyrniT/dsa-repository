#include <iostream>

using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int left[n1], right[n2];
    copy(arr + l, arr + l + n1, left);
    copy(arr + m + 1, arr + m + 1 + n2, right);
    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (left[i] < right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = left[i++];
    }

    while (j < n2)
    {
        arr[k++] = right[j++];
    }
}

/**
 * Merge Sort
 * Average complexity: O(nlogn)
 * Best Case: O(nlogn)
 * Worst Case: O(nlogn)
 * Space: O(n)
 * Not Stable (Can make it Stable)
 */
void MergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}


void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    MergeSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}