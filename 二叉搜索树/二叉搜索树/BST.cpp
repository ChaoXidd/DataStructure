#include"BST.h"


template<class K, class V>
BSTreeNode<K, V>* BSTree<K, V>::Find(BSTreeNode<K, V>* root, const K& sk)
{
	if (root == NULL) return NULL;
	if (sk > root->key_) return Find(root->rchild, sk);
	else if (sk < root->key_) return Find(root->lchild, sk);
	else return root;
}

template<class K, class V>
BSTreeNode<K, V>* BSTree<K, V>::Find(const K& sk)
{
	return Find(root_, sk);
}


template<class K, class V>
bool BSTree<K, V>::Insert(BSTreeNode<K, V>*& root, const K& ik, const V& value)
{
	if (root == NULL)
	{
		root = new BSTreeNode<K, V>(ik, value);
		return true;
	}
	if (ik > root->key_)        //目标 > 当前，向右子树移动
	{
		return Insert(root->rchild, ik, value);
	}
	else if (ik < root->key_)   //目标 < 当前，向左子树移动
	{
		return Insert(root->lchild, ik, value);
	}
	else
	{
		return false;   //已存在该结点
	}
	
}


template<class K, class V>
bool BSTree<K, V>::Insert(const K& ik, const V& value)
{
	return Insert(root_, ik, value);
}



template<class K, class V>
bool BSTree<K, V>::Remove(BSTreeNode<K, V>*& root, const K& rk)
{
	if (root == NULL) return false;
	if (rk > root->key_)
	{
		return Remove(root->rchild, rk);
	}
	else if (rk < root->key_)
	{
		return Remove(root->lchild, rk);
	}
	else
	{
		BSTreeNode<K, V>* del = root;
		if (root->lchild == NULL)    //只有右子树和左右均为空
		{
			root = root->rchild;
			return true;
		}

		else if (root->rchild == NULL)   //只有左子树
		{
			root = root->lchild;
			return true;
		}

		else      //两子树都不为空
		{
			BSTreeNode<K, V>* successor = root->rchild;
			while (successor->lchild != NULL)
			{
				successor = successor->lchild;
			}
			
	     /* BSTreeNode<K, V> temp = root;
			root = successor;
			successor = temp; */
			K tkey = root->key_;
			V tvalue = root->value_;
			root->key_ = successor->key_;
			root->value_ = successor->value_;
			successor->key_ = tkey;
			successor->value_ = tvalue;
			return Remove(root->rchild, rk);

		}
		delete del;
		del = NULL;
	}
	return false;
}


template<class K, class V>
bool BSTree<K, V>::Remove(const K& rk)
{
	return Remove(root_, rk);
}


template<class K, class V>
void BSTree<K, V>::Output()
{
	Output(root_);
	cout << endl;
}


template<class K, class V>
void BSTree<K, V>::Output(BSTreeNode<K, V>* root)
{
	if (root == NULL)
	{
		return;
	}

	Output(root->lchild);
	cout << root->key_ << " ";
	Output(root->rchild);
}


void Test()
{
	BSTree<int, int> s;
	s.Insert(4, 1);
	s.Insert(2, 1);
	s.Insert(5, 1);
	s.Insert(3, 1);
	s.Insert(1, 1);
	s.Insert(6, 1);


	s.Output();
	s.Remove(2);
	s.Output();
}
int max(BSTreeNode<int, int>* root)
{
	while (root->rchild != NULL)
	{
		root = root->rchild;
	}
	return root->key_;
}

int min(BSTreeNode<int, int>* root)
{
	while (root->lchild != NULL)
	{
		root = root->lchild;
	}
	return root->key_;
}


bool detect(BSTreeNode<int, int>* root, int max, int min)
{
	if (root == NULL)
	{
		return true;
	}

	if (root->key_ < min || root->key_ > max)
	{
		return false;
	}
	return detect(root->lchild, max, min) && detect(root->rchild, max, min);
}


void Test2()
{
	BSTreeNode<int, int>* root_ = new BSTreeNode<int, int>(2, 10);
	BSTreeNode<int, int>* left_ = new BSTreeNode<int, int>(1, 10);
	BSTreeNode<int, int>* right_ = new BSTreeNode<int, int>(3, 10);

	root_->lchild = left_;
	root_->rchild = right_;
	int max1 = max(root_);
	int min1 = min(root_);

	if (detect(root_, max1, min1))
	{
		cout << "yes";
	}

	root_->lchild = right_;
	root_->rchild = left_;

	int max2 = max(root_);
	int min2 = min(root_);

	if (detect(root_, max2, min2))
	{
		cout << "yes";
	}



}



int main()
{
	//Test();
	Test2();
	return 0;
}