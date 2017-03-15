#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include<iomanip>

using namespace std;
//structure with all the main variables
struct Time{
        int hour;
        int minutes;
        int seconds;
};

bool getTimeFromUser(Time *check){

        string my_line, temp;// initiates variables
        getline(cin, my_line);// takes in every line from input

        if(my_line.length() != 8)//if it is the wrong number of variables it is wrong
                return false;

        for (int i = 0; i < my_line.length(); i++)//checks where the : are in the input
        {
                if ( i == 2 || i == 5)
                {
                        if (my_line[i] != ':')
                                return false;
                }

                else
                {
                        if(!(isdigit(my_line[i])))
                                return false;
                }
        }
	//cahnges the string of letters into ints
        (*check).hour = atoi(my_line.substr(0,2).c_str());
        (*check).minutes = atoi(my_line.substr(3,2).c_str());
        (*check).seconds = atoi(my_line.substr(6,2).c_str());

	//checks if the hours, minutes, and seconds are in the right format and not numbers that they cant be
        if((*check).hour < 0 || (*check).hour > 23)
                return false;
        else if((*check).minutes < 0 || (*check).minutes > 59)
                return false;
        else if ((*check).seconds < 0 || (*check).seconds > 59)
                return false;
        else
                return true;

        return true;
}
void print24Hour(Time ticktock){
	//puts in zeros when needed
        cout<<setfill('0')<<setw(2)<<ticktock.hour<<":";
        cout<<setfill('0')<<setw(2)<<ticktock.minutes<<":";
        cout<<setfill('0')<<setw(2)<<ticktock.seconds;
}

int main()
{
        bool valid1, valid2;//stores if the number is valid or not
        Time start_time, end_time;//stores start time and end time
        string my_line1, my_line2;

        cout << "Enter the start time for the lecture (format is HH:MM:SS): ";

        valid1 = getTimeFromUser(&start_time);//calls getTimeFromUser 

        if (!valid1)//if the start time is invalid it prints out  the start time entered is invalid
        {
                cout << "The start time entered is invalid!" << endl;
                return 0;
        }
      else
        {
                cout << "Enter the end time for the lecture (format is HH:MM:SS): ";

                valid2 = getTimeFromUser(&end_time);

                if (!valid2)//if the second number is invalid it prints out the end time is invalid
                {
                        cout << "The end time entered is invalid!" << endl;
                        return 0;
                }

              else//if everything is valid then it prints out start time and end time of lecture
                {
                        cout<<"The lecture starts at ";
                        print24Hour(start_time);//gets the start time and prints it out
                        cout<<" and ends at ";
                        print24Hour(end_time);//gets the end time and prints it out
                        cout<<endl;// ends the line
                }

       }

        return 0;
}

