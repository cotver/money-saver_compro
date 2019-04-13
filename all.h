#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>


#define screen_lenght 139
#define Max_Record 200
#define Max_User 50
#define Max_Plan 6



// header border text
void head();                    // head
void userhead(char text[20], double balance);
void smallhead(char text[139]); //
void emptyborder();             // border
void bottomborder();
void fullborder();
void fullsmallborder();
void clearscreen();             //
void centertext(char text[139]);//text
void righttext(char text[139]);
void lefttext(char text[139]);
void welcome();
void logtext(char text[69], char inp[69]);//





// system
// user login/logout
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
void accountset();
void passwordchange();
void arerusure();
void goodbye();

// record page
void addrecord();
void recordpage();


// call/create/delete data
void usercall();
void createuser(char username[71], char password[71], char name[200], double balance);
void creatfilename();
void recordcall();
void userwrite();
void recordwrite();
void plancall();
void planwrite();
void get_time();
void deleteAccount();

void savingaccount();
void savingpage(int page, int pages);
void createplan();
void planfull();
void planselect();

int checkerror; //to check error

int userorder; // User order

char filename[100]; //to create user record file

char planfilename[100];//to create user plan file


struct counter{ //count
	int recordcount;//number of record
	int usercount;  //number of user
	int phasecount; //count current phase
	int plancount; //number of plan

}counter;


struct user{
	char username[71];
	char password[71];
	char name[200];
	double balance;
	double savingbalance;
}user, usercheck[Max_User]; // current user || checkuser for save login/register 



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


struct time{ //save current time
	int day;
	int month;
	int year;
	int hour;
	int min;
	int sec;
}times;

struct plan{ //plan for save money
	double goal;
	double current;
	char description[50];
}plan[Max_Plan], inpplan;