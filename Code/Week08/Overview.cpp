#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

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

void Bai5()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	unordered_map<int, int> f;
	vector<int> r;
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		f[arr[i]]++;
		m = max(m, f[arr[i]]);
	}
	for (const auto &i : f)
	{
		if (i.second == m)
		{
			r.push_back(i.first);
		}
	}
	for (const auto &i : r)
	{
		cout << i << " ";
	}
	cout << endl;
}

void bubbleSort(vector<int> &arr)
{
	int n = arr.size();
	bool sort = true;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				sort = false;
			}
		}
		if (sort)
		{
			break;
		}
	}
}

void Bai6()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	bubbleSort(arr);
	for (const auto &i : arr)
	{
		cout << i << " ";
	}
	cout << endl;
}

int partition(vector<int> &arr, int l, int h)
{
	int pivot = arr[h];
	int j = l;
	for (int i = l; i < h; i++)
	{
		if (arr[i] < pivot)
		{
			swap(arr[i], arr[j]);
			j++;
		}
	}
	swap(arr[j], arr[h]);
	return j;
}

void QuickSort(vector<int> &arr, int l, int h)
{
	if (l < h)
	{
		int pivot = partition(arr, l, h);
		QuickSort(arr, l, pivot - 1);
		QuickSort(arr, pivot + 1, h);
	}
}

void Bai7()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	QuickSort(arr, 0, n - 1);
	for (const auto &i : arr)
	{
		cout << i << " ";
	}
	cout << endl;
}

void Bai8()
{
	int n1, n2, i = 0, j = 0, k = 0;
	cin >> n1;
	vector<int> arr1(n1);
	for (int i = 0; i < n1; i++)
	{
		cin >> arr1[i];
	}
	cin >> n2;
	vector<int> arr2(n2);
	for (int i = 0; i < n2; i++)
	{
		cin >> arr2[i];
	}
	vector<int> arr3(n1 + n2);
	while (i < n1 && j < n2)
	{
		if (arr1[i] < arr2[j])
		{
			arr3[k++] = arr1[i++];
		}
		else
		{
			arr3[k++] = arr2[j++];
		}
	}
	while (i < n1)
	{
		arr3[k++] = arr1[i++];
	}
	while (j < n2)
	{
		arr3[k++] = arr2[j++];
	}
	for (auto const &i : arr3)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	// Bai1();
	// Bai2();
	// Bai3();
	// Bai4();
	// Bai5();
	// Bai6();
	// Bai7();
	Bai8();
}