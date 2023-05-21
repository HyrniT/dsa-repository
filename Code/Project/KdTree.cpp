#include <iostream>
#include <vector>

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

Node *findMin(Node *root, int dimension)
{
    if (root = nullptr)
        return nullptr;

    int k = root->location.coordinates.size();
    int axis = dimension % k;

    if (axis == dimension)
    {
        if (root->left == nullptr)
            return root;
        return findMin(root->right, dimension);
    }

    Node *leftMin = findMin(root->left, dimension);
    Node *rightMin = findMin(root->right, dimension);

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
}