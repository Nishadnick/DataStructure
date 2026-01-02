#include "tree.h"

/* Function to insert the data's in BST */
int insert_into_BST(Tree_t **root, int data)
{
	//create a new tree node
	Tree_t *new = malloc(sizeof(Tree_t));

	//check if memory is alloted
	if (NULL == new)
	{
		return FAILURE;
	}

	//update new tree data and links
	new -> data = data;
	new -> left = NULL;
	new -> right = NULL;

	//if tree is empty
	if ( NULL == (*root))
	{
		(*root) = new; //first node is treated as root
		return SUCCESS;
	}

	//if non empty 

	//take local reference to traverse along the tree nodes and a parent node to keep track of parent node
	Tree_t *temp, *parent;
	temp = (*root);
	int flag;

	//insert in appropriate place
	while(temp)
	{
		//get the parent reference
		parent = temp;
		
		if ((temp -> data) > (new -> data))
		{
			temp = temp -> left;
			flag = 0;
		}
		else if ((temp -> data) < (new -> data))
		{
			temp = temp -> right;
			flag = 1;
		}
		else
		{
			//no duplicates in BST
			return DUPLICATE;
		}		
	}
	
	//update the node at appropriate place
	if(flag)
	{
		parent -> right = new;
	}
	else
	{
		parent -> left = new;
	}
	return SUCCESS;
}