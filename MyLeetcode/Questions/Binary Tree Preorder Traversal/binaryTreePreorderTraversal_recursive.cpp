template <class T>
void preOrder(binaryTreeNode<T> *t)
{// Preorder traversal of *t.
    if (t != NULL)
    {
    	visit(t);
    	preOrder(t->leftChild);
    	preOrder(t->rightChild);
	}
	
}
