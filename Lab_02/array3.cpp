#include <iostream>
using namespace std;
int main()
{
	int i,j;
	int neg = 0;
	int dim = 0;
	int array [dim][dim];
	
	cout << "Enter the size of a 2D array: ";
	cin >>dim;
	
	if(dim <= 0)
	{
		cout << "ERROR: you entered an incorrect value for the array size!" << endl;
		return 1;
		}
	
	if (dim >= 10)
	{
		cout << "ERROR: your array is too large! Enter 1 to 10" << endl;
		return 1;
	}

	else{
		for (i = 0; i < dim; i++)
	{
			cout << "Enter the numbers in the array for row " << (i+1) <<  ", seperated by a space, and press enter: " << endl;
	
			for(j = 0;j < dim;j++)
			cin >> array[i][j];
			if(array[i][j]<0)
				neg++;
			else
				continue;
		}
	}	
	if(neg == 0)
		cout << "all values are non-negative!" << endl;
	else
		cout << "There are " << neg << " negative values" << endl;

return 1;
	}








