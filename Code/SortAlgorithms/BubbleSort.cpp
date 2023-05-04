#include <iostream>

using namespace std;

/**
 * Bubble Sort
 * Average complexity: O(n^2)
 * Best Case: O(n^2)
 * Worst Case: O(n^2)
 * Space: O(1)
 */
void BubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void BubbleSortRecursive(int arr[], int n)
{
    bool sorted = true;
    // we are assuming that array is sorted

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);

            sorted = false;
            // now array is not sorted
        }
        // if there are no swaps then we can
        // say that array is sorted.
    }
    if (sorted == false)
    {
        // recursively calling until it was sorted.
        BubbleSortRecursive(arr, n);
    }
}

/**
 * Bubble Sort Optimize
 * Average complexity: O(n^2)
 * Best Case: O(n)
 * Worst Case: O(n^2)
 * Space: O(1)
 * Stable
 */ 
void BubbleSortOptimize(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        bool sorted = true;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                sorted = false;
            }
        }
        if (sorted)
            break;
    }
}

void BubbleSortOptimizer(int arr[], int n)
{
    int i, j, lastSwap;
    for (i = 0; i < n - 1; i++) {
        lastSwap = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                lastSwap = j + 1;
            }
        }
        if (lastSwap == 0) {
            break;
        }
        i = n - lastSwap - 1;
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
    BubbleSortOptimizer(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}