#include "Tree.h"
#include <iostream>

using namespace std;

int Tree::_childCount(const Node *n) const
{
	int out = 0;
	if (n->left) out++;
	if (n->right) out++;

	return out;
}

Tree::~Tree()
{
}

bool Tree::isEmpty()
{
	return root == nullptr;
}

bool Tree::isIn(int val)
{
	Node *current = root;
	while (current != nullptr)
	{
		if (val == current->data)
			return true;
		else if (val < current->data)
			current = current->left;
		else
			current = current->right;
	}

	return false;
}

Node * Tree::find(int val)
{
	Node *current = root;
	while (current != nullptr)
	{
		if (val == current->data)
			return current;
		else if (val < current->data)
			current = current->left;			
		else
			current = current->right;
	}

	return nullptr;
}


bool Tree::insert(int val)
{
	Node *current = root;

	if (isEmpty())
	{
		root = new Node(val);
		return true;
	}
	while (true)	//It will hit one of the two end results eventually

	{

		if (val < current->data)
		{
			if (current->left == nullptr)
			{
				current->left = new Node(val);
				return true;
			}
			current = current->left;
		}
			
		else
		{
			if (current->right == nullptr)
			{
				current->right = new Node(val);
				return true;
			}
			current = current->right;
		}
	}

	if (val < current->data)
		current->left = new Node(val);
	else
		current->right = new Node(val);

	return true;
}

//This one is complicated
bool Tree::remove(int val)
{
	//IF deleting root AND root has no children...
	if (root != nullptr && root->data == val && root->left == nullptr && root->right == nullptr)
	{
		delete root;
		root = nullptr;
		return true;
	}

	Node *r = root;

	while (true)
	{
		if (r == nullptr) return false;

		//2-child deletion
		if (r->data == val)
		{
			Node *ts, *tt;
			ts = r->right;

			if (ts->left == nullptr)
			{
				ts = r;
				tt = r->right;
			}
			else
			{
				while (ts->left->left != nullptr)
					ts = ts->left;
				tt = r->left;
			}

			r->data = tt->data;
			ts->left = tt->right;
			delete tt;

		}

		if (r->left != nullptr && r->left->data == val)
		{
			Node *temp = r->left;

			r->left =
			r->left->left != nullptr ?
				r->left->left :
				r->left->right;
			delete temp;
			return true;
		}
		if (r->right != nullptr && r->right->data == val)
		{
			Node *temp = r->right;

			r->right =
				r->right->right != nullptr ?
				r->right->right :
				r->right->left;
			delete temp;
			return true;
		}

		r = val < r->data ? r->left : r->right;
	}
		

	return false;
}
