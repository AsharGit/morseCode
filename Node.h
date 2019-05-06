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


// Encode using the text file
void encode(string word, ifstream& fileName)
{
	char temp;
	string current;
	ofstream text;
	text.open("code.txt");

	// Open text file.
	fileName.open("morse.txt");

	// Check to see if file opened successfully.
	if (fileName.fail())
	{
		cerr << "Error opening file." << endl;
		exit(1);
	}

	for (int i = 0; i < word.size(); i++)
	{
		while (!fileName.eof())
		{
			fileName >> temp >> current;
			if (word.at(i) == temp)
			{
				cout << current << " ";
				text << current << " ";
				fileName.seekg(0, fileName.beg);
				break;
			}
		}
	}

	fileName.close();
	text.close();
}

void buildTree(Node& root, ifstream& fileName)
{
	char letter;
	string path;
	Node* position = NULL;

	// Open text file.
	fileName.open("morse.txt");

	// Check to see if file opened successfully.
	if (fileName.fail())
	{
		cerr << "Error opening file." << endl;
		exit(1);
	}
	while (!fileName.eof())
	{
		fileName >> letter >> path;
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
		position->data = letter;
		position->code = path;
		position = NULL;
	}
}

void find(Node &root, char key)
{
	Node newRoot = NULL;

	if (&root == NULL)
	{
		cout << "Leaf Node" << endl;
	}
	else if (root.data == key)
	{
		cout << root.code << " ";
	}

	else if (root.data != key)
	{
		newRoot = *root.leftSubTree;
		find(newRoot, key);
	}
}


