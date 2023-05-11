#include <iostream>

using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

/**
 * Heap Sort
 * Average complexity: O(nlogn)
 * Best Case: O(nlogn)
 * Worst Case: O(nlogn)
 * Space: O(1)
 * Not Stable
 */ 
void HeapSort(int arr[], int n)
{
    int i;
    // Build heap
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (i = n - 1; i > 0; i--)
    {
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
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
    HeapSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}