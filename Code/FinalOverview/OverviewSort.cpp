#include <iostream>

using namespace std;

void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n - 1; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

void SelectionSortOptimize(int arr[], int n)
{
    int r = n;
    for (int i = 0; i < r - 1; i++)
    {
        int min_idx = i, max_idx = i;
        for (int j = i + 1; j < r; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
            if (arr[j] > arr[max_idx])
            {
                max_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
        if (i == max_idx)
        {
            max_idx = min_idx;
        }
        r--;
        swap(arr[r], arr[max_idx]);
    }
}

void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int key = arr[i];

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        swap(arr[j + 1], key);
    }
}

int BinarySeearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
        {
            return m;
        }
        else if (x < arr[m])
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return l;
}

void InsertionSortOptimize(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];

        int l = BinarySeearch(arr, 0, i - 1, key);
        for (int r = i - 1; r >= l; r--)
        {
            arr[r + 1] = arr[r];
        }
        arr[l] = key;
    }
}

void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                swap(arr[j + 1], arr[j]);
            }
        }
    }
}

void BubbleSortOptimize(int arr[], int n)
{
    bool sorted = true;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                swap(arr[j + 1], arr[j]);
                sorted = false;
            }
        }
        if (sorted)
            return;
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
        i = n - 1 - lastSwap;
    }
}

void BubbleSortRecursive(int arr[], int n)
{
    bool sorted = true;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
            sorted = false;
        }
    }
    if (sorted == false)
        BubbleSortRecursive(arr, n);
}

void ShakerSort(int arr[], int n)
{
    int left = 0, right = n - 1;
    while (left < right)
    {
        for (int i = left; i < right; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }
        right--;
        for (int i = right; i > left; i--)
        {
            if (arr[i] < arr[i - 1])
            {
                swap(arr[i], arr[i - 1]);
            }
        }
        left++;
    }
}

void ShellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int key = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > key)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = key;
        }
    }
}

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

void MergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

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
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = { 64, 25, 12, 22, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);
    ShakerSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}