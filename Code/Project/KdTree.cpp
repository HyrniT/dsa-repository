#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

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

bool comparePoints(const Point &a, const Point &b, int axis)
{
    return a.coordinates[axis] < b.coordinates[axis];
}

void sortPoints(vector<Point> &points, int axis)
{
    sort(points.begin(), points.end(), [&](const Point &a, const Point &b)
         { return comparePoints(a, b, axis); });
}

Node *createTree(vector<Point> &points, int depth)
{
    if (points.empty())
    {
        return nullptr;
    }

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
        root->left = createTree(leftPoints, depth + 1);
    }

    if (medianIndex < points.size() - 1)
    {
        vector<Point> rightPoints(points.begin() + medianIndex + 1, points.end());
        root->right = createTree(rightPoints, depth + 1);
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

Node *findMin(Node *root, int depth, int axis)
{
    if (root == nullptr)
        return nullptr;

    int k = root->location.coordinates.size();
    int currentAxis = depth % k;

    Node *leftMin = findMin(root->left, depth + 1, axis);
    Node *rightMin = findMin(root->right, depth + 1, axis);

    Node *nodeMin = root;

    if (leftMin != nullptr && leftMin->location.coordinates[axis] < nodeMin->location.coordinates[axis])
        nodeMin = leftMin;
    if (rightMin != nullptr && rightMin->location.coordinates[axis] < nodeMin->location.coordinates[axis])
        nodeMin = rightMin;

    return nodeMin;
}

Node *remove(Node *root, Point &point, int depth)
{
    if (root == nullptr)
        return nullptr;

    int k = root->location.coordinates.size();
    int axis = depth % k;

    if (point.coordinates == root->location.coordinates)
    {
        // If the right child exists
        if (root->right != nullptr)
        {
            // Find the min node in the right subtree
            Node *nodeMin = findMin(root->right, depth + 1, axis);
            // Replace the root node with the min node
            root->location = nodeMin->location;
            // Recursively delete the min node in the right subtree
            root->right = remove(root->right, nodeMin->location, depth + 1);
        }
        // If the left child exists
        else if (root->left != nullptr)
        {
            // Find the min node in the left subtree
            Node *nodeMin = findMin(root->left, depth + 1, axis);
            // Replace the root node with the min node
            root->location = nodeMin->location;
            // Recursively delete the min node in the left subtree
            root->left = remove(root->left, nodeMin->location, depth + 1);
        }
        else
        {
            delete root;
            root = nullptr;
        }
    }
    else if (point.coordinates[axis] <= root->location.coordinates[axis])
        root->left = remove(root->left, point, depth + 1);
    else
        root->right = remove(root->right, point, depth + 1);

    return root;
}

double calculateDistance(const Point &a, const Point &b)
{
    double distance = 0.0;

    for (int i = 0; i < a.coordinates.size(); i++)
        distance += pow(a.coordinates[i] - b.coordinates[i], 2);

    return sqrt(distance);
}

bool shouldSearchOtherSubtree(const Point &target, const Point &currentBest, double *bestDistance, int axis)
{
    double distanceOnAxis = abs(target.coordinates[axis] - currentBest.coordinates[axis]);
    return distanceOnAxis <= *bestDistance;
}

Node *findNearestNeighbor(Node *root, const Point &target, int depth, Node *bestNode, double *bestDistance)
{
    if (root == nullptr)
        return bestNode;

    int k = root->location.coordinates.size();
    int axis = depth % k;

    Node *currentBest = bestNode;
    double currentDistance = calculateDistance(root->location, target);

    if (currentDistance < *bestDistance)
    {
        bestNode = root;
        *bestDistance = currentDistance;
    }

    Node *nearChild = nullptr;
    Node *farChild = nullptr;

    if (target.coordinates[axis] < root->location.coordinates[axis])
    {
        nearChild = root->left;
        farChild = root->right;
    }
    else
    {
        nearChild = root->right;
        farChild = root->left;
    }

    bestNode = findNearestNeighbor(nearChild, target, depth + 1, bestNode, bestDistance);

    if (shouldSearchOtherSubtree(target, root->location, bestDistance, axis))
        bestNode = findNearestNeighbor(farChild, target, depth + 1, bestNode, bestDistance);

    return bestNode;
}

void printPoint(Node *node)
{
    cout << "(";
    for (int i = 0; i < node->location.coordinates.size(); ++i)
    {
        cout << node->location.coordinates[i];
        if (i < node->location.coordinates.size() - 1)
            cout << ", ";
    }
    cout << ")" << endl;
}

void printKdTree(Node *node, string prefix = "", bool isLeft = true)
{
    if (node == nullptr)
        return;

    cout << prefix;
    cout << (isLeft ? "|---" : "'---");

    printPoint(node);

    printKdTree(node->left, prefix + (isLeft ? "|   " : "    "), true);

    printKdTree(node->right, prefix + (isLeft ? "|   " : "    "), false);
}

int main()
{
    vector<Point> pointList = {
        {{3, 6}},
        {{17, 15}},
        {{13, 15}},
        {{6, 12}},
        {{9, 1}},
        {{2, 7}},
        {{10, 19}}};

    Node *root = createTree(pointList, 0);
    printKdTree(root);
    cout << endl;

    Point newPoint = {{8, 5}};
    root = insert(root, newPoint, 0);

    cout << "After insertion (8, 5):" << endl;
    printKdTree(root);
    cout << endl;

    Point deletePoint = {{6, 12}};
    root = remove(root, deletePoint, 0);

    cout << "After deletion (6, 12):" << endl;
    printKdTree(root);
    cout << endl;

    double bestDistance = numeric_limits<double>::max();
    Point target = {{8, 10}};
    Node *nearestNode = findNearestNeighbor(root, target, 0, nullptr, &bestDistance);

    cout << "Nearest Neighbor to (8, 10): ";
    printPoint(nearestNode);

    return 0;
}
