// #include <iostream>

// using namespace std;

// const bool RED = 1;
// const bool BLACK = 0;
// const int COUNT = 10;

// struct NODE
// {
//     int data;
//     NODE *parent;
//     NODE *left;
//     NODE *right;
//     bool color;
// };

// // Khởi tạo một NODE từ một giá trị cho trước
// NODE *createNode(int data)
// {
//     NODE *new_node = new NODE();
//     new_node->data = data;
//     new_node->parent = nullptr;
//     new_node->left = nullptr;
//     new_node->right = nullptr;
//     new_node->color = RED;
//     return new_node;
// }

// // Tìm và trả về một NODE với giá trị cho trước
// NODE *Search(NODE *node, int x)
// {
//     if (node == nullptr || node->data == x)
//         return node;
//     if (x < node->data)
//         return Search(node->left, x);
//     else
//         return Search(node->right, x);
// }

// // Thêm một NODE có giá trị cho trước vào cây RED-BLACK cho trước (Chú ý giá trị cho trước có tồn tại hay chưa)
// void rotateRight(NODE *&root)
// {
//     NODE *x = root->left;
//     // Gán x->right vào left root
//     root->left = x->right;
//     if (x->right != NULL)
//         x->right->parent = root;

//     // Gán root vào x.right
//     x->right = root;
//     root->parent = x;

//     // Trả về x
//     root = x;
// }

// void rotateLeft(NODE *root)
// {
//     NODE *y = root->right;
//     // Gán y->left vào right root
//     root->right = y->left;
//     if (y->left != NULL)
//         y->left->parent = root;

//     // Gán root vào y.left
//     y->left = root;
//     root->parent = y;

//     // Trả về y;
//     root = y;
// }

// // void fixInsert(NODE *new_node)
// // {
// //     NODE *parent_node = new_node->parent;
// //     NODE *grandparent_node = nullptr;

// //     while (parent_node != nullptr && parent_node->color == RED)
// //     {
// //         grandparent_node = parent_node->parent;

// //         if (grandparent_node->left == parent_node)
// //         {
// //             NODE *uncle_node = grandparent_node->right;
// //             if (uncle_node != nullptr && uncle_node->color == RED)
// //             {
// //                 // Case 1: Uncle is RED
// //                 grandparent_node->color = RED;
// //                 parent_node->color = BLACK;
// //                 uncle_node->color = BLACK;

// //                 new_node = grandparent_node; // bắt đầu xét tiếp từ node grandparent
// //                 parent_node = new_node->parent;
// //             }
// //             else // nếu uncle đen (vì node null cũng là node đen nên không quan tâm có null hay không)
// //             {
// //                 // Case 2: Uncle is BLACK
// //                 //             grandparent (...)
// //                 //     parent (R)              uncle (B)
// //                 // ...         new (R)     ...         ...
// //                 if (parent_node->right == new_node)
// //                 {
// //                     new_node = parent_node; // gán để khi xoay cây xong new và parent không bị swap
// //                     rotateLeft(new_node);
// //                     parent_node = new_node->parent; // gán lại parent sau khi xoay
// //                 }
// //                 parent_node->color = BLACK;
// //                 grandparent_node->color = RED;
// //                 rotateRight(grandparent_node);
// //                 //           grandparent (B)
// //                 //    new (R)              parent (R)
// //                 // ...    ...           ...         uncle (B)
// //             }
// //         }
// //         else // grandparent_node->right == parent_node
// //         {
// //             NODE *uncle_node = grandparent_node->left;
// //             if (uncle_node != nullptr && uncle_node->color == RED)
// //             {
// //                 // Case 3: Uncle is RED
// //                 grandparent_node->color = RED;
// //                 parent_node->color = BLACK;
// //                 uncle_node->color = BLACK;

// //                 new_node = grandparent_node;
// //                 parent_node = new_node->parent;
// //             }
// //             else
// //             {
// //                 // Case 4: Uncle is BLACK
// //                 //             grandparent (...)
// //                 //     uncle (B)              parent (R)
// //                 // ...         ...      new (R)         ...
// //                 if (parent_node->left == new_node)
// //                 {
// //                     new_node = parent_node;
// //                     rotateRight(new_node);
// //                     parent_node = new_node->parent;
// //                 }
// //                 parent_node->color = BLACK;
// //                 grandparent_node->color = RED;
// //                 rotateLeft(grandparent_node);
// //                 //             grandparent (B)
// //                 //      parent (R)             new (R)
// //                 // unclde (B)    ...       ...         ...
// //             }
// //         }
// //     }
// //     // Ensure the root is BLACK
// //     NODE *root = new_node;
// //     while (root->parent != NULL)
// //     {
// //         root = root->parent;
// //     }
// //     root->color = BLACK;
// // }

// void fixInsert(NODE *new_node)
// {
//     NODE *parent_node = new_node->parent;
//     NODE *grandparent_node = nullptr;
//     while (parent_node != nullptr && parent_node->color == RED)
//     {
//         grandparent_node = parent_node->parent;

//         if (grandparent_node == nullptr)
//         {
//             // Parent node is the root node, color it black and return
//             parent_node->color = BLACK;
//             return;
//         }

//         if (grandparent_node->left == parent_node)
//         {
//             NODE *uncle_node = grandparent_node->right;
//             if (uncle_node != nullptr && uncle_node->color == RED)
//             {
//                 // Case 1: Uncle is RED
//                 grandparent_node->color = RED;
//                 parent_node->color = BLACK;
//                 uncle_node->color = BLACK;

//                 new_node = grandparent_node;
//                 parent_node = new_node->parent;
//             }
//             else
//             {
//                 if (parent_node->right == new_node)
//                 {
//                     // Case 2: Uncle is BLACK and new node is on the right of parent node
//                     new_node = parent_node;
//                     rotateLeft(new_node);
//                     parent_node = new_node->parent;
//                 }
//                 // Case 3: Uncle is BLACK and new node is on the left of parent node
//                 parent_node->color = BLACK;
//                 grandparent_node->color = RED;
//                 rotateRight(grandparent_node);
//             }
//         }
//         else
//         {
//             NODE *uncle_node = grandparent_node->left;
//             if (uncle_node != nullptr && uncle_node->color == RED)
//             {
//                 // Case 1: Uncle is RED
//                 grandparent_node->color = RED;
//                 parent_node->color = BLACK;
//                 uncle_node->color = BLACK;

//                 new_node = grandparent_node;
//                 parent_node = new_node->parent;
//             }
//             else
//             {
//                 if (parent_node->left == new_node)
//                 {
//                     // Case 2: Uncle is BLACK and new node is on the left of parent node
//                     new_node = parent_node;
//                     rotateRight(new_node);
//                     parent_node = new_node->parent;
//                 }
//                 // Case 3: Uncle is BLACK and new node is on the right of parent node
//                 parent_node->color = BLACK;
//                 grandparent_node->color = RED;
//                 rotateLeft(grandparent_node);
//             }
//         }
//     }
//     // Color the root node black
//     NODE *root = new_node;
//     while (root->parent != nullptr)
//     {
//         root = root->parent;
//     }
//     root->color = BLACK;
// }

// NODE *insert(NODE *pRoot, int x)
// {
//     NODE *new_node = createNode(x);
//     NODE *prev_node = nullptr;
//     NODE *curr_node = pRoot;

//     // Tìm vị trí chèn node mới
//     while (curr_node != nullptr)
//     {
//         prev_node = curr_node;
//         if (x < curr_node->data)
//             curr_node = curr_node->left;
//         else if (x > curr_node->data)
//             curr_node = curr_node->right;
//         else
//             return pRoot;
//     }

//     // Chèn node mới vào cây
//     new_node->parent = prev_node;
//     if (prev_node == nullptr)
//         pRoot = new_node;
//     else if (x < prev_node->data)
//         prev_node->left = new_node;
//     else
//         prev_node->right = new_node;

//     // Cân bằng lại cây
//     fixInsert(new_node);

//     // Nếu node gốc bị thay đổi thì cập nhật lại pRoot
//     while (pRoot->parent != nullptr)
//         pRoot = pRoot->parent;

//     return pRoot;
// }

// // Xóa một NODE với giá trị cho trước từ một cây RED-BLACK cho trước (Chú ý giá trị đó có tồn tại hay không)
// void Remove(NODE *&pRoot, int x)
// {
// }

// // string getColor(NODE *pRoot)
// // {
// //     if (pRoot->color == 1)
// //         return "RED";
// //     return "BLACK";
// // }

// // In - Print 2D ra console
// void print2DUtil(NODE *pRoot, int space)
// {
//     if (pRoot == nullptr)
//     {
//         return;
//     }
//     space += COUNT;

//     print2DUtil(pRoot->right, space);

//     cout << endl;
//     for (int i = COUNT; i < space; i++)
//     {
//         cout << " ";
//     }

//     cout << pRoot->data << " (";
//     if (pRoot->color == BLACK)
//     {
//         cout << "BLACK";
//     }
//     else
//     {
//         cout << "RED";
//     }
//     cout << ")" << endl;

//     print2DUtil(pRoot->left, space);
// }

// void print2D(NODE *pRoot)
// {
//     print2DUtil(pRoot, 0);
// }

// void LNR(NODE *pRoot)
// {
//     if (pRoot == nullptr)
//         return;
//     LNR(pRoot->left);
//     cout << pRoot->data << " ";
//     LNR(pRoot->right);
// }

// int main()
// {
//     NODE *root = nullptr;
//     // Insert(RedBlackTree, 1);
//     // Insert(RedBlackTree, 4);
//     // Insert(RedBlackTree, 6);
//     // Insert(RedBlackTree, 3);
//     // Insert(RedBlackTree, 5);
//     // Insert(RedBlackTree, 7);
//     // Insert(RedBlackTree, 8);
//     // Insert(RedBlackTree, 2);
//     // Insert(RedBlackTree, 9);
//     root = insert(root, 10);
//     root = insert(root, 20);
//     root = insert(root, 30);
//     root = insert(root, 15);
//     root = insert(root, 18);
//     root = insert(root, 25);
//     root = insert(root, 40);

//     print2D(root);
//     // LNR(RedBlackTree);
// }

#include <iostream>
#include <cmath>

using namespace std;
#define COUNT 10

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *parent;
    bool color;
    // 1 -> Red   | 0 -> Black
};

Node *maxValueNode(Node *root)
{
    Node *current = root;

    // Tìm kiếm Node có giá trị lớn nhất
    while (current->right != nullptr)
        current = current->right;

    return current;
}

Node *sibling(Node *current)
{
    if (current->parent == nullptr)
        return nullptr;
    if (current->parent->left == current)
        return current->parent->right;
    return current->parent->left;
}

void swapColors(Node *x1, Node *x2)
{
    bool temp;
    temp = x1->color;
    x1->color = x2->color;
    x2->color = temp;
}

void swapValues(Node *x1, Node *x2)
{
    int temp;
    temp = x1->data;
    x1->data = x2->data;
    x2->data = temp;
}

bool hasRedChild(Node *x)
{
    if (x->right != nullptr)
        if (x->right->color == 1)
            return true;
    if (x->left != nullptr)
        if (x->left->color == 1)
            return true;
    return false;
}


Node *rotateRight(Node *root)
{
    Node *x = root->left;
    root->left = x->right;
    if (x->right != nullptr)
        x->right->parent = root;

    x->right = root;
    root->parent = x;

    return x;
}

Node *rotateLeft(Node *root)
{
    Node *y = root->right;
    root->right = y->left;
    if (y->left != nullptr)
        y->left->parent = root;

    y->left = root;
    root->parent = y;

    return y;
}

struct RedBlackTree
{
    Node *Root;
    bool ll = false;
    bool rr = false;
    bool lr = false;
    bool rl = false;
    RedBlackTree()
    {
        Root = nullptr;
    }
    Node *insertHelp(Node *root, int key)
    {
        // f đúng khi có xung đột RED RED
        bool f = false;

        if (root == nullptr)
        {
            return new Node{key, nullptr, nullptr, nullptr, 1}; // RED Node
        }
        else if (key < root->data)
        {
            root->left = insertHelp(root->left, key);
            root->left->parent = root;
            // root->left = Node X
            // root       = X->parent
            if (root != Root)
            {
                if (root->color == root->left->color == 1)
                    f = true;
            }
        }
        else
        {
            root->right = insertHelp(root->right, key);
            root->right->parent = root;
            // root->right = Node X
            // root        = X->parent
            if (root != Root)
            {
                if (root->color == root->right->color == 1)
                    f = true;
            }
        }

        // Xử lý 4 TH lệch
        // *** Khi này (ll, lr, rr, rl = false) nên chưa xử lí liền
        // *** Sau khi thoát 1 vòng đệ quy thì: root = X->parent->parent
        // *** Tức là Node ông, lúc này ta quay Node ông
        // Case 1 : Left left - Trái trái
        if (ll)
        {
            root = rotateRight(root);
            root->color = 0;
            root->right->color = 1;
            ll = false;
        }
        // Case 2 : Right right - Phải phải
        else if (rr)
        {
            root = rotateLeft(root);
            root->color = 0;
            root->left->color = 1;
            rr = false;
        }
        // Case 3 : Left right - Phải trái
        else if (lr)
        {
            root->left = rotateLeft(root->left);
            root->left->parent = root;

            root = rotateRight(root);
            root->color = 0;
            root->right->color = 1;
            lr = false;
        }
        // Case 4 : Right left - Phải trái
        else if (rl)
        {
            root->right = rotateRight(root->right);
            root->right->parent = root;

            root = rotateLeft(root);
            root->color = 0;
            root->left->color = 1;
            rl = false;
        }

        // Xử lí xung đột đỏ - RED RED
        if (f)
        {
            if (root->parent->right == root)
            {
                if (root->parent->left == nullptr || root->parent->left->color == 0)
                {
                    // Cha đỏ - chú đen (rr or rl)
                    if (root->left != nullptr && root->left->color == 1)
                        rl = true;
                    if (root->right != nullptr && root->right->color == 1)
                        rr = true;
                }
                else
                {
                    // Cha đỏ - chú đỏ
                    root->color = root->parent->left->color = 0;
                    if (root != Root)
                        root->parent->color = 1;
                }
            }
            else // root->parent->left == root
            {
                if (root->parent->right == nullptr || root->parent->right->color == 0)
                {
                    // Cha đỏ - chú đen (ll or lr)
                    if (root->left != nullptr && root->left->color == 1)
                        ll = true;
                    if (root->right != nullptr && root->right->color == 1)
                        lr = true;
                }
                else
                {
                    // Cha đỏ - chú đỏ
                    root->color = root->parent->right->color = 0;
                    if (root != Root)
                        root->parent->color = 1;
                }
            }
            f = false;
        }
        return root;
    }

    void Insert(int key)
    {
        if (Root == nullptr)
        {
            Root = new Node{key, nullptr, nullptr, nullptr, 0};
        }
        else
        {
            Root = insertHelp(Root, key);
            if (Root->color == 1)
                Root->color = 0;
        }
    }

    void fixDoubleBlack(Node *root)
    {
        if (root == Root)
            return;
        Node *sib = sibling(root);
        Node *par = root->parent;

        if (sib == nullptr)
            fixDoubleBlack(par);
        else
        {
            if (sib->color == 1)
            {
                par->color = 1;
                sib->color = 0;

                if (sib->parent->left == sib)
                    par = rotateRight(par);
                else
                    par = rotateLeft(par);

                fixDoubleBlack(root);
            }
            else
            {
                if (hasRedChild(sib))
                {
                    if (sib->parent->left == sib)
                    {
                        if (sib->left != nullptr && sib->left->color)
                        {
                            sib->left->color = sib->color;
                            sib->color = par->color;
                            par->color = 0;

                            par = rotateRight(par);
                        }
                        else
                        {
                            sib->right->color = par->color;
                            par->color = 0;
                            sib = rotateLeft(sib);
                            par = rotateRight(par);
                        }
                    }
                    else
                    {
                        if (sib->right != nullptr && sib->right->color)
                        {
                            sib->right->color = sib->color;
                            sib->color = par->color;
                            par->color = 0;

                            par = rotateLeft(par);
                        }
                        else
                        {
                            sib->left->color = par->color;
                            par->color = 0;
                            sib = rotateRight(sib);
                            par = rotateLeft(par);
                        }
                    }
                }
                else
                {
                    sib->color = 1;
                    if (par->color == 0)
                        fixDoubleBlack(par);
                    else
                        par->color = 0;
                }
            }
        }
    }

    void deleteNode(Node *vDelete)
    {
        Node *uReplace;

        if ((vDelete->left != nullptr) && (vDelete->right != nullptr))
            uReplace = maxValueNode(vDelete->left);
        else if (vDelete->left != nullptr)
            uReplace = vDelete->left;
        else if (vDelete->right != nullptr)
            uReplace = vDelete->right;
        else
            uReplace = nullptr;

        bool uvBlack = ((uReplace == nullptr) || (uReplace->color == 0)) && (vDelete->color == 0);
        Node *par = vDelete->parent;
        Node *sib = sibling(vDelete);
        if (uReplace == nullptr)
        {
            if (vDelete == Root)
            {
                Root = nullptr;
            }
            else
            {
                if (uvBlack)
                    fixDoubleBlack(vDelete);
                else if (sib != nullptr)
                    sib->color = 1;

                if (vDelete->parent->left == vDelete)
                    par->left = nullptr;
                else
                    par->right = nullptr;
            }
            delete vDelete;
            return;
        }

        if (vDelete->left == nullptr || vDelete->right == nullptr)
        {
            if (vDelete == Root)
            {
                vDelete->data = uReplace->data;
                vDelete->left = vDelete->right = nullptr;
                delete uReplace;
            }
            else
            {
                if (vDelete->parent->left == vDelete)
                    par->left = uReplace;
                else
                    par->right = uReplace;
                delete vDelete;

                uReplace->parent = par;
                if (uvBlack)
                    fixDoubleBlack(uReplace);
                else
                    uReplace->color = 0;
            }
            return;
        }
        swapValues(uReplace, vDelete);
        deleteNode(uReplace);
    }

    Node *search(int val)
    {
        Node *temp = Root;
        while (temp != nullptr)
        {
            if (val < temp->data)
            {
                if (temp->left == nullptr)
                    return nullptr;
                else
                    temp = temp->left;
            }
            else if (val == temp->data)
            {
                break;
            }
            else
            {
                if (temp->right == nullptr)
                    return nullptr;
                else
                    temp = temp->right;
            }
        }
        return temp;
    }

    void Delete(int val)
    {
        Node *vDelete = search(val);
        if (vDelete == nullptr)
        {
            cout << "\n ** Khong tim thay Node can xoa **\n";
            return;
        }
        else
        {
            deleteNode(vDelete);
        }
        return;
    }
};

string getColor(Node *root)
{
    if (root->color == 1)
        return "RED";
    return "BLACK";
}

// In - Print 2D ra console
void print2DUtil(Node *root, int space)
{
    if (root == nullptr)
        return;
    space += COUNT;

    print2DUtil(root->right, space);
    cout << endl;

    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->data << " (" << getColor(root) << ") "
         << "\n";

    print2DUtil(root->left, space);
}

void print2D(Node *root)
{
    print2DUtil(root, 0);
}

int main()
{
    RedBlackTree RBTree;
    RBTree.Insert(1);
    RBTree.Insert(4);
    RBTree.Insert(6);
    RBTree.Insert(3);
    RBTree.Insert(5);
    RBTree.Insert(7);
    RBTree.Insert(8);
    RBTree.Insert(2);
    RBTree.Insert(9);

    print2D(RBTree.Root);
    cout << "\n---------------------------\n";
    RBTree.Delete(5);
    print2D(RBTree.Root);
    return 0;
}