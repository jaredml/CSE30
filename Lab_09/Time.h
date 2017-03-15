#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class Time
{
	private:         
		int hours, minutes, seconds;// a total of three private variables
	public:
		Time();//default constructor
		Time(int, int, int);//alternative constructor
		~Time();//destructor
		int Accesshours();		
		int Accessminutes();
		int Accessseconds();	
		void setHours(int);
		void setMinutes(int);
		void setSeconds(int);
		bool getTimeFromUser();
		void print24Hour();
	
};
