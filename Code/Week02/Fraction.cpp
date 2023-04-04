#include <iostream>

using namespace std;

template <class T>
struct Fraction
{
    T num;   // tu
    T denom; // mau
};

template <class T>
int gcd(T a, T b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

template <class T>
ostream &operator<<(ostream &os, Fraction<T> fraction)
{
    os << fraction.num << "/" << fraction.denom;
    return os;
}

template <class T>
Fraction<T> operator+(const Fraction<T> &f1, const Fraction<T> &f2)
{
    Fraction<T> result;
    result.num = f1.num * f2.denom + f2.num * f1.denom;
    result.denom = f1.denom * f2.denom;
    T a = gcd(result.num, result.denom);
    result.num /= a;
    result.denom /= a;
    return result;
}

int main()
{
    Fraction<int> f1, f2, f3;
    cout << "Num_first: ";
    cin >> f1.num;
    cout << "Denum_first: ";
    cin >> f1.denom;
    cout << "Num_second: ";
    cin >> f2.num;
    cout << "Denum_second: ";
    cin >> f2.denom;
    f3 = f1 + f2;
    cout << "Frac1: " << f1 << endl;
    cout << "Frac2: " << f2 << endl;
    cout << "Sum: " << f3 << endl;
}