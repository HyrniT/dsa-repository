#include <iostream>

using namespace std;

int sumOfSquares(int n)
{
    if (n == 1)
        return 1;
    return sumOfSquares(n - 1) + n * n;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

bool isPalindrome(int a[], int n)
{
    if (n <= 1)
        return true;
    if (a[0] == a[n - 1])
        return isPalindrome(a + 1, n - 2);
    else
        return false;
}

int Factorial(int n)
{
    if ((n == 0) || (n == 1))
        return 1;
    else
        return n * Factorial(n - 1);
}

int countDigit(int a)
{
    if (a == 0)
        return 0;
    else
        return 1 + countDigit(a/10);
}

int FIB(int n)
{
    if ((n == 0) || (n == 1))
        return 1;
    else 
        return FIB(n - 1) + FIB(n - 2);
}

int main()
{
    cout<<FIB(3)<<endl;
}