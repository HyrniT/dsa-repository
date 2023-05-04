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
    ShakerSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}