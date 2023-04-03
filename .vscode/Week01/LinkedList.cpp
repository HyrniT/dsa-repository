#include <iostream>
#include <unordered_set>

using namespace std;

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
    if ((L->p_head == nullptr) && (L->p_tail == nullptr))
    {
        L->p_head = L->p_tail = new_node;
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
    if ((L->p_head == nullptr) && (L->p_tail == nullptr))
    {
        L->p_head = L->p_tail = new_node;
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
    if ((L->p_head == nullptr) || (L->p_tail == nullptr))
        return;
    else if (L->p_head == L->p_tail)
    {
        L->p_head = L->p_tail = nullptr;
        delete L->p_head;
        delete L->p_tail;
    }
    else
    {
        NODE *temp_node = L->p_head->p_next;
        delete L->p_head;
        L->p_head = temp_node;
        temp_node = nullptr;
        delete temp_node;
    }
}

void removeTail(List *&L)
{
    if ((L->p_head == nullptr) || (L->p_tail == nullptr))
        return;
    else if (L->p_head == L->p_tail)
    {
        // delete L->p_head;
        // delete L->p_tail;
        L->p_head = L->p_tail = nullptr;
    }
    else
    {
        NODE *temp_node = L->p_head;
        while (temp_node->p_next->p_next != nullptr)
            temp_node = temp_node->p_next;
        temp_node->p_next = nullptr;
        L->p_tail = temp_node;
        temp_node = nullptr;
        delete temp_node;
    }
}

void removeAll(List *&L)
{
    NODE *p_current = L->p_head;
    while (p_current != nullptr)
    {
        NODE *p_temp = p_current;
        p_current = p_current->p_next;
        delete p_temp;
    }
    L->p_head = L->p_tail = nullptr;
    delete p_current;
}

void printList(List *L)
{
    NODE *current_node = L->p_head;
    while (current_node != nullptr)
    {
        cout << current_node->key << " ";
        current_node = current_node->p_next;
    }
    delete current_node;
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
    List *new_list;
    if ((L->p_head == nullptr) || (L->p_tail == nullptr))
        return nullptr;
    else
    {
        NODE *temp_node = L->p_head->p_next;
        NODE *new_node = createNode(L->p_head->key);
        new_list = createList(new_node);
        while (temp_node != nullptr)
        {
            addHead(new_list, temp_node->key);
            temp_node = temp_node->p_next;
        }
        delete temp_node;
    }
    return new_list;
}

void removeDuplicate(List *&L)
{
    unordered_set<int> hash_table;
    NODE *previous_node = nullptr;
    NODE *current_node = L->p_head;
    while (current_node != nullptr)
    {
        if (hash_table.find(current_node->key) != hash_table.end())
        {
            previous_node->p_next = current_node->p_next;
            current_node = nullptr;
            delete current_node;
            current_node = previous_node->p_next;
        }
        else
        {
            hash_table.insert(current_node->key);
            previous_node = current_node;
            current_node = current_node->p_next;
        }
    }
    previous_node = nullptr;
    delete previous_node;
    current_node = nullptr;
    delete current_node;
}

bool removeElement(List *&L, int key)
{
    NODE *previous_node = nullptr;
    NODE *current_node = L->p_head;
    while (current_node != nullptr)
    {
        if (current_node->key == key)
        {
            previous_node->p_next = current_node->p_next;
            current_node = nullptr;
            delete current_node;
            current_node = previous_node->p_next;
        }
        else
        {
            previous_node = current_node;
            current_node = current_node->p_next;
        }
    }
    previous_node = nullptr;
    delete previous_node;
    current_node = nullptr;
    delete current_node;
    return true;
}

bool addPos(List *&L, int data, int pos)
{
    NODE *new_node = createNode(data);
    if (new_node == nullptr)
        return false;
    if (pos <= 0)
        addHead(L, data);
    else
    {
        int count = 0;
        NODE *temp_node = L->p_head;
        while (temp_node != nullptr)
        {
            count++;
            if (count == pos)
            {
                new_node->p_next = temp_node->p_next;
                temp_node->p_next = new_node;
                break;
            }
            else
            {
                temp_node = temp_node->p_next;
            }
        }
        if (count < pos)
            addTail(L, data);
        temp_node = nullptr;
        delete temp_node;
    }
    return true;
}

void removePos(List *&L, int pos)
{
    if (pos <= 0)
        removeHead(L);
    else
    {
        int count = 0;
        NODE *previous_node = L->p_head;
        NODE *current_node = L->p_head->p_next;
        while (current_node != nullptr)
        {
            count++;
            if (count == pos)
            {
                previous_node->p_next = current_node->p_next;
                current_node = nullptr;
                delete current_node;
                break;
            }
            else
            {
                previous_node = current_node;
                current_node = current_node->p_next;
            }
        }
        if (pos > count)
            removeTail(L);
        previous_node = nullptr;
        current_node = nullptr;
        delete previous_node;
        delete current_node;
    }
}

int main()
{
    List *list = new List();
    // addHead(list, 3);
    // addHead(list, 2);
    // addHead(list, 1);
    addTail(list, 1);
    addTail(list, 2);
    addTail(list, 3);
    addTail(list, 3);
    // cout << countElements(list) << endl;
    // removeHead(list);
    // removeTail(list);
    // removeAll(list);
    // printList(list);
    // removeDuplicate(list);
    addPos(list, 100, 3);
    printList(list);
    removePos(list, 3);
    printList(list);
    // List *newList = new List();
    // newList = reverseList(list);
    // printList(newList);
}