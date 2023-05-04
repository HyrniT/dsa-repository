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
    int last = arr[n - 1]; // (n - 1) ~ i
    int j = n - 2;         // (n - 2) ~ (i - 1)

    // Shift elements to the right to make space for the nth element
    while (j >= 0 && arr[j] > last)
    {
        arr[j + 1] = arr[j];
        j--;
    }

    // Place the nth element in its correct position
    arr[j + 1] = last;
}

int BinarySearch(int arr[], int left, int right, int x)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return left;
}

void BinaryInsertionSort(int arr[], int n)
{
    int i, l, r, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        l = BinarySearch(arr, 0, i - 1, key);
        for (r = i - 1; r >= l; r--)
        {
            arr[r + 1] = arr[r];
        }
        arr[l] = key;
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
    BinaryInsertionSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    // cout<<std::lower_bound(arr, arr+5, 14)<<endl;
    // cout<<arr<<endl;
    // cout<<std::lower_bound(arr, arr+5, 14)-arr;

    return 0;
}