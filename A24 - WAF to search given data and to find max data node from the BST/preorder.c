#include "tree.h"

/* Function to print the tree in pre order */
int preorder(Tree_t *root)
{
	//print data while pre order Traversing
	if(root)
	{
		printf("%d ", root -> data);
		//move to left sub tree
		preorder(root -> left);
		//move to right sub tree		
		preorder(root -> right);
	}
}