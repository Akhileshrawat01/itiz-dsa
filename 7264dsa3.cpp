
#include <iostream>
using namespace std;

class BST
{
    int data;
    BST *left, *right;

public:

    BST();

    BST(int);
    BST *Insert(BST *, int);

    BST *search(BST *root, int key);
    BST *cloneBinaryTree(BST *root);
    BST *deleteNode(BST *root, int key);
    BST *minValueNode(BST *node);

    // Inorder traversal.
    void Inorder(BST *);

    void printPostorder(BST *);

    void printPreorder(BST *);

    int maxDepth(BST *node);

    void deleteTree(BST *node);
    
    int identicalTrees(BST* a, BST* b);
};

void BST::printPreorder(BST *node)
{
    if (node == NULL)
        return;

    /* first print data of node */
    cout << node->data << " ";

    /* then recur on left subtree */
    printPreorder(node->left);

    /* now recur on right subtree */
    printPreorder(node->right);
}

void BST::printPostorder(BST *node)
{

    if (node == NULL)
        return;

    // first recur on left subtree
    printPostorder(node->left);

    // then recur on right subtree
    printPostorder(node->right);

    // now deal with the node
    cout << node->data << " ";
}

BST *BST::minValueNode(BST *node)
{
    BST *current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

BST *BST::deleteNode(BST *root, int key)
{
    // base case
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else
    {
        // node has no child
        if (root->left == NULL and root->right == NULL)
            return NULL;

        // node with only one child or no child
        else if (root->left == NULL)
        {
            BST *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            BST *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        BST *temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void BST::deleteTree(BST *node)
{
    if (node == NULL)
        return;

    /* first delete both subtrees */
    deleteTree(node->left);
    deleteTree(node->right);

    /* then delete the node */
    cout << "\n Deleting node: " << node->data;
    delete node;
}

BST *BST::cloneBinaryTree(BST *root)
{
    // base case
    if (root == nullptr)
    {
        return nullptr;
    }

    // create a new node with the same data as the root node
    BST *root_copy = new BST(root->data);

    // clone the left and right subtree
    root_copy->left = cloneBinaryTree(root->left);
    root_copy->right = cloneBinaryTree(root->right);

    // return cloned root node
    return root_copy;
}

BST *BST::search(BST *root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
        return root;

    // Key is greater than root's key
    if (root->data < key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

BST ::BST()
    : data(0), left(NULL), right(NULL)
{
}

// Parameterized Constructor definition.
BST ::BST(int value)
{
    data = value;
    left = right = NULL;
}

// Insert function definition.
BST *BST ::Insert(BST *root, int value)
{
    if (!root)
    {
        // Insert the first node, if root is NULL.
        return new BST(value);
    }

    // Insert data.
    if (value > root->data)
    {
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.

        // Process right nodes.
        root->right = Insert(root->right, value);
    }
    else
    {
        // Insert left node data, if the 'value'
        // to be inserted is greater than 'root' node data.

        // Process left nodes.
        root->left = Insert(root->left, value);
    }

    // Return 'root' node, after insertion.
    return root;
}

// Inorder traversal function.
// This gives data in sorted order.
void BST ::Inorder(BST *root)
{

    if (!root)
    {
        return;
    }
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

int BST::maxDepth(BST *node)
{
    if (node == NULL)
        return -1;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

int BST:: identicalTrees(BST *a, BST *b)
{
	/*1. both empty */
	if (a == NULL && b == NULL)
		return 1;

	/* 2. both non-empty -> compare them */
	if (a != NULL && b != NULL)
	{
		return
		(
			a->data == b->data &&
			identicalTrees(a->left, b->left) &&
			identicalTrees(a->right, b->right)
		);
	}
	
	/* 3. one empty, one not -> false */
	return 0;
}

// Driver code
int main()
{
    int n, r, x;
    BST b, *root = NULL;
    BST *root1=NULL;
    cout << "how many nodes to enter?" << endl;
    cin >> n;
    cout << "enter root node: ";
    cin >> r;
    root = b.Insert(root, r);
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        b.Insert(root, x);
    }

    int key;
    cout << "enter element to be search" << endl;
    cin >> key;
    BST *i = b.search(root, key);
    if (i == NULL)
        cout << "element not found in tree" << endl;
    else
        cout << "element found in tree" << endl;

    cout << "Inorder traversal function" << endl;
    b.Inorder(root);
    cout << endl;
    cout << "Postorder traversal" << endl;
    b.printPostorder(root);
    cout << endl;
    cout << "Preorder traversal function" << endl;
    b.printPreorder(root);
    cout << endl;

    cout << "height of tree"
         << " ";
    int h = b.maxDepth(root);
    if (h == -1)
        cout << "NO TREE FOUND" << endl;
    else
        cout << h << endl;

    cout << "enter value to be deleted" << endl;
    cin >> key;
    root = b.deleteNode(root, key);
    cout << "inorder of modified tree is" << endl;
    b.Inorder(root);
    cout << endl;

    BST *clone = b.cloneBinaryTree(root);
    cout << "in order traversal of clone" << endl;
    b.Inorder(clone);
    cout << endl;

    cout << "delete original Tree" << endl;
    b.deleteTree(root);
    cout << endl;
    cout << "Deleted the entire tree!" << endl;
    root = NULL;

    cout<<"to check whether the trees are equal or not?"<<endl;
    cout<<"enter first tree" << endl;
    cout << "how many nodes to enter?" << endl;
    cin >> n;
    cout << "enter root node: ";
    cin >> r;
    root = b.Insert(root, r);
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        b.Insert(root, x);
    }
    cout<<"enter second tree"<< endl;
    cout << "how many nodes to enter?" << endl;
    cin >> n;
    cout << "enter root node: ";
    cin >> r;
    root1 = b.Insert(root1, r);
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        b.Insert(root1, x);
    }

    if(b.identicalTrees(root, root1))
		cout << "Both tree are identical.";
	else
		cout << "Trees are not identical.";



    return 0;
}

// This code is contributed by pkthapa
