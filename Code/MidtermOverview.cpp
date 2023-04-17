#include <iostream>
#include <cmath>
#include <cstring>
#include <unordered_set>

using namespace std;

/* LAB 1 */
// Con trỏ

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
}

int findMin(int *a, int n)
{
    int min = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    return min;
}

int findMaxModulus(int *a, int n)
{
    int max = abs(a[0]);
    for (int i = 1; i < n; i++)
    {
        if (abs(a[i]) > max)
        {
            max = abs(a[i]);
        }
    }
    return max;
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

void reverseString(char *a)
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

void beautifyString(char *a)
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
        else if (new_word && !isalpha(a[i]))
        {
            new_word = false;
        }
        else if (a[i] == ' ')
        {
            new_word = true;
        }
        else
        {
            a[i] = tolower(a[i]);
        }
    }
}

// Đệ quy
int sumOfSquares(int n)
{
    if (n == 1)
        return 1;
    return n * n + sumOfSquares(n - 1);
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
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

int factorial(int n)
{
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}

int countDigit(int a)
{
    if (a == 0)
        return 0;
    return 1 + countDigit(a / 10);
}

int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Danh sách liên kết
struct NODE
{
    int key;
    NODE *p_next;
};

struct List
{
    NODE *p_head;
    NODE *p_tail;
};

NODE *createNode(int data)
{
    NODE *new_node = new NODE();
    new_node->key = data;
    new_node->p_next = nullptr;
    return new_node;
}

List *createList(NODE *p_node)
{
    if (p_node == nullptr)
        return nullptr;
    List *new_list = new List();
    new_list->p_head = p_node;
    new_list->p_tail = p_node;
    return new_list;
}

bool addHead(List *&L, int data)
{
    NODE *new_node = createNode(data);
    if (new_node == nullptr)
        return false;
    if (L == nullptr)
        L = createList(new_node);
    else if (L->p_head == nullptr)
    {
        L->p_head = new_node;
        L->p_tail = new_node;
    }
    else
    {
        new_node->p_next = L->p_head;
        L->p_head = new_node;
    }
    return true;
}

bool addTail(List *&L, int data)
{
    NODE *new_node = createNode(data);
    if (new_node == nullptr)
        return false;
    if (L == nullptr)
        L = createList(new_node);
    else if (L->p_head == nullptr)
    {
        L->p_head = new_node;
        L->p_tail = new_node;
    }
    else
    {
        L->p_tail->p_next = new_node;
        L->p_tail = new_node;
    }
    return true;
}

void removeHead(List *&L)
{
    if (L == nullptr)
        return;

    if (L->p_head == L->p_tail)
    {
        L->p_head = nullptr;
        L->p_tail = nullptr;
    }
    else
    {
        NODE *temp_node = L->p_head;
        L->p_head = L->p_head->p_next;
        delete temp_node;
        temp_node = nullptr;
    }
}

void removeTail(List *&L)
{
    if (L == nullptr)
        return;

    if (L->p_head == L->p_tail)
    {
        L->p_head = nullptr;
        L->p_tail = nullptr;
    }
    else
    {
        NODE *temp_node = L->p_head;
        while (temp_node->p_next != L->p_tail)
            temp_node = temp_node->p_next;
        delete L->p_tail;
        L->p_tail = temp_node;
        L->p_tail->p_next = nullptr;
    }
}

void removeAll(List *&L)
{
    if (L == nullptr)
        return;
    while (L->p_head != nullptr)
        removeHead(L);
    delete L;
    L = nullptr;
}

void printList(List *L)
{
    NODE *temp_node = L->p_head;
    while (temp_node != nullptr)
    {
        cout << temp_node->key << " ";
        temp_node = temp_node->p_next;
    }
    delete temp_node;
    cout << endl;
}

int countElements(List *L)
{
    int count = 0;
    NODE *temp_node = L->p_head;
    while (temp_node != nullptr)
    {
        count++;
        temp_node = temp_node->p_next;
    }
    delete temp_node;
    return count;
}

List *reverseList(List *L)
{
    if (L == nullptr)
        return nullptr;
    NODE *temp_node = L->p_head;
    List *new_list = nullptr;
    while (temp_node != nullptr)
    {
        addHead(new_list, temp_node->key);
        temp_node = temp_node->p_next;
    }
    delete temp_node;
    return new_list;
}

void removeDuplicate(List *&L)
{
    if (L == nullptr)
        return;
    NODE *curr_node = L->p_head;
    NODE *prev_node = nullptr;
    unordered_set<int> visited;
    while (curr_node != nullptr)
    {
        if (visited.find(curr_node->key) != visited.end())
        {
            NODE *temp_node = curr_node;
            prev_node->p_next = curr_node->p_next;
            curr_node = curr_node->p_next;
            delete temp_node;
            temp_node = nullptr;
        }
        else
        {
            visited.insert(curr_node->key);
            prev_node = curr_node;
            curr_node = curr_node->p_next;
        }
    }
}

bool removeElement(List *&L, int key)
{
    if (L == nullptr)
        return false;
    NODE *curr_node = L->p_head;
    NODE *prev_node = nullptr;
    while (curr_node != nullptr)
    {
        if (curr_node->key == key)
        {
            NODE *temp_node = curr_node;
            prev_node->p_next = curr_node->p_next;
            curr_node = curr_node->p_next;
            delete temp_node;
            temp_node = nullptr;
        }
        else
        {
            prev_node = curr_node;
            curr_node = curr_node->p_next;
        }
    }
    return true;
}

// Stack
struct sNODE
{
    int key;
    sNODE* p_next;
};



int main()
{
    NODE *Node = nullptr;
    List *LinkedList = createList(Node);
    addTail(LinkedList, 1);
    addTail(LinkedList, 2);
    addTail(LinkedList, 2);
    addTail(LinkedList, 2);
    addTail(LinkedList, 3);
    addTail(LinkedList, 3);
    addTail(LinkedList, 3);
    addTail(LinkedList, 3);
    printList(LinkedList);
    List *ReverseList = reverseList(LinkedList);
    printList(ReverseList);
    removeDuplicate(LinkedList);
    printList(LinkedList);
    removeElement(LinkedList, 3);
    printList(LinkedList);
}