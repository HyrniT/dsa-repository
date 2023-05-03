#include <iostream>

using namespace std;

/**
 * Selection Sort
 * Average complexity: O(n^2)
 * Best Case: O(n^2)
 * Worst Case: O(n^2)
 * Space: O(1)
 * Stable
 */
void SelectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(arr[i], arr[min_idx]);
    }
}

/**
 * Selection Sort Optimize
 * Average complexity: O(n^2)
 * Best Case: O(n^2)
 * Worst Case: O(n^2)
 * Space: O(1)
 * Not Stable (Can make it Stable)
 */ 
void SelectionSortOptimize(int arr[], int n)
{
    int i, j, min_idx, max_idx, r = n;
    for (i = 0; i < r - 1; i++)
    {
        min_idx = i;
        max_idx = i;
        for (j = i + 1; j < r; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
            if (arr[j] > arr[max_idx])
                max_idx = j;
        }
        swap(arr[i], arr[min_idx]);
        if (max_idx == i)
            max_idx = min_idx;
        r--;
        swap(arr[r], arr[max_idx]);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    // SelectionSort(arr, n);
    SelectionSortOptimize(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}