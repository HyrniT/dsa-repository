#include <iostream>
#include <iomanip>

using namespace std;

template <class T>
struct Time
{
    T hrs;
    T mins;
    T secs;
};

template <class T>
ostream &operator<<(ostream &os, const Time<T> &t)
{
    os << setfill('0') << setw(2) << t.hrs << ":"
       << setfill('0') << setw(2) << t.mins << ":"
       << setfill('0') << setw(2) << t.secs;
    return os;
}

template <class T>
Time<T> operator+(const Time<T> &t1, const Time<T> &t2)
{
    Time<T> result;
    result.hrs = t1.hrs + t2.hrs;
    result.mins = t1.mins + t2.mins;
    result.secs = t1.secs + t2.secs;

    if (result.secs >= 60)
    {
        result.secs -= 60;
        result.mins += 1;
    }
    if (result.mins >= 60)
    {
        result.mins -= 60;
        result.hrs += 1;
    }

    return result;
}

int main()
{
    Time<int> t1, t2, t3;
    cout << "start_hrs: ";
    cin >> t1.hrs;
    cout << "start_mins: ";
    cin >> t1.mins;
    cout << "start_secs: ";
    cin >> t1.secs;
    cout << "end_hrs: ";
    cin >> t2.hrs;
    cout << "end_mins: ";
    cin >> t2.mins;
    cout << "end_secs: ";
    cin >> t2.secs;
    t3 = t1 + t2;
    cout << "start_time: \"" << t1 << "\"" << endl;
    cout << "end_time: \"" << t2 << "\"" << endl;
    cout << "total: \"" << t3 << "\"" << endl;
}