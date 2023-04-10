#include <iostream>

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

    while(temp_node != nullptr)
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

    NODE *temp_node = pRoot;
    NODE *parent_node = nullptr;

    while (temp_node != nullptr)
    {
        parent_node = temp_node;
        if (x < temp_node->key)
            temp_node = temp_node->p_left;
        else if (x > temp_node->key)
            temp_node = temp_node->p_right;
        else
            return;
    }

    if (x < parent_node->key)
        parent_node->p_left = new_node;
    else // x >= parent_node->key (tuy nhiên không có trường hợp dấu bằng)
        parent_node->p_right = new_node;
}

// Xoá một NODE với giá trị cho trước từ một cây nhị phân tìm kiếm: (Không sử dụng đệ quy)
void Remove(NODE* &pRoot, int x)
{
    NODE* temp_node = pRoot;
    while()
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
    LNR(BST);
    cout << endl;
    NODE *new_node = Search(BST, 3);
    if (new_node != nullptr)
        cout << new_node->key << endl;
    else
        cout << "Not find" << endl;
}