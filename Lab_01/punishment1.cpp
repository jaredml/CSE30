#include <iostream>
#include <string>
using namespace std;
int main()
{
	int max;
	int i;
	cout << "Enter the number of lines for the punishment: ";
	cin >> max;
	for (i=0; i < max; i++)
	{
		cout << "I will always use object oriented programming." << endl;

		}
	if(max <=  0)
	cout << " You entered an incorrect value for the number of lines!" << endl;
	return 0;
}
