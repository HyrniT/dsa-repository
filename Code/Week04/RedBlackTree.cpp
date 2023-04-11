#include <iostream>

using namespace std;

static int RED = 1;
static int BLACK = 0;

struct NODE
{
    int data;
    NODE *parent;
    NODE *left;
    NODE *right;
    int color;
};

// Khởi tạo một NODE từ một giá trị cho trước
NODE* createNode(int data)
{
    NODE* new_node = new NODE();
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

    node->right = pX->left;
    pX->left = node;

    node->parent = pX;
    if(pY != nullptr)
        pY->parent = node;
    
    node = pX;
}

void rotateRight(NODE *&node)
{
    NODE* nRoot = node->left;
    node->left = nRoot->right;
    nRoot->right = node;
    node->parent = nRoot;
    node = nRoot;
}

void Insert(NODE* &pRoot, int x)
{

}

// Xóa một NODE với giá trị cho trước từ một cây RED-BLACK cho trước (Chú ý giá trị đó có tồn tại hay không)
void Remove(NODE* &pRoot, int x)
{

}

int main ()
{

}


