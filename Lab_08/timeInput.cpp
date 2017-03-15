#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include<iomanip>

using namespace std;

struct Time{
        int hour;
        int minutes;
        int seconds;
};

bool getTimeFromUser(Time *check){

        string (*my_line) = new string;// creates a pointer
        getline(cin, *my_line);

        if((*my_line).length() != 8)//checks if the string length is long enough to be the right format
                return false;

        for (int i = 0; i < (*my_line).length(); i++)
        {
                if ( i == 2 || i == 5)// checks to see if the format is right by cheking if there is a :
                {
                        if ((*my_line)[i] != ':')
                                return false;
                }

                else
                {
                        if(!(isdigit((*my_line)[i])))
                                return false;
                }
        }
	//converts strings into ints and stores them into appropriate places in time structure
        check->hour = atoi((*my_line).substr(0,2).c_str());
        check->minutes = atoi((*my_line).substr(3,2).c_str());
        check->seconds = atoi((*my_line).substr(6,2).c_str());

        if(check->hour < 0 || check->hour > 23)//checks if the hours are right
                return false;
        else if((check->minutes) < 0 || (check->minutes) > 59)//checks if the minutes are right
                return false;
        else if ((check->seconds) < 0 || (check->seconds) > 59)// checks if the seconds are right
                return false;
        else
                return true;

        return true;
}
void print24Hour(Time *ticktock)
{//fills every first space that isn't used with a 0
        cout<<setfill('0')<<setw(2)<<ticktock->hour<<":";
        cout<<setfill('0')<<setw(2)<<ticktock->minutes<<":";
        cout<<setfill('0')<<setw(2)<<ticktock->seconds;
}

int main()
{
        bool *valid = new bool;//stores if the time is valid or not
        Time *start_time = new Time, *end_time = new Time;

        cout << "Enter the start time for the lecture (format is HH:MM:SS): ";
//asks for user input
        (*valid) = getTimeFromUser(start_time);
//calls the function to check the time that the user put in and says if it is valid or not
        if (!(*valid))
        {
                cout << "The start time entered is invalid!" << endl;//prints out  that start time is invalid if it is invalid
                return 0;
        }
      else
        {//only prints out if start time is valid
                cout << "Enter the end time for the lecture (format is HH:MM:SS): ";

                (*valid) = getTimeFromUser(end_time);// calls the function to check the end time entered

                if (!(*valid))//if not valid
                {
                        cout << "The end time entered is invalid!" << endl;// prints out if start time is invalid
                        return 0;
                }

              else// if end time is valid it prints out start time of lecture and end time of lecture
                {
                        cout<<"The lecture starts at ";
                        print24Hour(start_time);
                        cout<<" and ends at ";
                        print24Hour(end_time);
                        cout<<endl;
                }

       }

        return 0;
}
