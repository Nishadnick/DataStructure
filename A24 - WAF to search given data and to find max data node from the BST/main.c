#include "tree.h"

int main()
{
	/* Intializing the root with NULL */
	Tree_t *root = NULL;
	int result;
	/* Declaring the variables */
	int option=0, data;
	char choice='y';

	
		printf("1. insert BST\n2. in order Traversal\n3. pre order Traversal\n4. post order Traversal\n5. BST Search\n6. Find minimum\n7. Find maximum\n");
		//printf("Enter the option: ");
	while(1)
	{
		scanf("%d", &option);
	
		switch(option)
		{
			case 1:
				/* Reading the data from the user */
				//printf("Enter the data to insert into the BST : ");
				scanf("%d", &data);

				/* Calling the function to insert the element */
				if ((result = insert_into_BST(&root, data)) == DUPLICATE)
				{
					printf("INFO : Duplicate found\n");
				}
				else if (result == FAILURE)
				{
					printf("INFO : Node not created\n");
				}
				
				break;
			case 2:
				/* Function to Printing the data in in-order form */
				inorder(root);
				printf("\n");
				option=8;
				break;

			case 3:
				/* Function to Printing the data in pre-order form */
				preorder(root);
				printf("\n");
				option=8;
				break;
			case 4:
				/* Function to Printing the data in post-order form */
				postorder(root);
				printf("\n");
				option=8;
				break;
			
			case 5:
				printf("Enter the element to be searched: ");
				scanf("%d", &data);
				result = search_BST(root, data);
				if (result == NOELEMENT)
				{
					printf("INFO : Data not found\n");
				}
				else if (result == FAILURE)
				{
				    printf("INFO : Tree is empty\n");
					option=8;
					break;
				}
				else
				{
					printf("INFO : Data found\n");
				}

				break;
			case 6: 
				result = findmin(root);
				if (result == FAILURE)
				{
					printf("INFO : Tree is empty\n");
					option=8;
					break;
				}
				else
				{
				    printf("INFO : Minimum value in the tree is %d\n", result);	
				}
				break;
			case 7: 
				result = findmax(root);
				if (result == FAILURE)
				{
					printf("INFO : Tree is empty\n");
					option=8;
					break;
				}
				else
				{
				    printf("INFO : Maximum value in the tree is %d\n", result);	
				}	
				break;
			case 8:
			    break;
			
			default:
				printf("Invalid Option\n");
				break;
		}
		if(option==8)
		break;
	}
	//	printf("Press y or Y to continue: ");
	//	getchar();
	//	scanf("%c", &choice);
	
		/* If user press y means loop will continue */
	//}while(choice=='y'||choice=='Y');
	return 0;
}