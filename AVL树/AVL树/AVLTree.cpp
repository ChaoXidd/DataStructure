#include"AVLTree.h"


template<class K, class V>
AVLTreeNode<K, V>* AVLTree<K, V>::RotateL(AVLTreeNode<K, V>* root)
{
	//1.根节点root右子树变为新根结点newroot
	//2.若newroot左子树存在，则newroot的左子树变为root的右子树
	//3.root变为newroot的左子树

	AVLTreeNode<K, V>* newroot = root->right;
	root->right = newroot->left;
	newroot->left = root;

	root->height = 1 + max(getHeight(root->left), getHeight(root->right));
	newroot->height = 1 + max(getHeight(newroot->left), getHeight(newroot->right));

	return newroot;
}



template<class K, class V>
AVLTreeNode<K, V>* AVLTree<K, V>::RotateR(AVLTreeNode<K, V>* root)
{
	//1.根节点root左子树变为新根结点newroot
	//2.若newroot右子树存在，则newroot的右子树变为root的左子树
	//3.root变为newroot的右子树
	AVLTreeNode<K, V>* newroot = root->left;
	root->left = newroot->right;
	newroot->right = root;

	root->height = 1 + max(getHeight(root->left), getHeight(root->right));
	newroot->height = 1 + max(getHeight(newroot->left), getHeight(newroot->right));

	return newroot;
}



template<class K, class V>
AVLTreeNode<K, V>* AVLTree<K, V>::Insert(AVLTreeNode<K, V>* node, K key_, V value_)
{
	if (node == NULL) return  new AVLTreeNode<K, V>(key_, value_);
	if (key_ > node->key)
	{
		node->right = Insert(node->right, key_, value_);
	}
	else if (key_ < node->key)
	{
		node->left = Insert(node->left, key_, value_);
	}
	else    //已有相同的key
	{
		return node;   
	}

	node->height = 1 + max(getHeight(node->left), getHeight(node->right));   //更新树高
	int bf = getBF(node);


	//LL
	if (bf > 1 && getBF(node->left) > 0)
	{
		return RotateR(node);
	 }

	//LR
	if (bf > 1 && getBF(node->left) < 0)
	{
		node->left = RotateL(node->left);
		return RotateR(node);
	}

	//RR
	if (bf < -1 && getBF(node->right) < 0)
	{
		return RotateL(node);
	}

	//RL
	if (bf < -1 && getBF(node->right) > 0)
	{
		node->right = RotateR(node->right);
		return RotateL(node);
	}

	return node;

}


template<class K, class V>
bool AVLTree<K, V>::Insert(K key_, V value_)
{
	root = Insert(root, key_, value_);
	if (root == NULL) return false;
	return true;
}



template<class K, class V>
AVLTreeNode<K, V>* AVLTree<K, V>::Remove(AVLTreeNode<K, V>* node, K key_)
{
	if (node == NULL) return node;
	if (key_ > node->key)
	{
		node->right = Remove(node->right, key_);
	}
	else if (key_ < node->key)
	{
		node->left = Remove(node->left, key_);
	}
	else          //找到删除节点
	{


		if (node->right == NULL || node->left == NULL)   //有一个子节点为空或均为空
		{
			AVLTreeNode<K, V>* temp = node->left ? node->left : node->right;
			if (temp == NULL)   //无子节点
			{
				temp = node;
				node = NULL;
			}
			else                 //一子节点
			{
				*node = *temp;
			}
			delete temp;
		}

		else    //有两个子节点
		{
			AVLTreeNode<K, V>* temp = node->right;
			while (temp->left)
			{
				temp = temp->left;

			}   //后驱节点

			node->key = temp->key;
			node->value = temp->value;
			node->right = Remove(node->right, temp->key);

		}


	}
	if (node == NULL)
	{
		return NULL;    //无子节点
	}

	node->height = 1 + max(getHeight(node->left) , getHeight(node->right));   //更新树高
	int bf = getBF(node);

	//LL
	if (bf > 1 && getBF(node->left) >= 0)   //注意要包括=0的情况
	{
		return RotateR(node);
	}

	//RR
	if (bf < -1 && getBF(node->right) <= 0)     //注意要包括=0的情况
	{
		return RotateL(node);
	}

	//LR
	if (bf > 0 && getBF(node->left) < 0)
	{
		node->left = RotateL(node->left);
		return RotateR(node);
	}

	//RL
	if (bf < 0 && getBF(node->right) > 0)
	{
		node->right = RotateR(node->right);
		return RotateL(node);
	}

	return node;

}



template<class K, class V>
void AVLTree<K, V>::Remove(K key_)
{
	root = Remove(root, key_);
}









template<class K, class V>
void AVLTree<K, V>::preOrder(AVLTreeNode<K, V>* root)
{
	if (root == NULL) return;
	cout << root->key;
	preOrder(root->left);
	preOrder(root->right);
}


template<class K, class V>
void AVLTree<K, V>::inOrder(AVLTreeNode<K, V>* root)
{
	if (root == NULL) return;
	inOrder(root->left);
	cout << root->key;
	inOrder(root->right);
}


template<class K, class V>
void AVLTree<K, V>::preOrder()
{
	preOrder(root);
}



template<class K, class V>
void AVLTree<K, V>::inOrder()
{
	inOrder(root);
}




void test()
{
	AVLTree<int, int> t;
	t.Insert(1, 10);
	//t.Insert(2, 10);
	//t.Insert(3, 10);
	t.Insert(4, 10);
	t.Insert(5, 10);
	t.Insert(6, 10);
	t.Insert(7, 10);


	t.preOrder();
	cout << endl;
	t.inOrder();
	cout << endl;


	t.Remove(1);
	t.preOrder();
	cout << endl;
	t.inOrder();

}




int main()
{
	test();

	return 0;
}