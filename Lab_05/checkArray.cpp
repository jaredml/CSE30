#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int checkArraySort(int A[], int array_max, int start, int end)
{
	int increase = 0;
	int decrease = 0;

	if (end > array_max)
		return -20;
	else if(end < start)
		return -10;
	for (int k = start; k < end; k++)
	{
		if (A[k+1] > A[k])
			increase++;
		else if (A[k+1] < A[k])
			decrease++;
	}

	if (increase ==(end-start))
		return 1;
	else if (decrease == (end-start))
		return -1;
	else
		return 0;
}
 
int main()
{
	ofstream myfile_in;// file being created
	myfile_in.open("in.txt");
	ofstream myfile_out; //file being written in
	myfile_out.open("out.txt");

	string line;
	int start, end;

	const int array_max = 20;
	int arr[array_max];

	for(int i =1; i <= array_max; i++)
		myfile_in << i << endl;

	ifstream myfile_in1;
	myfile_in1.open("in.txt");

	cout << "Enter beginning position to output: ";
	cin >> start;

	cout << "Enter ending position to output: ";
	cin >> end;

	for (int i=0; i <array_max; i++)
	{
		getline (myfile_in1, line);
		stringstream(line) >> arr[i];
	}

	for(int j = start; j <= end; j++)
	{
		myfile_out << arr[j] << " ";
	}

	myfile_in.close();
	myfile_out.close();
	myfile_in1.close();
	return 0;

}
