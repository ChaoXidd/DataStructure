#include"BinaryTree.h"


template<class T>
int BinaryTree<T>::Size(BinTreeNode<T>* t)
{
	if (t == NULL)  return 0;
	else return 1 + Size(t->leftChild) + Size(t->rightChild);
}