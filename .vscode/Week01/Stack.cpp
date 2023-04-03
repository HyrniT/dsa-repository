#include <iostream>

using namespace std;

struct NODE
{
    int key;
    NODE *pNext;
};

struct Stack
{
    NODE *pHead;
    NODE *pTail;
};

NODE *createNode(int data)
{
    NODE *new_node = new NODE();
    new_node->key = data;
    new_node->pNext = nullptr;
    return new_node;
}

Stack *createStack(int data)
{
    NODE* new_node = createNode(data);
    Stack *new_stack = new Stack();
    new_stack->pHead = new_node;
    new_stack->pTail = new_node;
    return new_stack;
}

bool push(Stack *&S, int data)
{
    NODE *new_node = createNode(data);
    if (new_node == nullptr)
        return false;
    if ((S->pHead == nullptr) && (S->pTail == nullptr))
    {
        S->pHead = S->pTail = new_node;
    }
    else
    {
        new_node->pNext = S->pHead;
        S->pHead = new_node;
    }
    return true;
}

int pop (Stack *&S)
{
    int result = -1;
    if (S->pHead == S->pTail)
    {
        result = S->pHead->key;
        S->pHead = S->pTail =nullptr;
        delete S->pHead;
        delete S->pTail;
    }
    else
    {
        result = S->pHead->key;
        NODE *temp_node = S->pHead->pNext;
        delete S->pHead;
        S->pHead = temp_node;
        temp_node = nullptr;
        delete temp_node;
    }
    return result;
}

