#include <iostream>
#include <queue>

using namespace std;

struct NODE
{
    int key;
    NODE *p_left;
    NODE *p_right;
    int height;
};

// Khởi tạo một NODE từ một giá trị cho trước
NODE *createNode(int data)
{
    NODE *new_node = new NODE();
    new_node->key = data;
    new_node->p_left = nullptr;
    new_node->p_right = nullptr;
    new_node->height = 0;
    return new_node;
}

// Xác định chiều cao của một NODE
int getHeight(NODE *pRoot)
{
    if (pRoot == nullptr)
        return 0;
    return pRoot->height;
}

// Xác định hệ số cân bằng
int getBalanceFactor(NODE *pRoot)
{
    if (pRoot == nullptr)
        return 0;
    return getHeight(pRoot->p_left) - getHeight(pRoot->p_right);
}

// Cập nhập lại chiều cao của một NODE
void updateHeight(NODE *&pRoot)
{
    if (pRoot == nullptr)
        return;
    pRoot->height = max(getHeight(pRoot->p_left), getHeight(pRoot->p_right)) + 1;
}

// Xoay trái (khi cây lệch phải)
//  1                   2
//   \                 / \
//    2    ---->      1   3
//     \
//      3
void rotateLeft(NODE *&pRoot)
{
    NODE *nRoot = pRoot->p_right;
    pRoot->p_right = nRoot->p_left;
    nRoot->p_left = pRoot;

    updateHeight(pRoot);
    updateHeight(nRoot);

    pRoot = nRoot;
}

// Xoay phải (khi cây lệch trái)
//      3               2
//     /               / \
//    2     ---->     1   3
//   /
//  1
void rotateRight(NODE *&pRoot)
{
    NODE *nRoot = pRoot->p_left;
    pRoot->p_left = nRoot->p_right;
    nRoot->p_right = pRoot;

    updateHeight(pRoot);
    updateHeight(nRoot);

    pRoot = nRoot;
}

// Xoay trái phải
//     3                  3*                 2
//    /    (xoay trái)   /    (xoay phải)   / \
//   1*       ---->     2        ---->     1   3
//    \                /
//     2              1
void rotateLeftRight(NODE *&pRoot)
{
    rotateLeft(pRoot->p_left);
    rotateRight(pRoot);
}

// Xoay phải trái
//   1                   1*                      2
//    \    (xoay phải)    \      (xoay trái)    / \
//     3*     ---->        2        ---->      1   3
//    /                     \
//   2                       3
void rotateRightLeft(NODE *&pRoot)
{
    rotateRight(pRoot->p_right);
    rotateLeft(pRoot);
}

// Cây AVL: độ lệch tối đa giữa độ cao của cây con trái và cây con phải
// của một nút bất kỳ không vượt quá 1 ( <= 1 )
// Cân bằng cây
void Balance(NODE *&pRoot)
{
    if (pRoot == nullptr)
        return;
    // Cây lệch sang trái
    if (getBalanceFactor(pRoot) > 1)
    {
        // Cây con trái bên trái dài hơn hoặc bằng cây con phải bên trái
        if (getBalanceFactor(pRoot->p_left) >= 0)
        {
            rotateRight(pRoot);
        }
        // Cây con phải bên trái dài hơn cây con trái bên trái
        else
        {
            rotateLeftRight(pRoot);
        }
    }
    // Cây lệch bên phải
    if (getBalanceFactor(pRoot) < -1)
    {
        // Cây con phải bên phải dài hơn hoặc bằng cây con trái bên phải
        if (getBalanceFactor(pRoot->p_right) <= 0)
        {
            rotateLeft(pRoot);
        }
        // Cây con trái bên phải dài hơn cây con phải bên phải
        else
        {
            rotateRightLeft(pRoot);
        }
    }
    // Cân bằng lại các cây con
    Balance(pRoot->p_left);
    Balance(pRoot->p_right);
}

// Thêm một NODE có giá trị cho trước vào cây AVL cho trước
// void Insert(NODE *&pRoot, int x)
// {
//     if (pRoot == nullptr)
//         pRoot = createNode(x);
//     if (x < pRoot->key)
//         Insert(pRoot->p_left, x);
//     else if (x > pRoot->key)
//         Insert(pRoot->p_right, x);
//     else
//         return;
//     Balance(pRoot);
// }

void UpdateHeight(NODE* node) {
    node->height = max(getHeight(node->p_left), getHeight(node->p_right)) + 1;
}

NODE* LeftRotate(NODE* node) {
    NODE* newRoot = node->p_right;
    node->p_right = newRoot->p_left;
    newRoot->p_left = node;

    UpdateHeight(node);
    UpdateHeight(newRoot);

    return newRoot;
}

NODE* RightRotate(NODE* node) {
    NODE* newRoot = node->p_left;
    node->p_left = newRoot->p_right;
    newRoot->p_right = node;

    UpdateHeight(node);
    UpdateHeight(newRoot);

    return newRoot;
}

void Insert(NODE* &pRoot, int x) {
    if (pRoot == nullptr) {
        pRoot = createNode(x);
        return;
    }
    if (x < pRoot->key) {
        Insert(pRoot->p_left, x);
    }
    else {
        Insert(pRoot->p_right, x);
    }

    UpdateHeight(pRoot);

    int balanceFactor = getBalanceFactor(pRoot);
    if (balanceFactor > 1 && x < pRoot->p_left->key) {
        pRoot = RightRotate(pRoot);
    }
    else if (balanceFactor < -1 && x > pRoot->p_right->key) {
        pRoot = LeftRotate(pRoot);
    }
    else if (balanceFactor > 1 && x > pRoot->p_left->key) {
        pRoot->p_left = LeftRotate(pRoot->p_left);
        pRoot = RightRotate(pRoot);
    }
    else if (balanceFactor < -1 && x < pRoot->p_right->key) {
        pRoot->p_right = RightRotate(pRoot->p_right);
        pRoot = LeftRotate(pRoot);
    }
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
    LNR(pRoot->p_left);
    cout << pRoot->key << " ";
    LNR(pRoot->p_right);
}

// Duyệt hậu thứ tự
void LRN(NODE *pRoot)
{
    if (pRoot == nullptr)
        return;
    LRN(pRoot->p_left);
    LRN(pRoot->p_right);
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

int main()
{
    NODE* treeAVL = nullptr;
    Insert(treeAVL, 3);
    Insert(treeAVL, 2);
    Insert(treeAVL, 1);
    Insert(treeAVL, 0);

    LevelOrder(treeAVL);cout<<endl;
    // rotateRight(treeAVL);
    // LevelOrder(treeAVL);cout<<endl;

    // NLR(treeAVL);cout<<endl;
    // LNR(treeAVL);cout<<endl;
    // LRN(treeAVL);cout<<endl;
}