#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int checkArraySort(string * A, int array_max)
{
	int increase = 0; //counter for ascending order
	int decrease = 0; //counter for descending order

	for (int k=0; k < (array_max-1); k++)
	{
		if (A[k+1] > A[k]) //check for ascending array
			increase++;
		else if (A[k+1] < A[k]) //check for descending array
			decrease++;
	}

	if (increase == (array_max-1)) //if array is sorted in ascending order
		return 1;
	else if (decrease == (array_max-1)) //if array is sorted in descending order
		return -1;
	else //if array is not sorted
		return 0;
}

int binarySearch (string * A, int array_max, string keyword)
{
	int begin = 0;
	int end = (array_max-1);
	int temp_mid = 0;

	while (begin <= end)
	{
		temp_mid = (begin + end)/2;

		if (keyword == A[temp_mid])
			return temp_mid;
		else if (keyword < A[temp_mid])
			end = temp_mid - 1;
		else if (keyword > A[temp_mid])
			begin = temp_mid + 1;
		else
			begin = end + 1;
	}

	return -1;
}


int main(void)
{
	int counter = 0; //variable to determine number of lines in file
	string line, word, keyword; //store what we read from file

	ifstream mywords;
	mywords.open ("words_in.txt"); //file from where we read the words

	ofstream mywords_output;
	mywords_output.open ("words_out.txt"); //file where we write the words we read

	while (getline(mywords,line))   //The test condition is TRUE only while there is something to read.
	{
		counter++; //count the number of lines
	}

	// close file that is read so that getline will go back to the top of the file
	mywords.close();
	mywords.open ("words_in.txt");

	//initialize a dynamically allocated array of strings
	string * arr;
	arr = new string[counter];

	//read the file and store the words into an array of strings
	for(int i = 0; i < counter; i++)
	{
		getline(mywords, word);
		arr[i] = word.c_str();
	}

	//write in file the elements desired from the input file
	for (int j = 0; j < counter; j++)
		mywords_output << arr[j] << endl;

	int bla = checkArraySort(arr,counter); //call checkArraySort function to check if array is sorted

	//if array is not sorted, do not continue to binary search (only works for sorted arrays)
	if(bla == 0)
	{
		cout << "The array is not sorted!" << endl;
		return 15;
	}

	else
	{
		cout << "Enter a word to search for in array: ";
		cin >> keyword;

		cout << counter << endl;
		//call our binary search function and store the return value in an int
		int search = binarySearch(arr,counter,keyword);

		//print out whether or not the key was found and, if found, at what index it was found
		if (search == -1)
		{
			cout << "The word " << keyword << " was not found!" << endl;
		}
		else
		{
			cout << "Found word " << keyword << " at index " << search << "!" << endl;
			return 0;
		}
	}

	//free up memory and close all files opened
	delete [] arr;
	mywords.close();
	mywords_output.close();

	return 0;
}
