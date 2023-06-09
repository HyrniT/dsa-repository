#include <iostream>
#include <queue>

using namespace std;

struct Node
{
	int key;
	Node* left;
	Node* right;
	int height;
};

Node* createNode(int key)
{
	Node* newNode = new Node();
	newNode->key = key;
	newNode->left = nullptr;
	newNode->right = nullptr;
	newNode->height = 1;
	return newNode;
}

int getHeight(Node* node)
{
	if (node == nullptr)
		return 0;
	return node->height;
}

void updateHeight(Node*& node)
{
	if (node == nullptr)
		return;
	node->height = max(getHeight(node->left), getHeight(node->right));
}

int getBalance(Node* node)
{
	if (node == nullptr)
		return 0;
	return getHeight(node->left) - getHeight(node->right);
}

void rotateLeft(Node*& node)
{
	Node* temp = node->right;
	node->right = temp->left;
	temp->left = node;

	updateHeight(node);
	updateHeight(temp);

	node = temp;
}

void rotateRight(Node*& node)
{
	Node* temp = node->left;
	node->left = temp->right;
	temp->right = node;

	updateHeight(node);
	updateHeight(temp);

	node = temp;
}

void rotateLeftRight(Node*& node)
{
	rotateLeft(node->right);
	rotateRight(node);
}

void rotateRightLeft(Node*& node)
{
	rotateRight(node->left);
	rotateLeft(node);
}

void balance(Node*& node)
{
	if (node == nullptr)
		return;
	if (getBalance(node) > 1)
	{
		if (getBalance(node->left) >= 0)
			rotateRight(node);
		else
			rotateLeftRight(node);
	}
	if (getBalance(node) < -1)
	{
		if (getBalance(node->right) <= 0)
			rotateLeft(node);
		else
			rotateRightLeft(node);
	}
}

void insert(Node*& root, int key)
{
	if (root == nullptr)
		root = createNode(key);
	else if (key < root->key)
		insert(root->left, key);
	else if (key > root->key)
		insert(root->right, key);
	else
		return;

	updateHeight(root);
	balance(root);
}

Node* findMinNode(Node* node)
{
	if (node == nullptr)
		return nullptr;
	while (node->left != nullptr)
		node = node->left;
	return node;
}

void remove(Node*& root, int key)
{
	if (root == nullptr)
		return;
	else if (key < root->key)
		remove(root->left, key);
	else if (key > root->key)
		remove(root->right, key);
	else
	{
		if (root->left == nullptr && root->right == nullptr)
		{
			delete root;
			root = nullptr;
		}
		else if (root->left == nullptr)
		{
			Node* temp = root;
			root = root->right;
			delete temp;
			temp = nullptr;
		}
		else if (root->right == nullptr)
		{
			Node* temp = root;
			root = root->left;
			delete temp;
			temp = nullptr;
		}
		else
		{
			Node* minNode = findMinNode(root->right);
			root->key = minNode->key;
			remove(root->right, minNode->key);
		}
	}

	updateHeight(root);
	balance(root);
}

void printLevelOrder(Node* root)
{
	if (root == nullptr)
		return;
	queue<Node*> queue;
	queue.push(root);
	while (!queue.empty())
	{
		Node* temp = queue.front();
		queue.pop();
		cout << temp->key << " ";
		if (temp->left != nullptr)
			queue.push(temp->left);
		if (temp->right != nullptr)
			queue.push(temp->right);
	}
}

int main()
{
	Node* treeAVL = nullptr;
	insert(treeAVL, 3);
	insert(treeAVL, 2);
	insert(treeAVL, 1);
	insert(treeAVL, 0);
	insert(treeAVL, 4);
	insert(treeAVL, 5);
	remove(treeAVL, 2);
	printLevelOrder(treeAVL);
}