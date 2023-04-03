#include <iostream>
#include <cstring>

using namespace std;

void inputArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int FindMin(int *a, int n)
{
    int min = *a;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    return min;
}

int FindMaxModulus(int *a, int n)
{
    bool isNegative = false;
    if (*a < 0)
        isNegative = true;
    int maxModulus = abs(*a);

    for (int i = 1; i < n; i++)
    {
        if (a[i] < 0)
            isNegative = true;
        if (abs(a[i]) > maxModulus)
        {
            maxModulus = abs(a[i]);
        }
    }
    return isNegative ? -maxModulus : maxModulus;
}

int countValue(int *a, int n, int key)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            count++;
        }
    }
    return count;
}

void StrRev(char *a)
{
    int n = strlen(a);
    char *begin = a;
    char *end = a + n - 1;
    while (begin < end)
    {
        swap(*begin, *end);
        begin++;
        end--;
    }
}

void PrettyStr(char *a)
{
    int n = strlen(a);
    bool new_word = true;
    for (int i = 0; i < n; i++)
    {
        if (new_word && isalpha(a[i]))
        {
            a[i] = toupper(a[i]);
            new_word = false;
        }
        else if (a[i] == ' ')
        {
            new_word = true;
        }
    }
}

int main()
{
    // int *arr = new int();
    // inputArray(arr, 3);
    // printArray(arr, 3);
    // cout << FindMin(arr, 3);
    // cout << endl;
    // cout << FindMaxModulus(arr, 3);
    // cout << endl;
    char s[] = "Hien";
    StrRev(s);
    cout << s << endl;
    char a[] = "Cau TRuC dU liEu";
    PrettyStr(a);
    cout << a << endl;
}