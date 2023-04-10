#include <iostream>
#include <stack>

using namespace std;

struct NODE
{
    int key;
    NODE *p_left;
    NODE *p_right;
};

// Khởi tạo một NODE từ một giá trị cho trước
NODE *createNode(int data)
{
    NODE *new_node = new NODE();
    new_node->key = data;
    new_node->p_left = nullptr;
    new_node->p_right = nullptr;
    return new_node;
}

// Tìm và trả về một NODE với giá trị cho trước từ một cây nhị phân tìm kiếm: (Không sử dụng đệ quy)
NODE *Search(NODE *pRoot, int x)
{
    if (pRoot == nullptr)
        return nullptr;

    NODE *temp_node = pRoot;

    while (temp_node != nullptr)
    {
        if (x < temp_node->key)
            temp_node = temp_node->p_left;
        else if (x > temp_node->key)
            temp_node = temp_node->p_right;
        else // x == temp_node->key
            return temp_node;
    }

    return nullptr;
}

// Thêm một NODE với giá trị cho trước vào cây nhị phân tìm kiếm: (Không sử dụng đệ quy)
void Insert(NODE *&pRoot, int x)
{
    NODE *new_node = createNode(x);
    if (pRoot == nullptr)
    {
        pRoot = new_node;
        return;
    }

    NODE *current_node = pRoot;
    NODE *parent_node = nullptr;

    while (current_node != nullptr)
    {
        parent_node = current_node;
        if (x < current_node->key)
            current_node = current_node->p_left;
        else if (x > current_node->key)
            current_node = current_node->p_right;
        else
            return;
    }

    if (x < parent_node->key)
        parent_node->p_left = new_node;
    else // x >= parent_node->key
        parent_node->p_right = new_node;
}

// Xoá một NODE với giá trị cho trước từ một cây nhị phân tìm kiếm: (Không sử dụng đệ quy)
NODE *findMin(NODE *node)
{
    if (node == nullptr)
        return nullptr;
    NODE *temp_node = node;
    while (temp_node->p_left != nullptr)
        temp_node = temp_node->p_left;
    return temp_node;
}

void Remove(NODE *&pRoot, int x)
{
    if (pRoot == nullptr)
        return;
    NODE *parent_node = nullptr; // lưu trữ nút cha của nút cần xóa
    NODE *current_node = pRoot;  // lưu trữ nút hiện tại

    while (current_node != nullptr && current_node->key != x)
    {
        parent_node = current_node;
        if (x < current_node->key)
            current_node = current_node->p_left;
        else
            current_node = current_node->p_right;
    }

    // Trường hợp 1: Nút cần xóa không có con
    if (current_node->p_left == nullptr && current_node->p_right == nullptr)
    {
        if (current_node == parent_node->p_left)
            parent_node->p_left = nullptr;
        else
            parent_node->p_right = nullptr;
        delete current_node;
        current_node = nullptr;
    }
    // Trường hợp 2: Nút cần xóa có một con
    else if (current_node->p_left == nullptr || current_node->p_right == nullptr)
    {
        NODE *temp = current_node->p_left ? current_node->p_left : current_node->p_right;

        if (current_node == pRoot)
            pRoot = temp;
        else if (current_node == parent_node->p_left)
            parent_node->p_left = temp;
        else
            parent_node->p_right = temp;

        delete current_node;
        current_node = nullptr;
    }
    // Trường hợp 3: Nút cần xóa có hai con
    else
    {
        NODE *successor = findMin(current_node->p_right); // tìm nút kế tiếp của nút cần xóa
        current_node->key = successor->key;               // gán giá trị của nút kế tiếp vào nút cần xóa
        // Remove(current_node->p_right, successor->key);    // xóa nút kế tiếp
        delete successor;
        successor = nullptr;
    }
}

// Kiểm tra cây BST có tồn tại 2 giá trị a, b sao cho a + b = k hay không
bool check(NODE *pRoot, int k)
{
    if (pRoot == nullptr)
        return false;

    stack<NODE *> nodeStack;
    nodeStack.push(pRoot);

    NODE *a_node = nullptr;
    NODE *b_node = nullptr;

    while (!nodeStack.empty())
    {
        a_node = nodeStack.top();
        nodeStack.pop();

        b_node = Search(pRoot, k - a_node->key);

        if (b_node != nullptr && b_node != a_node)
            return true;

        if (a_node->p_right != nullptr)
            nodeStack.push(a_node->p_right);
        if (a_node->p_left != nullptr)
            nodeStack.push(a_node->p_left);
    }

    return false;
}

// Xác định một cây nhị phân có phải là cây AVL không
int getHeight(NODE *node)
{
    if (node == nullptr)
        return 0;
    
    int leftHeight = getHeight(node->p_left);
    int rightHeight = getHeight(node->p_right);
    return 1 + max(leftHeight, rightHeight);
}

bool isAVL(NODE *pRoot)
{
    if (pRoot == nullptr)
        return true;
    
    int leftHeight = getHeight(pRoot->p_left);
    int rightHeight = getHeight(pRoot->p_right);
    int balanceFactor = abs(leftHeight - rightHeight);

    if (balanceFactor > 1)
        return false;

    return isAVL(pRoot->p_left) && isAVL(pRoot->p_right);
}

// Duyệt trung thứ tự
void LNR(NODE *pRoot)
{
    if (pRoot == nullptr)
        return;
    LNR(pRoot->p_left);
    cout << pRoot->key << " ";
    LNR(pRoot->p_right);
}

int main()
{
    NODE *BST = createNode(0);
    Insert(BST, 2);
    Insert(BST, 1);
    Insert(BST, -2);
    Insert(BST, -2);
    Insert(BST, 3);
    LNR(BST);
    cout << endl;
    if (Search(BST, 4) == nullptr)
        cout << "Not find" << endl;
    Remove(BST, 3);
    LNR(BST);
    cout << endl;
    cout << check(BST, 0) << endl;
    cout << isAVL(BST) << endl;
}