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
    // appendNode ~ Append_Node_2_Linked_List
    void appendNode(string student_id, string name, int birth_year)
    {
        Person person = {student_id, name, birth_year};
        Node *newNode = new Node();
        newNode->key = person;
        newNode->next = nullptr;

        if (tail == nullptr)
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

    // Print the value of the linked list
    void printList()
    {
        Node *currNode = head;

        while (currNode != nullptr)
        {
            cout << "ID: " << currNode->key.id << endl;
            cout << "Name: " << currNode->key.name << endl;
            cout << "Year of birth: " << currNode->key.year << endl;
            cout << endl;
            currNode = currNode->next;
        }
    }

    // Bai 3
    // insertNode ~ Insert_Node_2_Linked_List
    // void insertNode(string student_id, string name, int birth_year, int index)
    // {
    //     if (index < 0)
    //         return;

    //     Person person = {student_id, name, birth_year};
    //     Node *newNode = createNode(person);

    //     if (index == 0)
    //     {
    //         newNode->next = head;
    //         head = newNode;
    //     }
    //     else
    //     {
    //         int iNode = 0;
    //         Node* currNode = head;
    //         while (currNode != nullptr)
    //         {
    //             iNode++;
    //             if(iNode == index)
    //             {
    //                 currNode->next = newNode;
    //                 newNode->next = currNode->next;
    //             }
    //             if(newNode->next == nullptr)
    //                 tail = newNode;
    //             currNode = currNode->next;
    //         }
    //     }
    // }
};

int main()
{
    // Bai 1
    // Person p1 = {"123", "Nguyen Van A", 2004};
    // Node *node1 = createNode(p1);
    // printNode(node1);

    // Bai 2
    LinkedList list;
    list.appendNode("123", "Nguyen Van A", 2004);
    cout << "Linked list value: " << endl;
    list.printList();

    // Bai 3
    // LinkedList list1;
    // list1.appendNode("123", "Nguyen Van A", 2004);
    // list1.appendNode("125", "Vo Van C", 2004);
    // // list1.insertNode("124", "Tran Thi B", 2004, 1);
    // list1.printList();

    return 0;
}
