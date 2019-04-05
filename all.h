#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


#define screen_lenght 139
#define Max_Record 100
#define Max_User 50


// header border text
void head();
void emptyborder();
void centertext(char text[139]);
void righttext(char text[139]);
void lefttext(char text[139]);
void clearscreen();
void bottomborder();
void welcome();
void logtext(char text[69], char inp[69]);
void fullborder();


// system
// user login
void loginphase();
void regisphase();
void regisload();
void userfull();
void loginfail();
void loginload();
// page
void start();
void home();
void Dashboard();


//call/create data
void usercall();
void createuser(char username[71], char password[71], char name[200], double balance);



int checkerror; //to check error



struct counter{ //count
	int recordcount;
	int	usercount;
	int registercount;

}counter;


struct user{
	char username[71];
	char password[71];
	char name[200];
	double balance;
}user;

struct usercheck{
	char username[71];
	char password[71];
	char name[200];
	double balance;
}usercheck[Max_User];

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