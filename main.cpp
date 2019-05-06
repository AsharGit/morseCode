#include "Node.h"

int main()
{
	Node root;
	Node* position = NULL;
			
	ifstream inFile;
	buildTree(root, inFile);
	find(root, 'h');
		

	/*encode("cat", inFile);*/


	return 0;
}


