#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int checkArraySort(int A[], int array_max, int begin, int ending)
{
        int increase = 0; //counter for ascending order
        int decrease = 0; //counter for descending order

        if (ending > array_max) //check if the last element is outside the array range
                return -20;
        else if (ending < begin) //check if last element is before first element
                return -10;
        for (int k=begin; k < ending; k++)
        {
                if (A[k+1] > A[k]) //check for ascending array
                        increase++;
                else if (A[k+1] < A[k]) //check for descending array
                        decrease++;
        }

        if (increase == (ending-begin)) //if portion is sorted in ascending order
                return 1;
        else if (decrease == (ending-begin)) //if portion is sorted in descending order
                return -1;
        else //if portion is not sorted
                return 0;
}

int binarySearch (int A[], int begin, int ending, int k)
{
        if (begin <=  ending)
        {
                int temp_mid = (begin+ending)/2; //compute midterm
                if (A[temp_mid] == k)
                        return temp_mid; //index at which k was found
                else if (A[temp_mid] > k)
                        return binarySearch(A,begin,(temp_mid-1),k); //search lower half of array
                else if (A[temp_mid] < k)
                        return binarySearch(A,(temp_mid+1),ending,k); //search upper half of array
        }

        return -1; // did not find k in the array
}

int main()
{
        int key;
//      ofstream myfile_in; //file to be created
//      myfile_in.open ("in.txt");
        ofstream myfile_out; //file to be written on with our result
        myfile_out.open ("sort.txt");

        string line; //define variable line string to store lines from in.txt
        int begin, ending; //positions as to where to begin writing onto our out.txt file and where to stop when reading in.txt
        const int array_max = 20; //define max array size as a constant
        int arr[array_max]; //define array of size array_max

        //writes onto in.txt, numbers 1-20 on separate lines
/*      for (int i = 1; i <= array_max; i++)
                myfile_in << i << endl;
*/
        ifstream myfile_in1; //define file to be read
        myfile_in1.open ("in.txt");

        cout << "Enter beginning position to output: "; //ask user where to start reading
        cin >> begin;

        cout << "Enter ending position to output: "; //ask user where to stop reading
        cin >> ending;

        for (int i = 0; i < array_max; i++)
        {
                getline (myfile_in1, line); //read a line from the input file
                stringstream(line) >> arr[i]; //convert the line into a number and assign it to an array element
        }

        for (int j = begin; j <= ending; j++)
        {
                myfile_out << arr[j] << " "; //write in file the elements desired from the input file with a space in between
        }

        int bla = checkArraySort(arr,array_max,begin,ending); //call checkArraySort function to check if array is sorted

        //if array is not sorted, do not continue to binary search (only works for sorted arrays)
        if(bla == 0)
        {
                cout << "The portion of array is not sorted!" << endl;
                return 15;
        }

        cout << "Enter a key (integer) to search for in array: ";
        cin >> key;

        //call our binary search function and store the return value in an int
        int search = binarySearch(arr,begin,ending,key);

        //print out whether or not the key was found and, if found, at what index it was found
        if (search == -1)
                cout << "The key " << key << " was not found in the array!" << endl;
        else
                cout << "Found key " << key << " at index " << search << "!" << endl;

        //close all files
//      myfile_in.close();
        myfile_out.close();
        myfile_in1.close();
        return 2;
}
