#pragma once
#include<iostream>

template<class T>
struct BinTreeNode {
	T data;
	BinTreeNode<T>* leftChild, * rightChild;
	BinTreeNode() :leftChild(NULL), rightChild(NULL)
	{

	}
	BinTreeNode(T x, BinTreeNode<T>* l = NULL, BinTreeNode<T>* r = NULL) : data(x), leftChild(l), rightChild(r)
	{

	}
};

template<class T>
class BinaryTree {
public:
	int Size(BinTreeNode<T>* t);
	
private:
	BinTreeNode<T>* root;

};
