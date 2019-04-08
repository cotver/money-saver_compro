#include "all.h"

char folder[]="data/user/"; //to create user record file
char sname[]=".txt"; //to create user record file


//check flie exist or not
int exists(const char *fname){
	if (access(fname, F_OK) != -1){ //flie exist
		return 1;
	}
	else{ //flie not exist
		return 0;
	}
}


// create filename for each user
void creatfilename(){
	strcat(filename,folder);
	strcat(filename,user.username);
	strcat(filename,sname);
}


// call all user in user.txt
void usercall(){
	if(!exists("data/user.txt")){
		fopen("data/user.txt", "w");
	}
	int i=0;
	FILE *us;
    us = fopen("data/user.txt", "r");
    while(fscanf(us, "%s\t%s\t%[^\t]\t%lf", usercheck[i].username, usercheck[i].password, usercheck[i].name, &usercheck[i].balance) != EOF){
    	i++;
    }
    fclose(us);
    counter.usercount = i;
}

// write new user to user.txt
void createuser(char username[71], char password[71], char name[200], double balance){
	strcpy(usercheck[counter.usercount].username, user.username);
	strcpy(usercheck[counter.usercount].password, user.password);
	strcpy(usercheck[counter.usercount].name, user.name);
	usercheck[counter.usercount].balance = user.balance;

	counter.usercount++;
	
	FILE *us;
    us = fopen("data/user.txt", "w");
    for(int i=0; i<counter.usercount; i++){
    	fprintf(us, "%s\t%s\t%s\t%.2lf\n", usercheck[i].username, usercheck[i].password, usercheck[i].name, usercheck[i].balance);
    }
    fclose(us);
    
}


void userwrite(){
	int i;
	FILE *us;
    us = fopen("data/user.txt", "w");
    for(i = 0; i < counter.usercount; i++){
    	fprintf(us, "%s\t%s\t%s\t%.2lf\n", usercheck[i].username, usercheck[i].password, usercheck[i].name, usercheck[i].balance);
    }
    fclose(us);
}


void recordcall(){
	if(!exists(filename)){
    	fopen(filename, "w");
	}

    int i=0;
	FILE *rec;
    rec = fopen(filename, "r");
    while(fscanf(rec, "%d/%d/%d\t%d:%d:%d\t%[^\t]\t%lf\t%lf\t%lf", &record[i].day, &record[i].month, &record[i].year, &record[i].hour, &record[i].min, &record[i].sec, record[i].description, &record[i].income, &record[i].expense, &record[i].balance) != EOF){
    	i++;
    }
    fclose(rec);
    counter.recordcount = i;
}




void recordwrite(){
	int i;
	FILE *rec;
    rec = fopen(filename, "w");
    for(i=0; i < counter.recordcount; i++){
    	fprintf(rec, "%d/%d/%d\t%d:%d:%d\t%s\t%.2lf\t%.2lf\t%.2lf\n", record[i].day, record[i].month, record[i].year, record[i].hour, record[i].min, record[i].sec, record[i].description, record[i].income, record[i].expense, record[i].balance);
    }
    fclose(rec);
}