// #include <iostream>
// #include <queue>

// using namespace std;

// struct Node
// {
// 	int key;
// 	Node* left;
// 	Node* right;
// 	int height;
// };

// Node* createNode(int key)
// {
// 	Node* newNode = new Node();
// 	newNode->key = key;
// 	newNode->left = nullptr;
// 	newNode->right = nullptr;
// 	newNode->height = 1;
// 	return newNode;
// }

// int getHeight(Node* node)
// {
// 	if (node == nullptr)
// 		return 0;
// 	return node->height;
// }

// void updateHeight(Node*& node)
// {
// 	if (node == nullptr)
// 		return;
// 	node->height = max(getHeight(node->left), getHeight(node->right));
// }

// int getBalance(Node* node)
// {
// 	if (node == nullptr)
// 		return 0;
// 	return getHeight(node->left) - getHeight(node->right);
// }

// void rotateLeft(Node*& node)
// {
// 	Node* temp = node->right;
// 	node->right = temp->left;
// 	temp->left = node;

// 	updateHeight(node);
// 	updateHeight(temp);

// 	node = temp;
// }

// void rotateRight(Node*& node)
// {
// 	Node* temp = node->left;
// 	node->left = temp->right;
// 	temp->right = node;

// 	updateHeight(node);
// 	updateHeight(temp);

// 	node = temp;
// }

// void rotateLeftRight(Node*& node)
// {
// 	rotateLeft(node->right);
// 	rotateRight(node);
// }

// void rotateRightLeft(Node*& node)
// {
// 	rotateRight(node->left);
// 	rotateLeft(node);
// }

// void balance(Node*& node)
// {
// 	if (node == nullptr)
// 		return;
// 	if (getBalance(node) > 1)
// 	{
// 		if (getBalance(node->left) >= 0)
// 			rotateRight(node);
// 		else
// 			rotateLeftRight(node);
// 	}
// 	if (getBalance(node) < -1)
// 	{
// 		if (getBalance(node->right) <= 0)
// 			rotateLeft(node);
// 		else
// 			rotateRightLeft(node);
// 	}
// }

// void insert(Node*& root, int key)
// {
// 	if (root == nullptr)
// 		root = createNode(key);
// 	else if (key < root->key)
// 		insert(root->left, key);
// 	else if (key > root->key)
// 		insert(root->right, key);
// 	else
// 		return;

// 	updateHeight(root);
// 	balance(root);
// }

// Node* findMinNode(Node* node)
// {
// 	if (node == nullptr)
// 		return nullptr;
// 	while (node->left != nullptr)
// 		node = node->left;
// 	return node;
// }

// void remove(Node*& root, int key)
// {
// 	if (root == nullptr)
// 		return;
// 	else if (key < root->key)
// 		remove(root->left, key);
// 	else if (key > root->key)
// 		remove(root->right, key);
// 	else
// 	{
// 		if (root->left == nullptr && root->right == nullptr)
// 		{
// 			delete root;
// 			root = nullptr;
// 		}
// 		else if (root->left == nullptr)
// 		{
// 			Node* temp = root;
// 			root = root->right;
// 			delete temp;
// 			temp = nullptr;
// 		}
// 		else if (root->right == nullptr)
// 		{
// 			Node* temp = root;
// 			root = root->left;
// 			delete temp;
// 			temp = nullptr;
// 		}
// 		else
// 		{
// 			Node* minNode = findMinNode(root->right);
// 			root->key = minNode->key;
// 			remove(root->right, minNode->key);
// 		}
// 	}

// 	updateHeight(root);
// 	balance(root);
// }

// void printLevelOrder(Node* root)
// {
// 	if (root == nullptr)
// 		return;
// 	queue<Node*> queue;
// 	queue.push(root);
// 	while (!queue.empty())
// 	{
// 		Node* temp = queue.front();
// 		queue.pop();
// 		cout << temp->key << " ";
// 		if (temp->left != nullptr)
// 			queue.push(temp->left);
// 		if (temp->right != nullptr)
// 			queue.push(temp->right);
// 	}
// }

// int main()
// {
// 	Node* treeAVL = nullptr;
// 	insert(treeAVL, 3);
// 	insert(treeAVL, 2);
// 	insert(treeAVL, 1);
// 	insert(treeAVL, 0);
// 	insert(treeAVL, 4);
// 	insert(treeAVL, 5);
// 	remove(treeAVL, 2);
// 	printLevelOrder(treeAVL);
// }

#include <iostream>
#define COUNT 10
using namespace std;

struct Node
{
	int key;
	Node* left;
	Node* right;
	Node* parent;
	bool color;
};

Node* rotateLeft(Node* node)
{
	Node* x = node->right;
	node->right = x->left;
	if (x->left != nullptr)
		x->left->parent = node;
	x->left = node;
	node->parent = x;

	return x;
}

Node* rotateRight(Node* node)
{
	Node* x = node->left;
	node->left = x->right;
	if (x->right != nullptr)
		x->right->parent = node;
	x->right = node;
	node->parent = x;

	return x;
}

Node* createNode(int key, bool color)
{
	Node* newNode = new Node();
	newNode->key = key;
	newNode->left = nullptr;
	newNode->right = nullptr;
	newNode->parent = nullptr;
	newNode->color = color;
	return newNode;
}

struct RedBlackTree
{
	Node* Root;
	bool LL = false;
	bool LR = false;
	bool RR = false;
	bool RL = false;

	RedBlackTree()
	{
		Root = nullptr;
	}

	Node* insertHelp(Node* root, int key)
	{
		bool conflict = false;

		if (root == nullptr)
			return createNode(key, 1);
		else if (key < root->key)
		{
			root->left = insertHelp(root->left, key);
			root->left->parent = root;
			if (root != Root)
				if (root->left->color == root->color == 1)
					conflict = true;
		}
		else
		{
			root->right = insertHelp(root->right, key);
			root->right->parent = root;
			if (root != Root)
				if (root->right->color == root->color == 1)
					conflict = true;
		}

		if (LL)
		{
			root = rotateRight(root);
			root->color = 0;
			root->right->color = 1;
			LL = false;
		}
		if (LR)
		{
			root->left = rotateLeft(root->left);
			root->left->parent = root;

			root = rotateRight(root);
			root->color = 0;
			root->right->color = 1;
			LR = false;
		}
		if (RR)
		{
			root = rotateLeft(root);
			root->color = 0;
			root->left->color = 1;
			RR = false;
		}
		if (RL)
		{
			root->right = rotateRight(root->right);
			root->right->parent = root;

			root = rotateLeft(root);
			root->color = 0;
			root->left->color = 1;
			RL = false;
		}

		if (conflict)
		{
			if (root->parent->right == root)
			{
				if (root->parent->left == nullptr || root->parent->left->color == 0)
				{
					if (root->left != nullptr && root->left->color == 1)
						RL = true;
					if (root->right != nullptr && root->right->color == 1)
						RR = true;
				}
				else
				{
					root->color = root->parent->left->color = 0;
					if (root->parent != Root)
						root->parent->color = 1;
				}
			}
			else
			{
				if (root->parent->right == nullptr || root->parent->right->color == 0)
				{
					if (root->left != nullptr && root->left->color == 1)
						LL = true;
					if (root->right != nullptr && root->right->color == 1)
						LR = true;
				}
				else
				{
					root->color = root->parent->right->color = 0;
					if (root->parent != Root)
						root->parent->color = 1;
				}
			}
			conflict = false;
		}

		return root;
	}

	void insert(int key)
	{
		if (Root == nullptr)
			Root = createNode(key, 0);
		else
		{
			Root = insertHelp(Root, key);
			if (Root->color == 1)
				Root->color = 0;
		}
	}
};

string getColor(Node* node)
{
	if (node->color == 1)
		return "RED";
	return "BLACK";
}

void print2DUtil(Node* root, int space)
{
	if (root == nullptr)
		return;
	space += COUNT;

	print2DUtil(root->right, space);
	cout << endl;

	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << root->key << " (" << getColor(root) << ") "
		<< "\n";

	print2DUtil(root->left, space);
}

void print2D(Node* root)
{
	print2DUtil(root, 0);
}

int main()
{
	//  {5, 1, 4, 3, 2, 8, 9, 7, 16, 11, 12, 15}
	RedBlackTree RBTree;
	RBTree.insert(5);
	RBTree.insert(1);
	RBTree.insert(4);
	RBTree.insert(3);
	RBTree.insert(2);
	RBTree.insert(8);
	RBTree.insert(9);
	RBTree.insert(7);
	RBTree.insert(16);
	RBTree.insert(11);
	RBTree.insert(12);
	RBTree.insert(15);
	print2D(RBTree.Root);
}