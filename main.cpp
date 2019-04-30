#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void encode(string word, ifstream& fileName);

int main()
{
	ifstream inFile;
	encode("cat", inFile);

	return 0;
}


void encode(string word, ifstream& fileName)
{
	char temp;
	string current;

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
				
				break;
			}
		}
	}

	fileName.close();

}
