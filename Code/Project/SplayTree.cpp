#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;
};

Node* createNode(int key)
{
    Node* newNode = new Node();
    newNode->key = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* rotateRight(Node* root)
{
    Node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}

Node* rotateLeft(Node* root)
{
    Node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}

Node* splay(Node* root, int key)
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
            if (root->left->right != nullptr)
                root->left = rotateLeft(root->left);
        }

        /* Second rotate */
        if (root->left != nullptr)
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
        if (key > root->right->key)
        {
            root->right->right = splay(root->right->right, key);
            root = rotateLeft(root);
        }
        // Zig-Zag
        else if (key < root->right->key)
        {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != nullptr)
                root->right = rotateRight(root->right);
        }
        /* Second rotate */
        if (root->right != nullptr)
            root = rotateLeft(root);

        return root;
    }
}

Node* insert(Node* root, int key)
{
    if (root == nullptr)
        return createNode(key);

    // START: Recursive solution
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    // END: Recursive solution

    // START: Non-recursive solution
    // Node* newNode = createNode(key);
    // Node* current = root;
    // Node* parent = nullptr;

    // while (current != nullptr) {
    //     parent = current;

    //     if (key < current->key) {
    //         current = current->left;
    //     } else if (key > current->key) {
    //         current = current->right;
    //     } else {
    //         current->key = key;
    //         splay(root, key);
    //         return root;
    //     }
    // }

    // if (key < parent->key)
    //     parent->left = newNode;
    // else
    //     parent->right = newNode;
    // END: Non-recursive solution

    return splay(root, key);
}

Node* remove(Node* root, int key)
{
    if (root == nullptr)
        return root;

    root = splay(root, key);

    if (root->key != key)
        return root;

    Node* temp = nullptr;

    if (root->left == nullptr)
    {
        temp = root;
        root = root->right;
    }
    else
    {
        temp = root;
        root = splay(root->left, key);
        root->right = temp->right;
    }

    delete temp;
    temp = nullptr;
    return root;
}

void printSplayTree(Node* root, const string& prefix = "", bool isLeft = true)
{
    if (root == nullptr)
        return;

    cout << prefix;
    cout << (isLeft ? "|---" : "'---");
    cout << "(" << root->key << ")" << endl;

    printSplayTree(root->left, prefix + (isLeft ? "|   " : "    "), true);
    printSplayTree(root->right, prefix + (isLeft ? "|   " : "    "), false);
}

int main()
{
    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);

    printSplayTree(root);
    cout << endl;

    root = insert(root, 80);
    cout << "After insertion (80):" << endl;
    printSplayTree(root);
    cout << endl;

    root = remove(root, 40);
    cout << "After deletion (40):" << endl;
    printSplayTree(root);
    cout << endl;
    return 0;
}