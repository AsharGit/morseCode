#include "Node.h"

int main()
{
	Node root;
	Node* rootPtr = &root;
	ifstream inFile;

	// Open text file.
	inFile.open("morse.txt");

	// Check to see if file opened successfully.
	if (inFile.fail())
	{
		cerr << "Error opening file." << endl;
		exit(1);
	}

	buildTree(root, inFile);
	encode(rootPtr,"puppy");
	decode(rootPtr, ".__. .._ .__. .__. _.__");

	// Close text file.
	inFile.close();
		
	return 0;
}


