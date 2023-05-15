#include <iostream>
#include <vector>

using namespace std;

/**
 * Counting Sort
 * Average complexity: O(n + k)
 * Best Case: O(n + k) where k is the range from min to max
 * Worst Case: O(n + k)
 * Space: O(k)
 * Not Stable (Can make it stable)
 */
void CountingSort(vector<int> &arr)
{
    int n = arr.size();
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    vector<int> count(range, 0), output(n);

    for (int i = 0; i < n; i++)
        count[arr[i] - min]++;

    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    copy(output.begin(), output.end(), arr.begin());
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
    CountingSort(arr);
    printArray(arr);
    return 0;
}