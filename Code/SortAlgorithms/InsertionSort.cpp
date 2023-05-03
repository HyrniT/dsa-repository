#include <iostream>

using namespace std;

/**
 * Insertion Sort
 * Average complexity: O(n^2)
 * Best Case: O(n^2)
 * Worst Case: O(n^2)
 * Space: O(1)
 * Stable
 */
void InsertionSort(int arr[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void InsertionSortRecursive(int arr[], int n)
{
    // Base case: if the array has only one element, it is already sorted
    if (n <= 1)
        return;

    // Sort the first n-1 elements of the array recursively
    InsertionSortRecursive(arr, n - 1);

    // Insert the nth element into its correct position in the sorted subarray
    int last = arr[n - 1];          // (n - 1) ~ i
    int j = n - 2;                  // (n - 2) ~ (i - 1)

    // Shift elements to the right to make space for the nth element
    while (j >= 0 && arr[j] > last)
    {
        arr[j + 1] = arr[j];
        j--;
    }

    // Place the nth element in its correct position
    arr[j + 1] = last;
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
    InsertionSortRecursive(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}