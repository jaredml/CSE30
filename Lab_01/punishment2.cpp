#include <iostream>
#include <string>
using namespace std;
int main()
{

        int max;
        int i;
	int typo;
        cout << "Enter the number of lines for the punishment: " << endl ;
        cin >> max;
       if(max <=  0)
        {
        cout << " You entered an incorrect value for the number of lines!" << endl;             
	return 1; 	
		}
	cout << "enter the line for which we want to make a typo: " << endl ;
	cin >> typo;
	if(typo <=  0)
        {
        cout << " You entered an incorrect value for the line typo!" << endl;
	}
	for (i = 1; i <=  max; i++)
	return 1;        
		{
        if(i == typo)
        {
		cout << "I will always use object oriented programing.";
		}
	else 
		{
		cout << "I will always use object oriented programming.";
			}
                		}
        if(typo <=  0)
	{
        cout << " You entered an incorrect value for the line typo!" << endl;
       		}
	 return 1;
}
