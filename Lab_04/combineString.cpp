#include <iostream>
using namespace std;

string str; //string entered by user to be concatenated
int num; //number of times the string is to be concatenated

string combineStr (string str, int num)
{
	string resultStr; // variable to store concatenated string
	for (int i=1;i<=num; i++)
	{
		resultStr = resultStr + str; // takes the variables and adds them to the concatenated string
	}
	return resultStr; //returns the string
}

int main()
{
	do
	{

		cout << "Entera string: ";//asks user for input
		cin >> str;

		cout << "Enter a number of times: ";//asks user for input
		cin >> num;

		string resultStr = combineStr(str, num);  // calls the function that concatenates the string num number of times

		if (num==0)
			return 0;
		else
			cout << "The resulting string is: " << resultStr << endl;
	}

while (num!=0);
}
