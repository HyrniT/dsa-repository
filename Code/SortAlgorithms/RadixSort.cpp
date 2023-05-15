#include <iostream>
#include <vector>

#define BASE 10

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
    vector<int> count(BASE, 0), output(n);

    for (int i = 0; i < n; i++)
    {
        int digit = (arr[i] / exp) % BASE;
        count[digit]++;
    }

    for (int i = 1; i < BASE; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % BASE;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    copy(output.begin(), output.end(), arr.begin());
}
/**
 * Radix Sort (LSD, Base 10)
 * Average complexity: O(nlogk)
 * Best Case: O(d(n+b)) where b is base, d is the number digits of max value, n is size
 * Worst Case: O(d(n+b))
 * Space: O(logk)
 * Stable or Not Stable
 */
void RadixSort(vector<int> &arr)
{
    int max = *max_element(arr.begin(), arr.end());
    for (int exp = 1; max / exp > 0; exp *= BASE)
        countingSort(arr, exp);
}

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
    RadixSort(arr);
    printArray(arr);
    return 0;
}