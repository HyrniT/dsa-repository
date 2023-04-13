#include <iostream>
#include <stack>

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
            if (currNode->key.id == student_id)
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

NODE *createNode(int data)
{
    NODE *newNode = new NODE();
    newNode->key = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->heigth = 0;
    return newNode;
}

int getHeight(NODE *node)
{
    if (node == nullptr)
        return 0;
    return node->heigth;
}

int getBalance(NODE *node)
{
    if (node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

void updateHeight(NODE *node)
{
    if (node == nullptr)
        return;
    node->heigth = max(getHeight(node->left), getHeight(node->right)) + 1;
}

void rotateRight(NODE *&node)
{
    NODE *temp = node->left;
    node->left = temp->right;
    temp->right = node;

    updateHeight(node);
    updateHeight(temp);

    node = temp;
}

void rotateLeft(NODE *node)
{
    NODE *temp = node->right;
    node->right = temp->left;
    temp->left = node;

    updateHeight(node);
    updateHeight(temp);

    node = temp;
}

void balance(NODE *&node)
{
    // Cây lệch trái
    if (getBalance(node) > 1)
    {
        // Cây lệch trái trái
        if (getBalance(node->left) > 0)
        {
            rotateRight(node);
        }
        // Cây lệch trái phải
        if (getBalance(node->left) < 0)
        {
            rotateLeft(node->left);
            rotateRight(node);
        }
    }
    // Cây lệch phải
    if (getBalance(node) < -1)
    {
        // Cây lệch phải phải
        if (getBalance(node->right) < 0)
        {
            rotateLeft(node);
        }
        // Cây lệch phải trái
        if (getBalance(node->right) > 0)
        {
            rotateRight(node->left);
            rotateLeft(node);
        }
    }

    updateHeight(node->left);
    updateHeight(node->right);
}

void insertNode(NODE *&root, int data) // không sử dụng đệ quy
{
    NODE *newNode = createNode(data);

    // Cây rỗng
    if (root == nullptr)
    {
        root = newNode;
        return;
    }

    NODE *currNode = root;
    NODE *parrNode = nullptr;

    while (currNode != nullptr)
    {
        parrNode = currNode;
        if (data < currNode->key)
            currNode = currNode->left;
        else if (data > currNode->key)
            currNode = currNode->right;
        else
            return;
    }

    if (data < parrNode->key)
        parrNode->left = newNode;
    if (data > parrNode->key)
        parrNode->right = newNode;

    // Cập nhật chiều cao và cân bằng cây
    while (parrNode != nullptr)
    {
        updateHeight(parrNode);
        balance(parrNode);

        parrNode = (parrNode == root) ? nullptr : parrNode;
        if (parrNode != nullptr)
            parrNode = (parrNode->left == newNode) ? parrNode->left : parrNode->right;
    }
}

void LNR(NODE *root)
{
    if (root == nullptr)
        return;
    LNR(root->left);
    cout << root->key << " ";
    LNR(root->right);
}

// Bai 7
void removeNode(NODE *&root, int data)
{
    // Cây rỗng
    if (root == nullptr)
        return;

    NODE *currNode = root;
    NODE *parrNode = nullptr;

    while (currNode != nullptr && currNode->key != data)
    {
        parrNode = currNode;
        if (data < currNode->key)
            currNode = currNode->left;
        if (data > currNode->key)
            currNode = currNode->right;
    }

    // Không tìm thấy giá trị cần xoá (khi này currNode ở vị trí phải nhất của cây trỏ NULL)
    if (currNode == nullptr)
        return;

    // Cây có con
    if (currNode->left != nullptr || currNode->right != nullptr)
    {
        NODE *childNode;
        // Có con bên trái
        if (currNode->left != nullptr)
            childNode = currNode->left;
        // Cây có con bên phải hoặc có 2 con
        else
            childNode = currNode->right;

        // Cập nhật liên kết giữa nút cha và nút con của nút cần xóa
        if (parrNode == nullptr) /////////////////////////////////////////////////////Chỗ này quan trọng //////////////////////////////////////////////////////
            root = childNode;
        else if (currNode == parrNode->left)
            parrNode->left = childNode;
        else
            parrNode->right = childNode;

        // Xóa nút cần xóa
        delete currNode;
        currNode = nullptr;
    }
    // Cây không có con
    else
    {
        if (parrNode->left == currNode)
            parrNode->left = nullptr;
        else
            parrNode->right = nullptr;

        // Xóa nút cần xóa
        delete currNode;
        currNode = nullptr;
    }

    // Cập nhật chiều cao và cân bằng cây
    while (parrNode != nullptr)
    {
        updateHeight(parrNode);
        balance(parrNode);

        parrNode = (parrNode == root) ? nullptr : parrNode; // Nếu mà không có thêm node gì thì trả về null
        if (parrNode != nullptr)
            parrNode = (parrNode->left == currNode) ? parrNode->left : parrNode->right;
    }
}

// Bai 8
bool checkExist(NODE *root, int data)
{
    if (root == nullptr)
        return false;

    NODE *currNode = root;
    while (currNode != nullptr)
    {
        if (data < currNode->key)
            currNode = currNode->left;
        else if (data > currNode->key)
            currNode = currNode->right;
        else
            return true;
    }

    return false;
}

// Bai 9
bool checkSum(NODE *root, int sum)
{
    if (root == nullptr)
        return false;

    stack<NODE *> stackNode;
    stackNode.push(root);

    NODE *tempNode = nullptr;

    while (!stackNode.empty())
    {
        tempNode = stackNode.top();
        stackNode.pop();

        if (checkExist(root, sum - tempNode->key) && tempNode->key != sum / 2) // Do trong cây nhị phân không có 2 node nào bằng nhau
            return true;

        if (tempNode->left != nullptr)
            stackNode.push(tempNode->left);
        if (tempNode->right != nullptr)
            stackNode.push(tempNode->right);
    }

    return false;
}

// Bai 10
void RNL(NODE *root)
{
    if (root == nullptr)
        return;
    RNL(root->right);
    cout << root->key << " ";
    RNL(root->left);
}

void kthLargestUtil(NODE *root, int &k, int &res)
{
    if (root == nullptr)
        return;

    kthLargestUtil(root->right, k, res);
    k--;
    if (k == 0)
    {
        res = root->key;
        return;
    }
    kthLargestUtil(root->left, k, res);
}

int kthLargest(NODE *root, int k)
{
    int res = -1;
    kthLargestUtil(root, k, res);
    return res;
}

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

    // Bai 6
    NODE *treeAVL = nullptr;
    insertNode(treeAVL, 10);
    insertNode(treeAVL, 100);
    insertNode(treeAVL, 20);
    insertNode(treeAVL, 30);
    insertNode(treeAVL, 40);
    insertNode(treeAVL, 50);
    LNR(treeAVL);

    // Bai 7
    cout << endl;
    cout << treeAVL->key << endl;
    removeNode(treeAVL, 10);
    cout << treeAVL->key << endl;
    LNR(treeAVL);
    cout << endl;

    // Bai 8
    if (checkExist(treeAVL, 60))
        cout << "exist" << endl;
    else
        cout << "non-exist" << endl;

    // Bai 9
    if (checkSum(treeAVL, 200))
        cout << "exist" << endl;
    else
        cout << "non-exist" << endl;

    // Bai 10
    cout << kthLargest(treeAVL, 2) << endl;
    return 0;
}
