#include <iostream>
using namespace std;
int main()
{
	int size =0;
	int arr[size];
	int tempMin=0;
	int iMin = 0;
	int swaps = 0;
// variables i used
	cout << "Enter the size of the array: ";
	cin >> size;
// takes the number for how big the array should be
	if (size <= 0)// checks if the array is biiger than 0
	{
		cout << "ERROR: you entere an incorrect value for the array size!" << endl;
		return 0;
	}

	else
	{
		cout << "Enter the numbers in the array, seperated by a space and press enter: ";

		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];// takes in the numbers inputted and puts them in the array
		}

		for (int i = 0; i < size - 1; i++)// starting at the end of the array
		{
			iMin = i;
			for (int j = i +1; j<size; j++)
			{
				if (arr[j] < arr[iMin])
					iMin = j;
			}

			if(iMin != i)
			{
				tempMin = arr[i];
				arr[i] = arr[iMin];
				arr[iMin]=tempMin;
				swaps++;
			}
		}

		cout << "This is the sorted array in ascending order: ";
		for (int m = 0; m<size; m++)
			cout << arr[m] << " ";
		cout << endl;
		cout << "The algorithm selected the minimum for the traverse of the array." << endl;
		cout << "It took " << swaps << " to sort the array..." << endl;
		return 1;
	}

}

