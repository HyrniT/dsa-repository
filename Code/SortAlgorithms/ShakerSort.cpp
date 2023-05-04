#include <iostream>

using namespace std;

/**
 * Shaker Sort
 * Average complexity: O(n^2)
 * Best Case: O(n^2)
 * Worst Case: O(n^2)
 * Space: O(1)
 * Stable
 */
void ShakerSort(int arr[], int n)
{
    int left = 0, right = n - 1;
    while (left < right)
    {
        for (int i = left; i < right; i++)
            if (arr[i] > arr[i + 1])
                swap(arr[i], arr[i + 1]);
        right--;
        for (int i = right; i > left; i--)
            if (arr[i] < arr[i - 1])
                swap(arr[i], arr[i - 1]);
        left++;
    }
}

/**
 * Shaker Sort Optimize
 * Average complexity: O(n^2)
 * Best Case: O(n)
 * Worst Case: O(n^2)
 * Space: O(1)
 * Stable
 */
void ShakerSortOptimize(int arr[], int n)
{
    int left = 0, right = n - 1;
    while (left < right)
    {
        bool sorted = true;
        for (int i = left; i < right; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                sorted = false;
            }
        }
        right--;
        for (int i = right; i > left; i--)
        {
            if (arr[i] < arr[i - 1])
            {
                swap(arr[i], arr[i - 1]);
                sorted = false;
            }
        }
        if (sorted)
            break;
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
    ShakerSortOptimize(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}