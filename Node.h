#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Node
{
public:
	char data;
	string code;
	Node* leftSubTree;
	Node* rightSubTree;

	// Constructors
	Node()
	{
		data = ' ';
		code = "";
		leftSubTree = NULL;
		rightSubTree = NULL;
	}
	Node(char data)
	{
		this->data = data;
		code = "";
		leftSubTree = NULL;
		rightSubTree = NULL;
	}
	// Destructor
	~Node()
	{};
};

// Read text file and create a Binary Tree with letters and codes.
void buildTree(Node& root, ifstream& fileName)
{
	char letter;
	string path;
	Node* position = NULL;

	while (!fileName.eof())
	{
		fileName >> letter >> path;
		// Initial starting position.
		if (path.at(0) == '.')
		{
			if (root.leftSubTree == NULL)
			{
				root.leftSubTree = new Node;
			}
			position = root.leftSubTree;
		}
		else if (path.at(0) == '_')
		{
			if (root.rightSubTree == NULL)
			{
				root.rightSubTree = new Node;
			}
			position = root.rightSubTree;
		}

		// Follow the rest of the path.
		for (int i = 1; i < path.size(); i++)
		{
			if (path.at(i) == '.')
			{
				if (position->leftSubTree == NULL)
				{
					position->leftSubTree = new Node;
				}
				position = position->leftSubTree;
			}
			else if (path.at(i) == '_')
			{
				if (position->rightSubTree == NULL)
				{
					position->rightSubTree = new Node;
				}
				position = position->rightSubTree;
			}
		}
		// Fill the data
		position->data = letter;
		position->code = path;
		position = NULL;
	}
}

// Find the code given a letter.
bool find(Node* rootPtr, char key)
{
	Node* position = NULL;
	bool found = false;

	// Check if tree is empty.
	if (rootPtr == NULL)
	{
		cout << "Empty tree." << endl;
		return false;
	}
	// Print and return true if key is found.
	if (rootPtr->data == key)
	{
		cout << rootPtr->code << " ";
		return true;
	}
	else if (rootPtr->data != key)
	{
		// Look at left tree first.
		if (rootPtr->leftSubTree != NULL)
		{
			position = rootPtr->leftSubTree;
			found = find(position, key);
		}
		// Look at right tree if not found.
		if (rootPtr->rightSubTree != NULL && found != true)
		{
			position = rootPtr->rightSubTree;
			found = find(position, key);
		}
	}
	return found;
}

// Find the letter given code.
bool find(Node* rootPtr, string code)
{
	Node* position = NULL;
	bool found = false;

	// Check if tree is empty.
	if (rootPtr == NULL)
	{
		cout << "Empty tree." << endl;
		return false;
	}
	// Print and return true if code is found.
	if (rootPtr->code == code)
	{
		cout << rootPtr->data;
		return true;
	}
	else if (rootPtr->code != code)
	{
		// Look at left tree first.
		if (rootPtr->leftSubTree != NULL)
		{
			position = rootPtr->leftSubTree;
			found = find(position, code);
		}
		// Look at right tree if not found.
		if (rootPtr->rightSubTree != NULL && found != true)
		{
			position = rootPtr->rightSubTree;
			found = find(position, code);
		}
	}
	return found;
}

// Create a morse code message given a word.
void encode(Node* rootPtr, string word)
{
	char key;

	cout << word << " in morse code: ";
	for (int i = 0; i < word.size(); i++)
	{
		key = word.at(i);
		find(rootPtr, key);
	}

	cout << endl;
}

// Create the translation of a morse code message.
void decode(Node* rootPtr, string message)
{
	string code;

	cout << message << " decoded: ";
	for (int i = 0; i < message.size(); i++)
	{
		if (message.at(i) == ' ')
		{
			find(rootPtr, code);
			code.clear();
		}
		else
		{
			code += message.at(i);
		}

	}
	find(rootPtr, code);
	code.clear();
	cout << endl;
}
