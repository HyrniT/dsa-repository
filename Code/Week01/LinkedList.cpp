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
        p_temp = nullptr;
    }
    L->p_head = L->p_tail = nullptr;
    delete p_current;
    p_current = nullptr;
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
        temp_node = nullptr;
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

List *concatList(List *L1, List *L2)
{
    NODE *l1_node = L1->p_head;
    NODE *l2_node = L2->p_head;
    List *new_list = new List();

    while ((l1_node != nullptr) && (l2_node != nullptr))
    {
        if (l1_node->key < l2_node->key)
        {
            addTail(new_list, l1_node->key);
            l1_node = l1_node->p_next;
        }
        else
        {
            addTail(new_list, l2_node->key);
            l2_node = l2_node->p_next;
        }
    }
    while (l1_node != nullptr)
    {
        addTail(new_list, l1_node->key);
        l1_node = l1_node->p_next;
    }
    while (l2_node != nullptr)
    {
        addTail(new_list, l2_node->key);
        l2_node = l2_node->p_next;
    }
    return new_list;
}

void mergeList(List *&L1, List *L2)
{
    if (L2->p_head == nullptr)
    {
        // If L2 is empty, nothing to merge
        return;
    }
    if (L1->p_head == nullptr)
    {
        // If L1 is empty, just copy all elements from L2 to L1
        L1->p_head = L2->p_head;
        L1->p_tail = L2->p_tail;
        L2->p_head = L2->p_tail = nullptr;
        return;
    }

    NODE *l1_node = L1->p_head;
    NODE *l1_next = L1->p_head->p_next;
    NODE *l2_node = L2->p_head;

    // Head L1 is greater than head L2
    if (l1_node->key > l2_node->key)
    {
        addHead(L1, l2_node->key);
        l2_node = l2_node->p_next;
        l1_node = L1->p_head;
        l1_next = l1_node->p_next;
    }

    int index = 0;
    while ((l1_next != nullptr) && (l2_node != nullptr))
    {
        if (l2_node->key < l1_next->key)
        {
            addPos(L1, l2_node->key, ++index);
            l2_node = l2_node->p_next; 
            l1_node = l1_node->p_next;
        }
        else
        {
            ++index;
            l1_node = l1_next;
            l1_next = l1_node->p_next;
        }
    }
    if (l2_node != nullptr) {
        l1_node->p_next = l2_node;
        L1->p_tail = L2->p_tail;
    }
    // Reset L2 to an empty list
    L2->p_head = L2->p_tail = nullptr;
}

int main()
{
    /*
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
    */

    List *list1 = new List();
    List *list2 = new List();
    List *list3 = new List();

    addTail(list1, 4);
    addTail(list1, 6);
    addTail(list1, 8);

    addTail(list2, 1);
    addTail(list2, 2);
    addTail(list2, 3);
    addTail(list2, 5);
    addTail(list2, 9);
    addTail(list2, 10);

    // addTail(list1, 2);
    // addTail(list1, 4);

    // addTail(list2, 1);
    // addTail(list2, 3);

    // List *list3 = new List();
    // list3 = concatList(list1, list2);
    // printList(list3);

    // List *list4 = new List();
    // mergeList(list4, list3);
    // printList(list4);

    mergeList(list1, list2);
    printList(list1);

    list3 = reverseList(list1);
    printList(list3);
}