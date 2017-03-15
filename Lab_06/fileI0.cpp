#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	int counter = -1;
	string line, word;

	ifstream mywords;
	mywords.open ("words_in.txt");

	ofstream mywords_output;
	mywords_output.open("words_out.txt");

	do
	{
		counter++;
	}
	while(getline(mywords,line));

	mywords.close();
	mywords.open ("words_in.txt");

	string * arr;
	arr = new string[counter];

	for(int i = 0; i < counter; i++)
	{
		getline(mywords, word);
		arr[i] = word.c_str();
	}

	for(int j = 0; j < counter; j++)
	{
		mywords_output << arr[j] << endl;
	}

	delete [] arr;
	mywords.close();
	mywords_output.close();
	return 0;
}
