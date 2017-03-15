#include <iostream>
using namespace std;
int order;
int size = 0;

void sortArray(int order, int arr[], int size)
{

	int saved;// stores the values to be inserted in the array
	int j;// array index

	//sort array in ascending order
	if(order==0)
	{
		for (int i = 1; i < size; i++)
		{
			saved = arr[i];
			j = i;

			while (j > 0 && arr[j-1] > saved)
			{
				arr[j] = arr[j-1];
				j=j-1;
			}

			arr[j]=saved;
		}
	}

	//sort array in ascending order
	else
	{
		for(int i = 1; i < size; i++)
		{
			saved = arr[i];
			j = i;
			while(j > 0 && arr[j-1] < saved)
			{
				arr[j] = arr[j-1];
				j=j-1;
			}

			arr[j] = saved;
		}
	}
}

int main()
{
	int arr[size];//array to be sorted

	cout<< "Enter the size of the array: ";
	cin >> size;

	//check if the user entered a vaild number
	if (size <= 0)
	{
		cout << "Error: you entered an incorrect value for the array size.";
		return -1;
	}

	else
	{
		arr[size];// sets arrayto the length of the size

		cout << "Enter the number in the array, seperated by a space, and press enter: ";

		//input the values that the user enters in the array
		for(int i = 0; i < size; i++)
			cin >> arr[i];

		//decide how the array should be sorted
		cout << "Sort in ascending (0) or descending (1) order: ";
		cin >> order;

		//call our function that sorts the array
		sortArray(order, arr, size);

		//print out the sorted array stating if it is in ascending or descending order
		cout << "This is the sorted array in ";

		if(order == 0)
		{
			cout << "Ascending order: ";
			for (int i =0; i < size; i++)
				cout << arr[i] << " ";
			cout << endl;
		}

		else
		{
			cout << "descending order: ";
			for(int i = 0; i < size; i++)
				cout << arr[i] << " ";
			cout << endl;
		}

	}
}
