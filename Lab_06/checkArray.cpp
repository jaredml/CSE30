#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int checkArraySort(string * A, int array_max)
{
	int increase = 0;//counter for ascending
	int decrease = 0;// counter for descending

	for (int k = 0; k < array_max-1; k++)
	{
		if (A[k+1] > A[k])
			increase++;
		else if (A[k+1] < A[k])
			decrease++;
	}

	if (increase ==(array_max-1))//checks if array is in ascending order
		return 1;
	else if (decrease == (array_max-1))//checks if array is in descending order
		return -1;
	else// checks if the array is niether
		return 0;
}

int main()
{
	int counter = 0;// determining varible for how many lines it has
	string line, word;//store what we read from file

	ifstream mywords;
	mywords.open ("words_in.txt");// the file we read

	ofstream mywords_output;
	mywords_output.open("words_out.txt");//the file we write on
// the test condition
	do
	{
		counter++;
	}
	while(getline(mywords,line));
// closes file and and starts it from the beginning
	mywords.close();
	mywords.open ("words_in.txt");
//initializes dynamically allocated array of strings
	string * arr;// string points to arr
	arr = new string[counter];
//read the file and store the words in the array
	for(int i = 0; i < counter; i++)
	{
		getline(mywords, word);
		arr[i] = word.c_str();
	}
//write in the file the elements from the desired input
	for(int j = 0; j < counter; j++)
	{
		mywords_output << arr[j];
	}

	int bla = checkArraySort(arr,counter);// call check array sort function

	if(bla==-1)
		cout << "The array is sorted in descending order!";

	else if(bla == 0)
		cout << "The array is not sorted!";

	else if (bla == 1)
		cout << "The array is sorted in ascending order!";

// free up memory and close all files
	delete [] arr;
	mywords.close();
	mywords_output.close();
	return 0;

}
