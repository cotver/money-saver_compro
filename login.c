#include "all.h"

void loginphase(){
	FILE *fp;

    fp = fopen("data/user.txt", "r");
    int em = fgetc(fp); // check empty txt
	if (em != EOF) {
    	fscanf(fp, "%[^\t]\t%ld", user.name, &user.balance);
    	bottomborder();
	}
	else{
		regisphase();
	}
    fclose(fp);
}

void regisphase(){
	head();
	for(int i = 0;i<8;i++){
		emptyborder();
	}
	centertext("This is your first time use");
	emptyborder();
	centertext("Please enter your full name");
	for(int i = 0;i<20;i++){
		emptyborder();
	}
	bottomborder();
	printf("Enter your full name: ");
	scanf("\n%[^\n]", user.name);
	user.balance = 0;


}

