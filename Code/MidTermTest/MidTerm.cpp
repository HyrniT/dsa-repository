#include<iostream>

using namespace std;

struct Node
{
	int key;
	Node* next;
};

struct List
{
	Node* head;
};

List* addPos(List* L, int data, int pos)
{
	Node* newNode = new Node();
	newNode->key = data;
	newNode->next = nullptr;

	if (L == nullptr)
	{
		L = new List();
		L->head = newNode;
		return L;
	}

	if (pos <= 0)
	{
		newNode->next = L->head;
		L->head = newNode;
	}
	else
	{
		Node* curr = L->head;
		int count = 1;
		while (curr->next != nullptr)
		{
			if (count == pos) break;
			curr = curr->next;
			count++;
		}

		newNode->next = curr->next;
		curr->next = newNode;
	}

	return L;
}

int getLength(List* L)
{
	int count = 0;
	Node* curr = L->head;

	while (curr != nullptr)
	{
		count++;
		curr = curr->next;
	}

	return count;
}

List* removeFromEnd(List* L, int pos)
{
	if (L == nullptr)
		return nullptr;

	int length = getLength(L);
	pos = length - pos - 1;
	Node* curr = L->head;
	
	if (pos <= 0)
	{
		L->head = L->head->next;
		delete curr;
		curr = nullptr;
	}
	else
	{
		int count = 1;
		while (curr->next != nullptr)
		{
			if (count == pos) break;
			curr = curr->next;
			count++;
		}
		Node* temp = curr->next;
		curr->next = curr->next->next;
		delete temp;
		temp = nullptr;
	}
	return L;
}

List* swapNode(List* L, int pos1, int pos2)
{
	int length = getLength(L);
	pos2 = length - pos2 - 1;
	if (pos1 >= length ||
		pos2 >= length || 
		pos1 < 0 || 
		pos2 < 0 ||
		pos2 == pos1 ||
		length < 2)
		return L;

	Node* prev1 = nullptr;
	Node* curr1 = L->head;
	int count1 = 0;
	while (count1 < pos1)
	{
		prev1 = curr1;
		curr1 = curr1->next;
		count1++;
	}

	Node* prev2 = nullptr;
	Node* curr2 = L->head;
	int count2 = 0;
	while (count2 < pos2)
	{
		prev2 = curr2;
		curr2 = curr2->next;
		count2++;
	}

	if (prev1 != nullptr)
		prev1->next = curr2;
	else
		L->head = curr2;

	if (prev2 != nullptr)
		prev2->next = curr1;
	else
		L->head = curr1;

	Node* temp = curr1->next;
	curr1->next = curr2->next;
	curr2->next = temp;

	return L;
}

void print(List* L)
{
	Node* curr = L->head;
	while (curr != nullptr)
	{
		cout << curr->key << " ";
		curr = curr->next;
	}
	cout << endl;
}

int  main()
{
	List* L = nullptr;
	L = addPos(L, 5, 0);
	L = addPos(L, 4, 0);
	L = addPos(L, 3, 0);
	L = addPos(L, 2, 0);
	L = addPos(L, 1, 0);
	L = addPos(L, 6, 5);
	L = removeFromEnd(L, 0);
	L = swapNode(L, 1, 2);
	print(L);
}