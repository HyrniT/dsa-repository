#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node *next;
};

Node *createNode(int key)
{
    Node *newNode = new Node();
    newNode->key = key;
    newNode->next = nullptr;
    return newNode;
}

Node *addHead(Node *head, int key)
{
    Node *newNode = createNode(key);
    if (head == nullptr)
        return newNode;
    newNode->next = head;
    head = newNode;
    return head;
}

Node *addTail(Node *head, int key)
{
    Node *newNode = createNode(key);
    if (head == nullptr)
        return newNode;
    Node *currNode = head;
    while (currNode->next != nullptr)
        currNode = currNode->next;
    currNode->next = newNode;
    return head;
}

Node *addAt(Node *head, int key, int pos)
{
    if (head == nullptr)
        return nullptr;
    if (pos <= 0)
        head = addHead(head, key);
    else
    {
        Node *newNode = createNode(key);
        int count = 1;
        Node *currNode = head;
        while (currNode->next != nullptr)
        {
            if (count == pos)
                break;
            currNode = currNode->next;
            count++;
        }
        newNode->next = currNode->next;
        currNode->next = newNode;
    }
    return head;
}

Node *delHead(Node *head)
{
    if (head == nullptr)
        return nullptr;
    Node *currNode = head;
    head = head->next;
    delete currNode;
    currNode = nullptr;
    return head;
}

Node *delTail(Node *head)
{
    if (head == nullptr)
        return nullptr;
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return nullptr;
    }
    Node *prevNode = nullptr;
    Node *currNode = head;
    while (currNode->next != nullptr)
    {
        prevNode = currNode;
        currNode = currNode->next;
    }
    prevNode->next = nullptr;
    delete currNode;
    currNode = nullptr;
    return head;
}

Node *delAt(Node *head, int pos)
{
    if (pos <= 0)
        head = delHead(head);
    else
    {
        int count = 1;
        Node *prevNode = nullptr;
        Node *currNode = head;
        while (currNode->next != nullptr)
        {
            prevNode = currNode;
            currNode = currNode->next;
            if (count == pos)
                break;
            count++;
        }
        if (prevNode != nullptr)
            prevNode->next = currNode->next;
        else
            head = nullptr;
        delete currNode;
        currNode = nullptr;
    }
    return head;
}

Node *delKey(Node *head, int key)
{
    if (head == nullptr)
        return nullptr;
    if (head->key == key)
        return delHead(head);
    Node *prevNode = nullptr;
    Node *currNode = head;
    while (currNode->next != nullptr)
    {
        if (currNode->key == key)
        {
            prevNode->next = currNode->next;
            delete currNode;
            currNode = prevNode->next;
        }
        else
        {
            prevNode = currNode;
            currNode = currNode->next;
        }
    }
    return head;
}

void delAll(Node *&head)
{
    while (head != nullptr)
    {
        // head = delHead(head);
        Node *temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
    }
}

int find(Node *head, int key)
{
    int count = 0;
    Node *currNode = head;
    while (currNode != nullptr)
    {
        if (currNode->key == key)
            return count;
        currNode = currNode->next;
        count++;
    }
    if (currNode == nullptr)
        return -1;
    return count;
}

Node *reverse(Node *head) // Recursion
{
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *p = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return p;
}

// Node* reverse(Node* head) // Non-recursion
// {
//     Node* prev = nullptr;
//     Node* current = head;
//     Node* next = nullptr;

//     while (current != nullptr)
//     {
//         next = current->next;
//         current->next = prev;
//         prev = current;
//         current = next;
//     }

//     return prev;
// }

// void reverse(Node* &head) // void recursion
// {
//     if (head == nullptr || head->next == nullptr)
//         return;

//     Node* first = head;
//     Node* rest = head->next;

//     reverse(rest);

//     first->next->next = first;
//     first->next = nullptr;

//     head = rest;
// }

// void reverse(Node* &head) // void non-recursion
// {
//     if (head == nullptr || head->next == nullptr)
//         return;

//     Node* prev = nullptr;
//     Node* current = head;
//     Node* next = nullptr;

//     while (current != nullptr)
//     {
//         next = current->next;
//         current->next = prev;
//         prev = current;
//         current = next;
//     }

//     head = prev;
// }

Node *merge(Node *head1, Node *head2)
{
    if (head1 == nullptr)
        return head2;
    if (head2 == nullptr)
        return head1;

    Node *newNode = nullptr;
    Node *currNode1 = head1;
    Node *currNode2 = head2;

    while (currNode1 != nullptr && currNode2 != nullptr)
    {
        if (currNode1->key < currNode2->key)
        {
            newNode = addTail(newNode, currNode1->key);
            currNode1 = currNode1->next;
        }
        else
        {
            newNode = addTail(newNode, currNode2->key);
            currNode2 = currNode2->next;
        }
    }

    while (currNode1 != nullptr)
    {
        newNode = addTail(newNode, currNode1->key);
        currNode1 = currNode1->next;
    }

    while (currNode2 != nullptr)
    {
        newNode = addTail(newNode, currNode2->key);
        currNode2 = currNode2->next;
    }

    return newNode;
}

Node *concatenate(Node *head1, Node *head2)
{
    if (head1 == nullptr)
        return head2;
    if (head2 == nullptr)
        return head1;

    Node *currNode1 = head1;
    Node *currNode2 = head2;
    Node *newNode = nullptr;

    while (currNode1->next != nullptr)
    {
        newNode = addTail(newNode, currNode1->key);
        currNode1 = currNode1->next;
    }

    while (currNode2->next != nullptr)
    {
        newNode = addTail(newNode, currNode2->key);
        currNode2 = currNode2->next;
    }

    return newNode;
}

void print(Node *head)
{
    Node *currNode = head;
    while (currNode != nullptr)
    {
        cout << currNode->key << " ";
        currNode = currNode->next;
    }
    cout << endl;
}

int main()
{
    Node *LinkedList = nullptr;
    LinkedList = addHead(LinkedList, 3);
    LinkedList = addHead(LinkedList, 4);
    LinkedList = addTail(LinkedList, 2);
    LinkedList = addTail(LinkedList, 1);

    // LinkedList = delHead(LinkedList);
    // LinkedList = delTail(LinkedList);

    LinkedList = addAt(LinkedList, 5, 4);
    LinkedList = delAt(LinkedList, 4);

    print(LinkedList);
    LinkedList = reverse(LinkedList);
    print(LinkedList);

    Node *LinkedList1 = nullptr;
    LinkedList1 = addTail(LinkedList1, 5);
    LinkedList1 = addTail(LinkedList1, 6);
    LinkedList1 = addTail(LinkedList1, 7);
    print(LinkedList1);

    Node *LinkedList2 = nullptr;
    LinkedList2 = concatenate(LinkedList, LinkedList1);
    LinkedList2 = delTail(LinkedList2);
    print(LinkedList2);

    cout << find(LinkedList2, 7) << endl;

    delAll(LinkedList2);
    print(LinkedList2);

    return 0;
}