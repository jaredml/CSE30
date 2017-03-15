#include "Time.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include<iomanip>
using namespace std;

int hour, minutes, seconds;
//constructor
Time::Time()
{//Initiate to 0
	hours = 0;
	minutes = 0;
	seconds = 0;
}
//alternative constructor that takes 2 values
Time::Time(int hrs, int mins, int secs)
{//Initiate to values
	hours = hrs;
	minutes = mins;
	seconds = secs;
}

int Time::Accesshours()
{
	return hours;
}

int Time::Accessminutes()
{
	return minutes;
}

int Time::Accessseconds()
{
	return seconds;
}
//Destructor
Time::~Time()
{

}

//3 mutator functions

void Time::setHours(int hrs)
{
	hours = hrs;
}

void Time::setMinutes(int mins)
{
	minutes = mins;
}

void Time::setSeconds (int secs)
{
	seconds = secs;
}

void Time::print24Hour()
{
	//puts in zeros when needed
        cout << setfill('0') << setw(2) << Accesshours() << ":";
        cout << setfill('0') << setw(2) << Accessminutes() << ":";
        cout << setfill('0') << setw(2) << Accessseconds();
}

bool Time::getTimeFromUser(){

        string my_line;// initiates variables
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
	//changes the string of letters into ints
        
        setHours(atoi((my_line.substr(0,2)).c_str()));
        setMinutes(atoi((my_line.substr(3,2)).c_str()));
	setSeconds(atoi((my_line.substr(6,2)).c_str()));

	//checks if the hours, minutes, and seconds are in the right format and not numbers that they cant be
        if(Accesshours() < 0 || Accesshours() > 23)
                return false;
        else if(Accessminutes() < 0 || Accessminutes() > 59)
                return false;
        else if (Accessseconds() < 0 || Accessseconds() > 59)
                return false;
        else
                return true;

        return true;
}
