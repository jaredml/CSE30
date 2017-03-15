#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

//create Time structure with 3 integer values
struct Time
{
        int hour; //stores hours
        int minutes; //stores minutes
        int seconds; //stores seconds
};

struct Course
{
        string name; //stores the name of the course
        int credits; //stores the number of credits for the course
        bool majorRequirement; //tells if the course is a requirement for your major
        double avgGrade; //gives the average grade (in precentage) that past students received in the course
        string days; //stores the days that lectures are held
        Time startTime; //start time of the lecture
        Time endTime; //end time of the lecture
};

//convert strings into ints and store into appropriate places in Time structure
bool getTimeFromUser(Time *check, string my_line)
{
        (*check).hour = atoi((my_line.substr(0,2)).c_str());
        (*check).minutes = atoi((my_line.substr(3,2)).c_str());
        (*check).seconds = atoi((my_line.substr(6,2)).c_str());
}

//print out HH:MM:SS from Time structure
void print24Hour(Time lecture)
{
        string hour12 = "am";

        //convert to 12 hour structure
        if (lecture.hour > 12)
        {
                lecture.hour -= 12;
                hour12 = "pm";
        }

        cout << lecture.hour << ":";
        cout << setfill('0') << setw(2) << lecture.minutes << ":";
        cout << setfill('0') << setw(2) << lecture.seconds << hour12;
}

int main()
{
        string my_line; //store what is read from file
        Course school; //declare a Course variable
        int classes = 1, lines = 1; //keep track of lines and number of courses

        ifstream course_info;
        course_info.open ("in.txt"); //open the file to read

        cout << "--------------------" << endl;
        cout << "SCHEDULE OF STUDENT" << endl;
        cout << "--------------------" << endl;

        //read first line
        getline(course_info, my_line);

        //read until end of file
        while (getline(course_info, my_line))
        {
                //first line of sequence (name)
                if (lines%7 == 1)
                {
                        school.name = my_line;
                }
                //second line of sequence (credits)
                else if (lines%7 == 2)
                {
                        school.credits = atoi(my_line.c_str());
                }
                //Is the course a major requirement?
                else if (lines%7 == 3)
                {
                        if(atoi(my_line.c_str()) == 1)
                                school.majorRequirement == true;
                        else
                                school.majorRequirement == false;
                }
                //average grade for the course
                else if (lines%7 == 4)
                {
                        school.avgGrade = atof(my_line.c_str());
                }
                //lecture days
                else if (lines%7 == 5)
                {
                        school.days = my_line;
                }
                //start time of lecture
                else if (lines%7 == 6)
                {
                        getTimeFromUser(&(school.startTime),my_line);
                }
                //end time of lecture and print out everything from this course
                else if (lines%7 == 0)
                {
                        getTimeFromUser(&(school.endTime),my_line);

                        cout << "Course " << classes << ": " << school.name << endl;

                        if (school.majorRequirement)
                                cout << "Note: this course is a major requirement!" << endl;
                        else
                                cout << "Note: this course is not a major requirement!" << endl;

                        cout << "Number of Credits: " << school.credits << endl;

                        cout << "Days of Lectures: " << school.days << endl;

                        cout << "Lecture Time: ";
                        print24Hour(school.startTime);
                        cout << " - ";
                        print24Hour(school.endTime);
                        cout << endl;

                        cout << "Stat: on average students get " << school.avgGrade << "% in this course." << endl;

                        //increase number of courses
                        classes++;
                }

                //new line
                lines++;
        }

        return 0;
}
