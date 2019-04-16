#include "all.h"


void get_time(){
	int hours, minutes, seconds, day, month, year;
	// time_t is arithmetic time type
	time_t now;
	
	// Obtain current time
	time(&now);

	// returns a pointer to a tm structure with its members 
	// filled with the corresponding values
	struct tm *local = localtime(&now);

	day = local->tm_mday;        	// get day of month (1 to 31)
	month = local->tm_mon + 1;   	// get month of year (0 to 11)
	year = local->tm_year + 1900;	// get year since 1900
	hours = local->tm_hour;      	// get hours since midnight (0-23)
	minutes = local->tm_min;     	// get minutes passed after the hour (0-59)
	seconds = local->tm_sec;     	// get seconds passed after minute (0-59)

	times.day = day;
	times.month = month;
	times.year = year;
	times.hour = hours;
	times.min = minutes;
	times.sec = seconds;
}
