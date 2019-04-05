#include "all.h"

void usercall(){
	int i=0;
	FILE *us;
    us = fopen("data/user.txt", "r");
    while(fscanf(us, "%s\t%s\t%[^\t]\t%lf", usercheck[i].username, usercheck[i].password, usercheck[i].name, &usercheck[i].balance) != EOF){
    	i++;
    }
    fclose(us);
    counter.usercount = i;
}

void createuser(char username[71], char password[71], char name[200], double balance){
	strcpy(usercheck[counter.usercount].username, user.username);
	strcpy(usercheck[counter.usercount].password, user.password);
	strcpy(usercheck[counter.usercount].name, user.name);
	usercheck[counter.usercount].balance = user.balance;
	FILE *us;
    us = fopen("data/user.txt", "w");
    for(int i=0;i<counter.usercount;i++){
    	fprintf(us, "%s\t%s\t%s\t%.2lf\n", usercheck[i].username, usercheck[i].password, usercheck[i].name, usercheck[i].balance);
    }
    fclose(us);
    counter.usercount++;
}