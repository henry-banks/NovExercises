#pragma once
//Linked Tree
struct Node
{
	int data;
	Node *left = nullptr, *right = nullptr;
	Node(int v) : data(v), left(nullptr), right(nullptr) {};
};

class Tree
{
private:
	Node *root;

	int _childCount(const Node*n) const;

public:
	Tree() : root(nullptr) {};
	~Tree();

	//They're all bools because they return false if it fails
	bool isEmpty();
	bool isIn(int val);
	Node* find(int val);
	bool insert(int val);
	bool remove(int val);
};

