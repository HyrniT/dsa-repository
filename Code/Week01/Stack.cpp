#include <iostream>

using namespace std;

struct NODE
{
    int key;
    NODE *pNext;
};

// Stack
struct Stack
{
    NODE *pTop;
};

void initStack(Stack &S, int val)
{
    NODE *p = new NODE;
    p->key = val;
    p->pNext = nullptr;
    S.pTop = p;
}

void push(Stack &S, int val)
{
    NODE *p = new NODE;
    p->key = val;
    p->pNext = S.pTop;
    S.pTop = p;
}

int pop(Stack &S)
{
    if (S.pTop == nullptr)
    {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    NODE *p = S.pTop;
    int val = p->key;
    S.pTop = p->pNext;
    delete p;
    return val;
}

int countStack(Stack &S)
{
    int count = 0;
    NODE *p = S.pTop;
    while (p != nullptr)
    {
        count++;
        p = p->pNext;
    }
    return count;
}

bool isEmptyStack(Stack &S)
{
    return (S.pTop == nullptr);
}

// Queue
struct NODE
{
    int key;
    NODE *pNext;
};

struct Queue
{
    NODE *pHead;
    NODE *pTail;
};

// Khởi tạo hàng đợi với một giá trị cho trước
void initQueue(Queue &Q, int val)
{
    NODE *p = new NODE;
    p->key = val;
    p->pNext = nullptr;
    Q.pHead = Q.pTail = p;
}

// Kiểm tra hàng đợi có rỗng hay không
bool isEmpty(Queue Q)
{
    return Q.pHead == nullptr;
}

// Enqueue một giá trị vào hàng đợi
void enqueue(Queue &Q, int val)
{
    NODE *p = new NODE;
    p->key = val;
    p->pNext = nullptr;
    if (Q.pHead == nullptr)
    {
        Q.pHead = Q.pTail = p;
    }
    else
    {
        Q.pTail->pNext = p;
        Q.pTail = p;
    }
}

// Dequeue một phần tử ra khỏi hàng đợi, trả về giá trị của phần tử đó
int dequeue(Queue &Q)
{
    if (Q.pHead == nullptr)
    {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    NODE *p = Q.pHead;
    int val = p->key;
    Q.pHead = p->pNext;
    if (Q.pHead == nullptr)
    {
        Q.pTail = nullptr;
    }
    delete p;
    return val;
}

// Đếm số lượng phần tử có trong hàng đợi
int countElements(Queue Q)
{
    int count = 0;
    NODE *p = Q.pHead;
    while (p != nullptr)
    {
        count++;
        p = p->pNext;
    }
    return count;
}
