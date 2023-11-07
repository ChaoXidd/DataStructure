#pragma once
#include<iostream>
using namespace std;

template<class K, class V>
struct AVLTreeNode {
	K key;
	V value;
	int height;
	//int bf;
	AVLTreeNode<K, V>* left;
	AVLTreeNode<K, V>* right;
	AVLTreeNode(K k, V v):key(k), value(v), height(1), left(NULL), right(NULL)
	{

	}
};


template<class K, class V>
class AVLTree
{
public:
	int getHeight(AVLTreeNode<K, V>* r)
	{
		if (r == NULL) return 0;
		return r->height;
	}

	int max(int a, int b)
	{
		return (a > b) ? a : b;
	}

	bool Insert(K key_, V value_); //插入

	void Remove(K key_);      //删除
	
	void preOrder();

	void inOrder();

private:

	AVLTreeNode<K, V>* root = NULL;


	int getBF(AVLTreeNode<K, V>* root)
	{
		return getHeight(root->left) - getHeight(root->right);
	}

	AVLTreeNode<K, V>* RotateL(AVLTreeNode<K, V>* root);      //左旋

	AVLTreeNode<K, V>* RotateR(AVLTreeNode<K, V>* root);     //右旋

	AVLTreeNode<K, V>* Insert(AVLTreeNode<K, V>* node, K key_, V value_);  //插入

	AVLTreeNode<K, V>* Remove(AVLTreeNode<K, V>* node, K key_);     //删除

	void preOrder(AVLTreeNode<K, V>* root);

	void inOrder(AVLTreeNode<K, V>* root);







	//AVLTreeNode<K, V>* RotaterLR(AVLTreeNode<K, V>* root);    //先左后右旋
	//AVLTreeNode<K, V>* RotaterRL(AVLTreeNode<K, V>* root);    //先右后左旋
	

};

