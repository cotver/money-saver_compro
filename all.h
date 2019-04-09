#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>


#define screen_lenght 139
#define Max_Record 200
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
void smallhead(char text[139]);
void userhead();


// system
// user login
void loginphase();
void regisphase();
void regisload();
void userfull();
void loginfail();
void loginload();
void logout();
// page
void start();
void home();
void quit();
void Dashboard();
void dashpage(int page, int pages);

// record page
void addrecord();
void recordpage();


// call/create data
void usercall();
void createuser(char username[71], char password[71], char name[200], double balance);
void creatfilename();
void recordcall();
void userwrite();
void recordwrite();
void get_time();



int checkerror; //to check error

char filename[100]; //to create user record file

int userorder; // User order


struct counter{ //count
	int recordcount;
	int usercount;
	int phasecount;

}counter;


struct user{
	char username[71];
	char password[71];
	char name[200];
	double balance;
}user, usercheck[Max_User]; // current user || checkuser for save login register 



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
}record[Max_Record], inprecord, saverec;// save all record || input a new record || save record


struct time{
	int day;
	int month;
	int year;
	int hour;
	int min;
	int sec;
}times;