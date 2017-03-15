#include <iostream>
using namespace std;
int main()
{
	int i;
	int max = 0;
	int array[max];
	int key = 0;
	int x = 1;
	// these are the declarations of the variables used in the code

	cout << "Enter the size of the array: " << endl;
	cin >> max;// this is where the computer takes the users input


	if(max <= 0)
	{
        	cout << "ERROR: you entered an incorrect array value for the array size!" << endl;
          		return 1;
			}
	else{
		cout << "Enter the numbers in the array, seperated by a space, and press enter: " << endl;
		for (i=0; i < max; i++)
		{
		cin >> array[i];// puts the numbers in the array
			}
		cout << "Enter a number to search for in the array: " << endl;
		cin >> key;
		for(i=0; i < max; i++){
			if(array[i] == key)
			{
				if (x == 1)
					{
					cout << "Found value " << key << " at index " << i << " which took " << i+1 << " checks" << endl;
					cout << "we ran into the best case scenario!" << endl;
						}
				if (x == max)
					{
					cout << "Found value " << key << " at index " << i << " which took " << i+1 << " checks" << endl;
					cout << "we ran into the worst case scenario!" << endl;
						}
				return 0;
				}
			else if (i== max)
			{
				cout << "we ran into the worst case scenario" << endl;
				cout << "The value " << key << " was not found in the array!" << endl;
				return 1;
				}
			else
			{
				x++;
				continue;
				}
}
}
}
