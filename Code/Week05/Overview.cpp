#include <iostream>

using namespace std;

// Bai 1

struct Person
{
    string id;
    string name;
    int year;
};

struct Node
{
    Person key;
    Node *next;
};

Node *createNode(Person person)
{
    Node *newNode = new Node();
    newNode->key.id = person.id;
    newNode->key.name = person.name;
    newNode->key.year = person.year;
    newNode->next = nullptr;
    return newNode;
}

void printNode(Node *node)
{
    cout << "ID: " << node->key.id << endl;
    cout << "Name: " << node->key.name << endl;
    cout << "Year: " << node->key.year << endl;
}

// Bai 2
class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    Node *getTail()
    {
        return tail;
    }

    Node *getHead()
    {
        return head;
    }
    // appendNode ~ Append_Node_2_Linked_List
    void appendNode(string student_id, string name, int birth_year)
    {
        Person person = {student_id, name, birth_year};
        Node *newNode = createNode(person);

        if (head == nullptr && tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList()
    {
        Node *currNode = head;
        while (currNode != nullptr)
        {
            printNode(currNode);
            currNode = currNode->next;
        }
    }

    // Bai 3
    // insertNode ~ Insert_Node_2_Linked_List
    void insertNode(string student_id, string name, int birth_year, int index)
    {
        if (index < 0)
            return;

        Person person = {student_id, name, birth_year};
        Node *newNode = createNode(person);

        if (index == 0)
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        else
        {
            int i = 0;
            Node *currNode = head;
            while (currNode != nullptr)
            {
                i++;
                if (i == index)
                {
                    newNode->next = currNode->next;
                    currNode->next = newNode;
                    break;
                }
                else
                    currNode = currNode->next;
            }
        }
        if (newNode->next == nullptr)
            tail = newNode;
    }

    // Bai 4
    // deleteNode ~ Delete_Node_By_Id
    void deleteNode(string deleted_student_id)
    {
        if (head == nullptr)
            return;

        Node *currNode = head;

        // Xoá node đầu danh sách
        if (head->key.id == deleted_student_id)
        {
            head = head->next;
            delete currNode;
            currNode = nullptr;
            return;
        }

        Node *prevNode = nullptr;

        // Xoá node giữa danh sách
        while (currNode->next != nullptr)
        {
            if (currNode->key.id == deleted_student_id)
            {
                prevNode->next = currNode->next;
                delete currNode;
                currNode = nullptr;
                return;
            }
            else
            {
                prevNode = currNode;    
                currNode = currNode->next;
            }
        }
        // Xoá node cuối danh sách
        if (tail->key.id == deleted_student_id)
        {
            prevNode->next = nullptr;
            tail = prevNode;
            delete currNode;
            currNode = nullptr;
        }
    }

    // Bai 5
    // updateNode ~ Modify_Name_By_Id
    void updateNode(string student_id, string new_name)
    {
        if (head == nullptr)
            return;

        Node *currNode = head;

        while (currNode != nullptr)
        {
            if(currNode->key.id == student_id)
            {
                currNode->key.name = new_name;
                break;
            }
            else
            {
                currNode = currNode->next;
            }
        }
    }
};

// Bai 6
struct NODE
{
    int key;
    NODE *left;
    NODE *right;
    int heigth;
};




int main()
{
    // Bai 1
    // Person p1 = {"123", "Nguyen Van A", 2004};
    // Node *node1 = createNode(p1);
    // printNode(node1);

    // Bai 2
    // LinkedList list;
    // list.appendNode("123", "Nguyen Van A", 2004);
    // cout << "Linked list value: " << endl;
    // list.printList();

    // Bai 3
    // LinkedList list1;
    // list1.appendNode("123", "Nguyen Van A", 2004);
    // list1.appendNode("125", "Vo Van C", 2004);
    // list1.insertNode("124", "Tran Thi B", 2004, 1);
    // list1.printList();

    // Bai 4
    // list1.deleteNode("125");
    // list1.printList();

    // Bai 5
    // list1.updateNode("123", "Truong Thi Z");
    // list1.printList();

    return 0;
}
