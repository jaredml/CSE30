#include <iostream>
using namespace std;

int main()
{
	int size = 0;
	int tempMax = 0;
	int arr[size];
	int Max = 0;
	int iMax = 0;
// variables that i am using
	cout << "Enter the size of the array: " ;
	cin >> size;//where it takes the number for the array

	if (size <= 0)// check for the right array size
	{
		cout << "Error: you entered an incorrect value for the arraysize!" << endl;
		return 0;
	}

	else
	{

		cout << "Enter the numbers in the array, seperated by a space, and press enter: ";

		for (int i = 0; i < size; i++)//inputs in the values for the array
		{
			cin >> arr[i];
		}

		for (int k = 0; k< size-1; k++)// starting at the end of the array
		{
			iMax = k;// set index of temparary max to

			for(int j = k+1; j < size; j++)// starts at the beginning of the array
			{
				if (arr[j] > arr[iMax])// checks if the jth element is larger than the temp max
				{
					iMax = j; // set the temporary max's index to j
				}
			}

			if(iMax != k)
			{
				tempMax = arr[k];// set the temporary max to the new value
				arr[k] = arr[iMax];// placing the new max in the kth index
				arr[iMax] = tempMax;// placing the kth element in the new maximum's position
			}
		}

	cout << "This is the sorted array in descending order: ";
	for (int m = 0; m<size; m++)
		cout << arr[m] << " ";
	cout << endl;
	cout << "The algorithm selected the maximum for the traverse of the array." << endl;
	return 1;

	}
}
