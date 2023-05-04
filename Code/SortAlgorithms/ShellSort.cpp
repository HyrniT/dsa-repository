#include <iostream>

using namespace std;

/**
 * Shell Sort
 * gap: 2
 * Average complexity: n^(4/3)
 * Best Case: O(nlogn)
 * Worst Case: n^(3/2)
 * Space: O(1)
 * Not Stable
 */
void ShellSort(int arr[], int n)
{
    int i, j, key, gap;
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            key = arr[i];
            j = i;
            while (j >= gap && arr[j - gap] > key)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = key;
            // or
            // int j;
            // for (j = i; j >= gap && arr[j - gap] > key; j -= gap)
            //     arr[j] = arr[j - gap];
            // arr[j] = key;
        }
    }
}

/**
 * Shell Sort Optimize
 * gaps: {1750, 701, 301, 132, 57, 23, 10, 4, 1}
 * Ciura, 2001
 * Average complexity: unknown
 * Best Case: O(n)
 * Worst Case: unknown
 * Space: O(1)
 * Not Stable
 */
int gaps[] = {1750, 701, 301, 132, 57, 23, 10, 4, 1};
void ShellSortOptimize(int arr[], int n)
{
    int i, j, key;
    for (int gap : gaps)
    {
        for (i = gap; i < n; i++)
        {
            key = arr[i];
            j = i;
            while (j >= gap && arr[j - gap] > key)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = key;
        }
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
    ShellSortOptimize(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}