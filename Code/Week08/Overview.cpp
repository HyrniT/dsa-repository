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
	// cin.ignore();
	getline(cin, s1);
	// cin.ignore();
	getline(cin, s2);
	int n1 = s1.length();
	int n2 = s2.length();

	char privot = s2[0];

	if (n2 == 1)
	{
		for (int i = 0; i < n1; i++)
		{
			if (s1[i] == privot)
			{
				check = true;
			}
		}
	}
	else
	{
		for (int i = 0; i < n1; i++)
		{
			if (s1[i] == privot)
			{
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
	}

	if (check)
		cout << "exist" << endl;
	else
		cout << "not exist" << endl;
}

int binarySearch(vector<int> arr, int x)
{
	int l = 0;
	int r = arr.size();

	while (l <= r)
	{
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

int binarySearchLeftMost(vector<int> arr, int x)
{
	int result = -1;
	int n = arr.size();
	int l = 0;
	int r = n - 1;

	while (l <= r)
	{
		int m = l + (r - l) / 2;

		if (arr[m] == x)
		{
			result = m;
			r = m - 1;
		}
		else if (arr[m] < x)
		{
			l = m + 1;
		}
		else
		{
			r = m - 1;
		}
	}

	return result;
}

int binarySearchRightMost(vector<int> arr, int x)
{
	int result = -1;
	int l = 0;
	int r = arr.size();

	while (l <= r)
	{
		int m = l + (r - l) / 2;

		if (arr[m] == x)
		{
			result = m;
			l = m + 1;
		}
		else if (arr[m] < x)
		{
			l = m + 1;
		}
		else
		{
			r = m - 1;
		}
	}

	return result;
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
	if (binarySearch(arr, x) != -1)
		cout << "exist" << endl;
	else
		cout << "non-exist" << endl;
}

void Bai4()
{
	int n, x, result = 0;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cin >> x;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x)
		{
			result++;
		}
	}
	cout << result << endl;
}

int main()
{
	// Bai1();
	// Bai2();
	// Bai3();
	Bai4();
}