#include <iostream>
using namespace std;


struct NODE2
{
    string student_id;
    string name;
    int birth_year;
    NODE2 *p_next;
};

struct List
{
    NODE2 *p_head;
    NODE2 *p_tail;
};

NODE2* createNode(string student_id, string name, int birth_year)
{
    NODE2* newNode = new NODE2;
    newNode->student_id = student_id;
    newNode->name = name;
    newNode->birth_year = birth_year;
    newNode->p_next = nullptr;
    return newNode;
}


void printNode(NODE2* node)
{
    cout << "Student ID: " << node->student_id << endl;
    cout << "Name: " << node->name << endl;
    cout << "Birth year: " << node->birth_year << endl;
}

void addNode(List& list, NODE2* newNode)
{
    if (list.p_head == nullptr) {
        list.p_head = newNode;
        list.p_tail = newNode;
    } else {
        list.p_tail->p_next = newNode;
        list.p_tail = newNode;
    }
}

void changeName(List& list, string student_id, string new_name)
{
    NODE2* currentNode = list.p_head;
    while (currentNode != nullptr) {
        if (currentNode->student_id == student_id) {
            currentNode->name = new_name;
            return;
        }
        currentNode = currentNode->p_next;
    }
    // Student ID not found
    cout << "Student ID not found in the list" << endl;
}



int main()
{
    NODE2 *node = createNode("123", "Nguyễn Văn A", 2004);
    printNode(node);
}