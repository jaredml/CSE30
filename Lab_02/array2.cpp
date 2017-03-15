#include <iostream>
#include <string>
using namespace std;
int main()
{
	string arr;// first string/ array
	cout << "Enter the string to reverse: ";
	cin >> arr;// where you enter your string/array of letters
	string arr2;
	for(int i = arr.length(); i>=0; i--)
	{
		arr2=arr2+arr[i];// takes the string and reverses
		}
	cout << "The reverse of the string is: ";
	cout << arr2; // prints the reverse
	cout << endl;
	return 0;
}
