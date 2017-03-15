#include <iostream>
using namespace std;
int order;
int size = 0;

void sortArr (int order, int arr[], int size)
{
	int iMin, iMax;
	int tempMin, tempMax;

	if (order == 0)
	{
		for (int i = 0; i < size - 1; i++)
		{
			iMin = i;
			for(int j = i + 1; j< size; j++)
				{
					if (arr[j] < arr[iMin])
					iMin =j;
				}

			if (iMin != i)
			{
				tempMin = arr[i];
				arr[i] = arr[iMin];
				arr[iMin] = tempMin;
			}
		}
	}

	else
		for (int i = 0; i < size-1; i++)
		{
			iMax =i;
			for (int j = i+1; j < size; j++)
			{
				if (arr[j]>arr[iMax])
					iMax = j;
			}

			if (iMax != i)
			{
				tempMax = arr[i];
				arr[i] = arr[iMax];
				arr[iMax] = tempMax;
			}
		}
}

int main()
{

	int arr[size];

	cout << "Enter the size of the array: " ;
	cin >> size;

	if (size <= 0)
	{
		cout << "Error: you entered an incorrect value for the arraysize!" << endl;
		return -1;
	}

	else
	{
		arr[size];
		cout << "Enter the numbers in the array, seperated by a space, and press enter: ";

		for (int i = 0; i < size; i++)
			cin >> arr[i];

		cout << "Sort in ascending (0) or descending (1) order? ";
		cin >> order;

		sortArr(order, arr, size);

		cout << "This is the sorted array in ";
		if (order == 0)
		{
			cout << "ascending order: ";
			for (int i = 0; i < size; i++)
				cout << arr[i] << " ";
			cout << endl;
		}

		else
		{
			cout << "descending order: ";
			for (int i = 0; i <size; i++)
				cout << arr[i] << " ";
			cout << endl;
		}
	}
}
