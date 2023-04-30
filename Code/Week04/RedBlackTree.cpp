#include <iostream>

using namespace std;

static bool RED = 1;
static bool BLACK = 0;

struct NODE
{
    int data;
    NODE *parent;
    NODE *left;
    NODE *right;
    bool color;
};

// Khởi tạo một NODE từ một giá trị cho trước
NODE *createNode(int data)
{
    NODE *new_node = new NODE();
    new_node->data = data;
    new_node->parent = nullptr;
    new_node->left = nullptr;
    new_node->right = nullptr;
    new_node->color = RED;
}

// Tìm và trả về một NODE với giá trị cho trước
NODE *Search(NODE *node, int x)
{
    if (node == nullptr || node->data == x)
        return node;
    if (x < node->data)
        return Search(node->left, x);
    else
        return Search(node->right, x);
}

// Thêm một NODE có giá trị cho trước vào cây RED-BLACK cho trước (Chú ý giá trị cho trước có tồn tại hay chưa)
void rotateLeft(NODE *&node)
{
    NODE *pX = node->right;
    NODE *pY = pX->left;

    pX->left = node;
    node->right = pX->left;

    node->parent = pX;
    if (pY != nullptr)
        pY->parent = node;

    node = pX;
}

void rotateRight(NODE *&node)
{
    NODE *pX = node->left;
    NODE *pY = pX->right;

    pX->right = node;
    node->left = pY;

    node->parent = pX;
    if (pY != nullptr)
        pY->parent = node;

    node = pX;
}

void Insert(NODE *&pRoot, int x)
{
    NODE *new_node = createNode(x);
    NODE *prev_node = nullptr;
    NODE *curr_node = new_node;

    while (curr_node != nullptr)
    {
        prev_node = curr_node;
        if (x < curr_node->data)
            curr_node = curr_node->left;
        else if (x > curr_node->data)
            curr_node = curr_node->right;
        else
            return;
    }

    new_node->parent = prev_node;
    if (prev_node == nullptr)
        pRoot = new_node;
    else if (x < prev_node->data)
        prev_node->left = new_node;
    else
        prev_node->right = new_node;

    fixInsert(new_node);
}

void fixInsert(NODE *new_node)
{
    NODE *parent_node = new_node->parent;
    NODE *grandparent_node = nullptr;

    while (parent_node != nullptr && parent_node->color == RED)
    {
        grandparent_node = parent_node->parent;

        if(grandparent_node->left == parent_node)
        {
            NODE* uncle_node = grandparent_node->right;
            if(uncle_node != nullptr && uncle_node->color == RED)
            {
                // Case 1: Uncle is RED
                grandparent_node->color = RED;
                parent_node->color = BLACK;
                uncle_node->color = BLACK;

                new_node = grandparent_node; // bắt đầu xét tiếp từ node grandparent
                parent_node = new_node->parent;
            }
            else // nếu uncle đen (vì node null cũng là node đen nên không quan tâm có null hay không)
            {
                // Case 2: Uncle is BLACK
                //             grandparent (...)
                //     parent (R)              uncle (B)
                // ...         new (R)     ...         ...
                if(parent_node->right == new_node)
                {
                    new_node = parent_node; // gán để khi xoay cây xong new và parent không bị swap
                    rotateLeft(new_node);
                    parent_node = new_node->parent; // gán lại parent sau khi xoay
                }
                parent_node->color = BLACK;
                grandparent_node->color = RED;
                rotateRight(grandparent_node); 
                //           grandparent (B)
                //    new (R)              parent (R)
                // ...    ...           ...         uncle (B)
            }
        }
        else // grandparent_node->right == parent_node
        {
            NODE* uncle_node = grandparent_node->left;
            if(uncle_node != nullptr && uncle_node->color == RED)
            {
                // Case 3: Uncle is RED
                grandparent_node->color = RED;
                parent_node->color = BLACK;
                uncle_node->color = BLACK;

                new_node = grandparent_node;
                parent_node = new_node->parent;
            }
            else
            {
                // Case 4: Uncle is BLACK
                //             grandparent (...)
                //     uncle (B)              parent (R)
                // ...         ...      new (R)         ...
                if(parent_node->left == new_node)
                {
                    new_node = parent_node;
                    rotateRight(new_node);
                    parent_node = new_node->parent;
                }
                parent_node->color = BLACK;
                grandparent_node->color = RED;
                rotateLeft(grandparent_node);
                //             grandparent (B)
                //      parent (R)             new (R)
                // unclde (B)    ...       ...         ...
            }
        }
    }
    // Ensure the root is BLACK
    NODE* root = new_node;
    while (root->parent != NULL) {
        root = root->parent;
    }
    root->color = BLACK;
}

// Xóa một NODE với giá trị cho trước từ một cây RED-BLACK cho trước (Chú ý giá trị đó có tồn tại hay không)
void Remove(NODE *&pRoot, int x)
{
}

int main()
{
}
