#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
};

Node *createNode(int key)
{
    Node *newNode = new Node();
    newNode->key = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node *rotateRight(Node *root)
{
    Node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}

Node *rotateLeft(Node *root)
{
    Node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}

Node *splay(Node *root, int key)
{
    // cout<<root->key<<endl;
    if (root == nullptr || root->key == key)
        return root;

    if (key < root->key)
    {
        // Not exist key in tree
        if (root->left == nullptr)
            return root;

        /* First rotate */ 
        // Zig-Zig
        if (key < root->left->key)
        {
            root->left->left = splay(root->left->left, key);
            root = rotateRight(root);
        }
        // Zag-Zig
        else if (key > root->left->key)
        {
            root->left->right = splay(root->left->right, key);
            // Exist key in tree
            if(root->left->right != nullptr)
                root->left = rotateLeft(root->left);
        }

        /* Second rotate */
        if(root->left != nullptr)
            root = rotateRight(root);

        return root;
    }
    else // key > root->key
    {
        // Not exist key in tree
        if (root->right == nullptr)
            return root;
        
        /* First rotate */
        // Zag-Zag
        if(key > root->right->key)
        {
            root->right->right = splay(root->right->right, key);
            root = rotateLeft(root);
        }
        // Zig-Zag
        else if(key < root->right->key)
        {
            root->right->left = splay(root->right->left, key);
            if(root->right->left != nullptr)
                root->right = rotateRight(root->right);
        }
        /* Second rotate */
        if(root->right != nullptr)
            root = rotateLeft(root);

        return root;
    }
}

Node* insert(Node* root, int key)
{
    if(root == nullptr)
        return createNode(key);
    
    // if(key < root->key)
    // {
    //     // if(root->left == nullptr)
    //     //     root->left = createNode(key);
    //     // else
    //     root->left = insert(root->left, key);
    //     // root = rotateRight(root);
    //     // root = splay(root, key);
    // }
    // else if(key > root->key)
    // {
    //     // if(root->right == nullptr)
    //     //     root->right = createNode(key);
    //     // else
    //     root->right = insert(root->right, key);
    //     // root = rotateLeft(root);
    //     // root = splay(root, key);
    // }

    Node* current = root;
    Node* parent = nullptr;
    Node* newNode = createNode(key);

    while(current != nullptr)
    {
        parent = current;
        if(key < current->key)
            current = current->left;
        else if(key > current->key)
            current = current->right;
        else // key == current->key
            return splay(current, key);
    }

    if (key < parent->key) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    // cout<<root->key<<endl;
    return splay(root, key);
}

void printSplayTree(Node* root, const std::string& prefix = "", bool isLeft = false) {
    if (root == nullptr) {
        return;
    }

    std::cout << prefix;
    std::cout << (isLeft ? "├──" : "└──");
    std::cout << "(" << root->key << ")" << std::endl;

    printSplayTree(root->left, prefix + (isLeft ? "│   " : "    "), true);
    printSplayTree(root->right, prefix + (isLeft ? "│   " : "    "), false);
}

Node* insert1(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }

    if (value < root->key) {
        root->left = insert1(root->left, value);
    }
    else if (value > root->key) {
        root->right = insert1(root->right, value);
    }

    return root;
}



int main()
{
    // Node* root = nullptr;
    // root = insert(root, 50);
    // root = insert(root, 30);
    // // root = insert(root, 70);
    // // root = insert(root, 20);
    // // root = insert(root, 40);
    // // root = insert(root, 60);
    // // root = insert(root, 80);

    // std::cout << "Inorder traversal of the splay tree:\n";
    // printSplayTree(root);
    // std::cout << std::endl;

    Node * temp = nullptr;
    temp = insert(temp, 50);
    temp = insert(temp, 30);
    temp = insert(temp, 70);
    temp = insert(temp, 20);
    // temp = rotateRight(temp);
    // temp = insert(temp, 70);
    // temp = insert(temp, 20);
    printSplayTree(temp);
    // temp = rotateLeft(temp);
    // printSplayTree(temp);

    return 0;
}