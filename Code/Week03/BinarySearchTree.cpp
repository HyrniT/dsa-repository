#include <iostream>
#include <queue>

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

// Duyệt tiền thứ tự
void NLR(NODE *pRoot)
{
    if (pRoot == nullptr)
        return;
    cout << pRoot->key << " ";
    NLR(pRoot->p_left);
    NLR(pRoot->p_right);
}

// Duyệt trung thứ tự
void LNR(NODE *pRoot)
{
    if (pRoot == nullptr)
        return;
    NLR(pRoot->p_left);
    cout << pRoot->key << " ";
    NLR(pRoot->p_right);
}

// Duyệt hậu thứ tự
void LRN(NODE *pRoot)
{
    if (pRoot == nullptr)
        return;
    NLR(pRoot->p_left);
    NLR(pRoot->p_right);
    cout << pRoot->key << " ";
}

// Duyệt theo mức
void LevelOrder(NODE *pRoot)
{
    if (pRoot == nullptr)
        return;
    queue<NODE *> q;
    q.push(pRoot);
    while (!q.empty())
    {
        NODE *pNode = q.front();
        q.pop();
        cout << pNode->key << " ";
        if (pNode->p_left != nullptr)
            q.push(pNode->p_left);
        if (pNode->p_right != nullptr)
            q.push(pNode->p_right);
    }
}

// Tìm và trả về một NODE với giá trị cho trước
NODE *Search(NODE *pRoot, int x)
{
    if (pRoot == nullptr || pRoot->key == x)
        return pRoot;
    if (x < pRoot->key)
        return Search(pRoot->p_left, x);
    else
        return Search(pRoot->p_right, x);
}

// Thêm một NODE với giá trị cho trước vào cây nhị phân tìm kiếm
void Insert(NODE *&pRoot, int x)
{
    if (pRoot == nullptr)
    {
        pRoot = createNode(x);
        return;
    }
    if (x < pRoot->key)
        Insert(pRoot->p_left, x);
    else if (x > pRoot->key)
        Insert(pRoot->p_right, x);
    else
        return;
}

NODE *findMin(NODE *node)
{
    if (node == nullptr)
        return nullptr;
    if (node->p_left == nullptr)
        return node;
    else
        return findMin(node->p_left);
}

// Xoá một NODE với giá trị cho trước từ một cây nhị phân tìm kiếm
void Remove(NODE *&pRoot, int x)
{
    if (pRoot == nullptr)
        return;
    if (x < pRoot->key)
        Remove(pRoot->p_left, x);
    else if (x > pRoot->key)
        Remove(pRoot->p_right, x);
    else
    {
        if (pRoot->p_left == nullptr && pRoot->p_right == nullptr)
        {
            delete pRoot;
            pRoot = nullptr;
        }
        else if (pRoot->p_left == nullptr)
        {
            NODE *temp = pRoot;
            pRoot = pRoot->p_right;
            delete temp;
            temp = nullptr;
        }
        else if (pRoot->p_right == nullptr)
        {
            NODE *temp = pRoot;
            pRoot = pRoot->p_left;
            delete temp;
            temp = nullptr;
        }
        else
        {
            NODE *temp = findMin(pRoot->p_right);
            pRoot->key = temp->key;
            Remove(pRoot->p_right, temp->key);
        }
    }
}

// Khởi tạo một cây nhị phân tìm kiếm từ một mảng cho trước
NODE *createTree(int a[], int n)
{
    NODE *pRoot = nullptr;
    for (int i = 0; i < n; i++)
        Insert(pRoot, a[i]);
    return pRoot;
}

// Xóa hoàn toàn một cây nhị phân tìm kiếm
void removeTree(NODE *&pRoot)
{
    if (pRoot != nullptr)
    {
        removeTree(pRoot->p_left);
        removeTree(pRoot->p_right);
        delete pRoot;
        pRoot = nullptr;
    }
}

// Tính chiều cao của một cây nhị phân tìm kiếm (trả về -1 nếu không tồn tại)
int Height(NODE *pRoot)
{
    if (pRoot == nullptr)
        return -1;
    return max(Height(pRoot->p_left), Height(pRoot->p_right)) + 1;
}

// Đếm số lượng NODE của một cây nhị phân
int countNode(NODE *pRoot)
{
    if (pRoot == nullptr)
        return 0;
    return countNode(pRoot->p_left) + countNode(pRoot->p_right) + 1;
}

// Tính tổng giá trị của toàn bộ NODEs trong một cây nhị phân
int sumNode(NODE *pRoot)
{
    if (pRoot == nullptr)
        return 0;
    return sumNode(pRoot->p_left) + sumNode(pRoot->p_right) + pRoot->key;
}

// Tính toán chiều cao của một NODE với giá trị cho trước: (trả về -1 nếu không tồn tại)
int heightNode(NODE *pRoot, int value)
{
    if (pRoot == nullptr)
        return -1;
    if (value < pRoot->key)
        return heightNode(pRoot->p_left, value);
    else if (value > pRoot->key)
        return heightNode(pRoot->p_right, value);
    else
        return Height(pRoot);
}

// Tính toán tầng của một NODE cho trước
int Level(NODE *pRoot, NODE *p)
{
    if (p == NULL || p == pRoot)
        return 0;
    else if (p->key < pRoot->key)
        return Level(pRoot->p_left, p) + 1;
    else
        return Level(pRoot->p_right, p) + 1;
}

// Đếm số lá của một cây nhị phân
int countLeaf(NODE *pRoot)
{
    if (pRoot == nullptr)
        return 0;
    if (pRoot->p_left == nullptr && pRoot->p_right == nullptr)
        return 1;
    return countLeaf(pRoot->p_left) + countLeaf(pRoot->p_right);
}

// Đếm số NODE của một cây nhị phân tìm kiếm mà giá trị key nhỏ hơn giá trị cho trước
int countLess(NODE *pRoot, int x)
{
    if (pRoot == nullptr)
        return 0;
    if (x <= pRoot->key)
        return countLess(pRoot->p_left, x);
    return countLess(pRoot->p_left, x) + countLess(pRoot->p_right, x) + 1;
}

// Đếm số lượng NODE của một cây nhị phân tìm kiếm cho trước mà giá trị key lớn hơn giá trị cho trước
int countGreater(NODE *pRoot, int x)
{
    if (pRoot == nullptr)
        return 0;
    if (x >= pRoot->key)
        return countGreater(pRoot->p_right, x);
    return countLess(pRoot->p_left, x) + countLess(pRoot->p_right, x) + 1;
}

// Xác định cây nhị phân có phải là cây nhị phân tìm kiếm hay không
bool isBST(NODE *pRoot)
{
    if (pRoot == nullptr)
    {
        return true;
    }
    if (pRoot->p_left != nullptr && pRoot->p_left->key > pRoot->key)
    {
        return false;
    }
    if (pRoot->p_right != nullptr && pRoot->p_right->key < pRoot->key)
    {
        return false;
    }
    return isBST(pRoot->p_left) && isBST(pRoot->p_right);
}

// Xác định cây nhị phân có phải là cây nhị phân tìm kiếm đầy đủ hay không
bool isFullBST(NODE *pRoot)
{
    if (pRoot == nullptr)
        return true;
    if (pRoot->p_left == nullptr && pRoot->p_right == nullptr)
        return true;
    if (pRoot->p_left != nullptr && pRoot->p_right != nullptr)
        return isFullBST(pRoot->p_left) && isFullBST(pRoot->p_right);
    return false;
}

int main()
{
    // int a[5] = {2, 1, 4, 3, 5};
    // NODE *BinaryTree = createTree(a, 5);
    int a[6] = {5, 2, 1, 3, 4, 6};
    NODE *BinaryTree = createTree(a, 6);
    NLR(BinaryTree);
    cout << endl;
    LNR(BinaryTree);
    cout << endl;
    LRN(BinaryTree);
    cout << endl;
    cout << countLeaf(BinaryTree) << endl;
    cout << countNode(BinaryTree) << endl;
    cout << isBST(BinaryTree) << endl;
    cout << isFullBST(BinaryTree) << endl;
}