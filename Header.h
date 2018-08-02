#pragma once
#include "stdafx.h"
#include<iostream>

using namespace std;

template <class T>
class node {
public:
	T data;
	node<T> *left, *right, *parent;
	node() { data = 0; parent = NULL; right = NULL; left = NULL; }
	~node() {
		if (left != NULL) delete left;
		if (right != NULL) delete right;
		left = right = parent = NULL;
		cout << "delete :" << data << endl;
	}
};

template <class T>
class BST {
	node<T> *root, *nil;

public:
	BST();
	void BST_Insert(T a);
	void Recurse_insert(node<T> *root, T item);
	node<T>* get_root() { return root; }
	node<T>* min(node<T> *p);
	node<T>* max(node<T> *p);
	bool search(const T& item) const;
	int depth(node<T> *lr);
	void Print(node<T> *root, int k = 0);
	void printLevel(node<T> *root);

};
