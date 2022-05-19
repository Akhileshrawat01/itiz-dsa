//5. construct a binary tree from inorder and perorder traversal 

#include <bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node* left;
	node* right;
};

/* Prototypes for utility functions */
int search(int arr[], int strt, int end, int value);
node* newNode(int data);

node* buildTree(int in[], int pre[], int inStrt, int inEnd)
{
	static int preIndex = 0;

	if (inStrt > inEnd)
		return NULL;

	node* tNode = newNode(pre[preIndex++]);

	/* If this node has no children then return */
	if (inStrt == inEnd)
		return tNode;

	/* Else find the index of this node in Inorder traversal */
	int inIndex = search(in, inStrt, inEnd, tNode->data);

	/* Using index in Inorder traversal, construct left and
	right subtress */
	tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
	tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

	return tNode;
}


int search(int arr[], int strt, int end, int value)
{
	int i;
	for (i = strt; i <= end; i++)
	{
		if (arr[i] == value)
			return i;
	}
}

node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return (Node);
}

/* This function is here just to test buildTree() */
void printInorder(node* node)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	printInorder(node->left);

	/* then print the data of node */
	cout<<node->data<<" ";

	/* now recur on right child */
	printInorder(node->right);
}

/* Driver code */
int main()
{
	int in[] = { 4, 2, 1, 7, 5, 8, 3, 6 };
	int pre[] = { 1, 2, 4, 3, 5, 7, 8, 6 };
	int len = sizeof(in) / sizeof(in[0]);
	node* root = buildTree(in, pre, 0, len - 1);

	/* Let us test the built tree by
	printing Inorder traversal */
	cout << "Inorder traversal of the constructed tree is \n";
	printInorder(root);
}
