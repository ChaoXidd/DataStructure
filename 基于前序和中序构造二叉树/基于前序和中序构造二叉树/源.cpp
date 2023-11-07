#include<iostream>
using namespace std;

struct BinTreeNode {
	char data;
	BinTreeNode* leftChild;
	BinTreeNode* rightChild;
	BinTreeNode(char c)
	{
		data = c;
		leftChild = NULL;
		rightChild = NULL;
	}
};


void preOrder(BinTreeNode* r)
{
	if (r != NULL)
	{
		cout << r->data;
		preOrder(r->leftChild);
		preOrder(r->rightChild);
	}
}


void inOrder(BinTreeNode* r)
{
	if (r != NULL)
	{
		inOrder(r->leftChild);
		cout << r->data;
		inOrder(r->rightChild);
	}
}


BinTreeNode* createTree(char* VLR, char* LVR, int n)
{
	if (n == 0) return NULL;
	int k = 0;
	while(VLR[0] != LVR[k]) k++;
	BinTreeNode* t = new BinTreeNode(VLR[0]);
	cout << t->data << endl;
	cout << "left: ";
	for (int i = 0; i < k; i++)
	{
		cout << LVR[i];
	}
	cout << endl;
	cout << "right: ";
	for (int j = k + 1, m = 0; m < n - k -1; j++,m++)
	{
		cout << LVR[j];
	}
	cout << endl;
	t->leftChild = createTree(VLR + 1, LVR, k);
	t->rightChild = createTree(VLR + k + 1, LVR + k + 1, n - k - 1);



	return t;
}



int main()
{
	//BinTreeNode* a = new BinTreeNode('A');
	//BinTreeNode* b = new BinTreeNode('B');
	//BinTreeNode* c = new BinTreeNode('C');
	//BinTreeNode* d = new BinTreeNode('D');
	//BinTreeNode* e = new BinTreeNode('E');
	//BinTreeNode* f = new BinTreeNode('F');
	//BinTreeNode* g = new BinTreeNode('G');
	//BinTreeNode* h = new BinTreeNode('H');
	//BinTreeNode* k = new BinTreeNode('K');

	//a->leftChild = b;
	//a->rightChild = e;
	//b->leftChild = h;
	//b->rightChild = f;
	//f->leftChild = d;
	//e->rightChild = c;
	//c->leftChild = k;
	//c->rightChild = g;

	//preOrder(a);
	//cout << endl;
	//inOrder(a);


	char VLR[9] = {'A', 'B', 'H', 'F', 'D', 'E', 'C', 'K', 'G' };
	char LVR[9] = {'H',' B', 'D', 'F', 'A', 'E', 'K', 'C', 'G'};
	BinTreeNode* r = createTree(VLR, LVR, 9);
	//preOrder(r);



	return 0;
}