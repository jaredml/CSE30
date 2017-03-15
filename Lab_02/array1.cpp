#include <iostream>
using namespace std;
int main()
{
	int i;
	int max = 0;
	int array[max];
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
		for (i=0; i < max; i++){
		cin >> array[i];// puts the numbers in the array
		}
		for(i=0;i<(max-1); i++){
			if(array[i]<=array[i+1])// makes sure the array is increasing
				continue;

			else// if the array is decreasing it prints out the statement below
			cout << "This is NOT an increasing array!" << endl;
				return 1;
				}
			}
		cout << "This IS an increasing array!" << endl;// if the array is increasing it prints this statement out
			return 1;
}
