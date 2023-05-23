#include <iostream>
#include <vector>
#include <string>
 
#define M 1000
 
using namespace std;
 
// Bai 1
void Bai1()
{
	int n, x;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cin >> x;
	for (int i : arr)
	{
		if (i == x)
		{
			cout << "exist" << endl;
			return;
		}
	}
	cout << "not exist" << endl;
}
 
void Bai2()
{
	bool check = false;
	string s1, s2;
	//cin.ignore();
	getline(cin, s1);
	//cin.ignore();
	getline(cin, s2);
	int n1 = s1.length();
	int n2 = s2.length();
 
	char privot = s2[0];
 
	for (int i = 0; i < n1; i++)
	{
		if (s1[i] == privot)
		{
			if (n2 == 1)
			{
				check = true;
				break;
			}
			for (int j = i + 1; j < n1; j++)
			{
				if (s1[j] != s2[j - i])
				{
					break;
				}
				if (j - i == n2 - 1)
				{
					check = true;
				}
			}
		}
	}
	cout << n2 << endl;
 
	if (check)
		cout << "exist" << endl;
	else
		cout << "not exist" << endl;
}
 
int binarySearch(int arr[], int l, int r, int x)
{
	while (l <= r) {
		int m = l + (r - l) / 2;
 
		if (arr[m] == x)
			return m;
 
		if (arr[m] < x)
			l = m + 1;
 
		else
			r = m - 1;
	}
 
	return -1;
}
 
 
void Bai3()
{
	int n, x;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cin >> x;
 
}
 
int main()
{
	//Bai1();
	Bai2();
}