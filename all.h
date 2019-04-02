#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


#define screen_lenght 139
#define Max_Record 100


// header border text
void head();
void emptyborder();
void centertext(char text[139]);
void righttext(char text[139]);
void lefttext(char text[139]);
void clearscreen();
void bottomborder();
void welcome();


// user login
void loginphase();
void regisphase();

// system
void Dashboard();


void home();
void start();

int checkerror; //to check error



struct countrecord{ //number of record
	int record;

}countrecord;


struct user{
	char name[200];
	long balance;
}user;

struct record{ //record INCOME/EXPENSE
	int day;
	int month;
	int year;
	int hour;
	int min;
	int sec;
	char description[50];
	double income;
	double expense;
	double balance;
}record[Max_Record];