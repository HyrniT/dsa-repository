#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point
{
    vector<int> coordinates;
};

struct Node
{
    Point location;
    Node *left;
    Node *right;
};

Node *createNode(Point location)
{
    Node *newNode = new Node();
    newNode->location = location;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void sortPoints(vector<Point> &points, int axis)
{
    sort(points.begin(), points.end(), [&](Point a, Point b)
         { return a.coordinates[axis] < b.coordinates[axis]; });
}

Node *createTree(vector<Point> &points, int depth)
{
    int k = points[0].coordinates.size();
    int axis = depth % k;

    // Sort to get median
    sortPoints(points, axis);

    int medianIndex = points.size() / 2;
    Point median = points[medianIndex];

    Node *root = createNode(median);

    if (medianIndex > 0)
    {
        vector<Point> leftPoints(points.begin(), points.begin() + medianIndex);
        createTree(leftPoints, depth + 1);
    }

    if (medianIndex < points.size() - 1)
    {
        vector<Point> rightPoints(points.begin() + medianIndex + 1, points.end());
        createTree(rightPoints, depth + 1);
    }
    return root;
}

Node *insert(Node *root, Point &point, int depth)
{
    if (root == nullptr)
        return createNode(point);

    int k = root->location.coordinates.size();
    int axis = depth % k;

    if (point.coordinates[axis] < root->location.coordinates[axis])
        root->left = insert(root->left, point, depth + 1);
    else
        root->right = insert(root->right, point, depth + 1);

    return root;
}

Node *findMin(Node *root, int depth)
{
    if (root == nullptr)
        return nullptr;

    int k = root->location.coordinates.size();
    int axis = depth % k;

    // If the current axis is equal to the given depth
    if (axis == depth)
    {
        if (root->left == nullptr)
            return root;
        return findMin(root->left, depth + 1);
    }

    if (axis == depth)
    {
        if (root->left == nullptr)
            return root;
        return findMin(root->right, depth + 1);
    }

    Node *leftMin = findMin(root->left, depth + 1);
    Node *rightMin = findMin(root->right, depth + 1);

    if (leftMin == nullptr)
        return rightMin;
    if (rightMin == nullptr)
        return leftMin;

    return (leftMin->location.coordinates[axis] <
            rightMin->location.coordinates[axis])
               ? leftMin
               : rightMin;
}

Node *remove(Node *root, Point &point, int depth)
{
    if (root == nullptr)
        return nullptr;

    int k = root->location.coordinates.size();
    int axis = depth % k;

    // If the point axis is equal to the root node axis
    if (point.coordinates[axis] == root->location.coordinates[axis])
    {
        // If the root node is a leaf node
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }
        // If the root node has right child
        else if (root->right != nullptr)
        {
            Node *minNode = findMin(root->right, depth);
        }
    }
    // If the point axis is less than the root node axis
    else if (point.coordinates[axis] < root->location.coordinates[axis])
        root->left = remove(root->left, point, depth + 1);
    // If the point axis is more than the root node axis
    else
        root->right = remove(root->right, point, depth + 1);

    return root;
}

void printKdTree(Node *node, std::string prefix = "", bool isLeft = false)
{
    if (node == nullptr)
        return;

    cout << prefix;
    cout << (isLeft ? "├── " : "└── ");

    cout << "(";
    for (int i = 0; i < node->location.coordinates.size(); ++i)
    {
        cout << node->location.coordinates[i];
        if (i < node->location.coordinates.size() - 1)
            cout << ", ";
    }
    cout << ")" << endl;

    printKdTree(node->left, prefix + (isLeft ? "│   " : "    "), true);

    printKdTree(node->right, prefix + (isLeft ? "│   " : "    "), false);
}

int main() {
    std::vector<Point> pointList = {
        { {3, 6} },
        { {17, 15} },
        { {13, 15} },
        { {6, 12} },
        { {9, 1} },
        { {2, 7} },
        { {10, 19} }
    };

    Node* root = createTree(pointList, 0);
    printKdTree(root);

    Point newPoint = { {8, 5} };
    root = insert(root, newPoint, 0);

    cout << "After insertion:" << endl;
    printKdTree(root);

    Point pointToDelete = { {6, 12} };
    root = remove(root, pointToDelete, 0);

    cout << "After deletion:" << endl;
    printKdTree(root);
}