#include <iostream>
#include <vector>

using namespace std;

int findMax(vector<int> &arr)
{
    int maxVal = arr[0];
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];
    return maxVal;
}

void countingSort(vector<int> &arr, int exp)
{
    int n = arr.size();
    vector<int> output(n);
    vector<int> count(10, 0);

    for (int i = 0; i < n; i++)
    {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    
}
/**
 * Radix Sort (LSD, Base 10)
 * Average complexity: O(nlogk)
 * Best Case: O(d(n+b)) where b is base, d is the number digits of max value, n is size
 * Worst Case: O(d(n+b))
 * Space: O(logk)
 * Stable or Not Stable
 */

void printArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    vector<int> arr;
    arr.push_back(64);
    arr.push_back(25);
    arr.push_back(12);
    arr.push_back(22);
    arr.push_back(11);
    CountingSort(arr);
    printArray(arr);
    return 0;
}