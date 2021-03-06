// Class_BST.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Header.h"
#include<iostream>
#include <queue>
using namespace std;

template <class T>
BST<T>::BST() {

	nil = new node<T>;
	nil->data = 0;
	nil->left = NULL;
	nil->right = NULL;
	nil->parent = NULL;
	root = nil;
}

template <class T>
void BST<T>::BST_Insert(T a) {

	if (root == nil) {
		node<T> *temp = new node<T>;
		temp->data = a;
		temp->left = nil;
		temp->right = nil;
		temp->parent = nil;
		root = temp;
	}
	else {
		Recurse_insert(root, a);
	}
}

template <class T>
void BST<T>::Recurse_insert(node<T> *root, T item) {

	if (root->data > item) {

		if (root->left != nil) {
			Recurse_insert(root->left, item);
		}
		else {
			node<T> *temp = new node<T>;
			temp->data = item;
			temp->left = nil;
			temp->right = nil;
			temp->parent = root;
			root->left = temp;
		}

	}
	else {

		if (root->right != nil) {
			Recurse_insert(root->right, item);
		}
		else {
			node<T> *temp = new node<T>;
			temp->data = item;
			temp->left = nil;
			temp->right = nil;
			temp->parent = root;
			root->right = temp;
		}
	}

}


template <class T>
node<T>* BST<T>::min(node<T> *p) {
	if (p->left != nil) {
		return min(p->left);
	}
	else { return p; }
}


template <class T>
node<T>* BST<T>::max(node<T> *p) {
	if (p->right != nil)
		return max(p->right);
	else
		return p;
}

template <class T>
bool BST<T>::search(const T& item) const
{
	node<T>* loc = root;
	bool found = false;
	while (!found && loc != 0)
	{
		if (item < loc->data)
			loc = loc->left;
		else if (loc->data < item)
			loc = loc->right;
		else
			found = true;
	}
	return found;
}

template <class T>
int BST<T>::depth(node<T> *lr) {
	if (lr == nil)  return 0;
	return (1 + depth(lr->left))>(1 + depth(lr->right)) ?
		(1 + depth(lr->left)) : (1 + depth(lr->right));
}

template <class T>
void  BST<T>::Print(node<T> *root, int k) {
	if (root != NULL)
	{
		Print(root->right, k + 3);
		for (int i = 0; i < k; i++) { cout << "  "; }
		cout << root->data << endl;
		Print(root->left, k + 3);
	}
}

template <class T>
void BST<T>::printLevel(node<T> *root) {
	if (!root) return;
	queue< node<T>* > q;
	int CurrLevel = 1;
	int NextLevel = 0;
	q.push(root);
	while (!q.empty()) {
		node<T> *currNode = q.front();
		q.pop();
		CurrLevel--;
		if (currNode) {
			cout << currNode->data << "  ";
			q.push(currNode->right);
			q.push(currNode->left);
			NextLevel += 2;
		}
		if (CurrLevel == 0) {
			cout << endl;
			CurrLevel = NextLevel;
			NextLevel = 0;
		}
	}
}

int main() {
	BST<int> bs;

	bs.BST_Insert(5);
	bs.BST_Insert(3);
	bs.BST_Insert(8);
	bs.BST_Insert(1);
	bs.BST_Insert(7);
	bs.BST_Insert(13);
	bs.BST_Insert(6);
	bs.BST_Insert(4);
	bs.BST_Insert(11);
	bs.BST_Insert(2);
	bs.BST_Insert(10);
	cout << "binary tree1: \n";
	bs.Print(bs.get_root());
	cout << "\n\n\nbinary tree deep: " << bs.depth(bs.get_root()) << endl;
	cout << "\nsearch 22: find=1 not found=0" << endl;
	cout << bs.search(22) << endl;
	cout << "search 6: find=1 not found=0" << endl;
	cout << bs.search(1.8) << endl;
	system("pause");

	return 0;


}