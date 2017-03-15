#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
#include "Time.h"

using namespace std;

int main()
{
        bool valid1, valid2;//stores if the number is valid or not
        Time start_time, end_time;//stores start time and end time
        //string my_line1, my_line2;

        cout << "Enter the start time for the lecture (format is HH:MM:SS): ";

        valid1 = start_time.getTimeFromUser();//calls getTimeFromUser 

        if (!valid1)//if the start time is invalid it prints out  the start time entered is invalid
        {
                cout << "The start time entered is invalid!" << endl;
                return 0;
        }
      else
        {
                cout << "Enter the end time for the lecture (format is HH:MM:SS): ";

                valid2 = end_time.getTimeFromUser();

                if (!valid2)//if the second number is invalid it prints out the end time is invalid
                {
                        cout << "The end time entered is invalid!" << endl;
                        return 0;
                }

              else//if everything is valid then it prints out start time and end time of lecture
                {
                        cout<<"The lecture starts at ";
                        start_time.print24Hour();//gets the start time and prints it out
                        cout<<" and ends at ";
                        end_time.print24Hour();//gets the end time and prints it out
                        cout<<endl;// ends the line
                }

       }

        return 0;
}

