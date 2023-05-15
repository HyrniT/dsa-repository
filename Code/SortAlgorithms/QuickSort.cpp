#include <iostream>

using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i, j = low - 1;
    for (i = low; i < high; i++)
    {
        if (arr[i] < pivot)
        {
            j++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j + 1], arr[high]);
    return j + 1;
}

/**
 * Quick Sort
 * Average complexity: O(nlogn)
 * Best Case: O(nlogn)
 * Worst Case: O(n^2)
 * Space: O(logn)
 * Not Stable
 */
void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        QuickSort(arr, low, pivot - 1);
        QuickSort(arr, pivot + 1, high);
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
    QuickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}