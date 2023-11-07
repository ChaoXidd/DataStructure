#pragma once
#include<iostream>
using namespace std;

template<class K, class V>
struct BSTreeNode
{
	BSTreeNode<K,V>* lchild;
	BSTreeNode<K,V>* rchild;
	K key_;
	V value_;
	BSTreeNode(const K& key, const V& value) :lchild(NULL), rchild(NULL), key_(key), value_(value)
	{

	}
};



template<class K, class V>
class BSTree
{
public:

	BSTree() :root_(NULL)
	{

	}
	~BSTree()
	{

	}

	bool Insert(const K& ik, const V& value);

	bool Remove(const K& rk);

	BSTreeNode<K, V>* Find(const K& sk);

	void Output();

	
private:

	bool Remove(BSTreeNode<K, V>*& root, const K& rk);

	bool Insert(BSTreeNode<K, V>*& root, const K& ik, const V& value);

	BSTreeNode<K, V>* Find(BSTreeNode<K, V>* root, const K& sk);

	BSTreeNode<K, V>* root_;

	void Output(BSTreeNode<K, V>* root);




};






