#include "all.h"

void Dashboard(){
	char inp;
	int pages = counter.recordcount/25, pagecheck, page=1; // 25 list per page
	counter.recordcount%25==0 ? pages:pages++;
	dashpage(1, pages);
	while(1){
		checkerror = 0;
		scanf("\n%c", &inp);
		if(isdigit(inp)){
			pagecheck = (int) inp - 48;
            if ((pagecheck <= pages) && (pagecheck >= 1)) {
                page = (int) inp - 48;
                dashpage(page, pages);
            } 
            else {
            	checkerror =1;
                dashpage(page, pages);
                
            }
		}
		else{
			switch(toupper(inp)){
			case 'B':
				home();
				break;
			case 'Q':
				quit();
				break;
			default:
				checkerror =1;
				dashpage(page, pages);

			}
		}
	}
	
}

void dashpage(int page, int pages){

	clearscreen();
	userhead();
	printf("| Date         | Time         | Description                                                  | Income       | Expenses     | Balance        |\n");
	fullborder();
	if(page == pages || pages == 0){
		for(int i = (page-1)*25;i<counter.recordcount;i++){
			printf("| %02d/%02d/%04d   | %02d:%02d:%02d     | %-61s| %13.2lf| %13.2lf| %15.2lf|\n", record[i].day, record[i].month, record[i].year, record[i].hour, record[i].min, record[i].sec, record[i].description, record[i].income, record[i].expense, record[i].balance);
		}
		for(int i = 0;i<25-(counter.recordcount%25);i++){
			printf("|              |              |                                                              |              |              |                |\n");
		}
	}
	else{
		for(int i = (page-1)*25; i < page*25; i++){
			printf("| %02d/%02d/%04d   | %02d:%02d:%02d     | %-61s| %13.2lf| %13.2lf| %15.2lf|\n", record[i].day, record[i].month, record[i].year, record[i].hour, record[i].min, record[i].sec, record[i].description, record[i].income, record[i].expense, record[i].balance);
		}
	}
	fullborder();
	checkerror == 1 ? centertext("Invalid response. Please try again."):emptyborder();
	printf("|                                                                << %d of %d >>                                                               |\n", page, pages);
	centertext("Type \"B\" to Back || Type \"Q\" to Quit");
	bottomborder();
	printf(">>");

}

void accountset(){
	clearscreen();
	head();
	emptyborder();
	for(int i = 0;i<13;i++){
		emptyborder();
	}
	centertext("1. Change your password");
	centertext("2. Delete account");
	for(int i = 0;i<12;i++){
		emptyborder();
	}

	checkerror == 1 ? centertext("Invalid response. Please try again."):emptyborder();
	emptyborder();
	centertext("Type \"B\" to Back || Type \"Q\" to Quit");
	bottomborder();

	
	char inp;
	printf(">> ");
	checkerror = 0;
	scanf("\n%c", &inp);
	switch(toupper(inp)){
		case '1':
			passwordchange();
			break;
		case '2':
			arerusure();
			break;
		case 'B':
			home();
			break;
		case 'Q':
			quit();
			break;
		default:
			checkerror =1;
			accountset();

	}
}

void passwordchange(){
	char password[71], newpass[71], confirm[71];
	while(1){
		if(strcmp(password, "\\\\C")==0 || strcmp(password, "\\\\c")==0 || strcmp(newpass, "\\\\C")==0|| strcmp(newpass, "\\\\c")==0|| strcmp(confirm, "\\\\C")==0 || strcmp(confirm, "\\\\c")==0){
			checkerror = 0;
			accountset();
		}
		clearscreen();
		smallhead("Change password");
		for(int i = 0;i<14;i++){
       		emptyborder();
    	}
    	if(counter.phasecount == 0){
    		centertext("Enter your password");
    	}
    	else if(counter.phasecount == 1){
    		centertext("Enter your new password");
    	}
    	else if(counter.phasecount == 2){
    		centertext("Confirm your new password");
    	}
    	else{
    		centertext("success");
    	}
    	for(int i = 0;i<16;i++){
        	emptyborder();
    	}
    	checkerror == 1 ? counter.phasecount == 0 ? centertext("Wrong password"): centertext("Passwords do not match"):emptyborder();
    	emptyborder();
    	centertext("Type \"\\\\C\" to Cancel");
    	bottomborder();

    	checkerror = 0;
    	if(counter.phasecount > 2){
    		strcpy(user.password, newpass);
    		strcpy(usercheck[userorder].password, newpass);
    		userwrite();
    		sleep(3);
    	}
    	else{
    		printf(">> ");
    	}
		switch(counter.phasecount){
			case 0:
				scanf("\n%s", password);
				counter.phasecount++;
				if(strcmp(password, user.password)!=0){
					counter.phasecount--;
					checkerror = 1;
				}
				break;
			case 1:
				scanf("\n%s", newpass);
				counter.phasecount++;
				break;
			case 2:
				scanf("\n%s", confirm);
				counter.phasecount++;
				if(strcmp(newpass, confirm)!=0){
					counter.phasecount-=2;
					checkerror = 1;
				}
				break;
			default:
			counter.phasecount=0;
			accountset();
		}
	}
}


void arerusure(){
	clearscreen();
	smallhead("Are you Sure");
	for(int i = 0;i<14;i++){
        emptyborder();
    }
    centertext("All your activities will be deleted.");
    centertext("Are you Sure?");
    emptyborder();
    centertext("< Y/N >");
    for(int i = 0;i<14;i++){
        emptyborder();
    }
    checkerror == 1 ? centertext("Invalid input. Please Try Again"):emptyborder();
    emptyborder();
    bottomborder();

    char inp;
	printf(">> ");
	checkerror = 0;
	scanf("\n%c", &inp);
	switch(toupper(inp)){
		case 'Y':
			goodbye();
			break;
		case 'N':
			accountset();
			break;
		default:
			checkerror =1;
			accountset();

	}
}

void goodbye(){
	char name[100];
	strcpy(name, user.name);
	clearscreen();
	smallhead("Good Bye");
	for(int i = 0;i<14;i++){
        emptyborder();
    }
    centertext("Good Bye");
    emptyborder();
    centertext(name);
    emptyborder();
    centertext("We will miss you");
    for(int i = 0;i<15;i++){
        emptyborder();
    }
    bottomborder();
    deleteAccount();

    strcpy(filename, "") ;// clear old user
    strcpy(user.username, "");// clear old user
    strcpy(user.password, "");// clear old user
    strcpy(user.name, "");// clear old user

    sleep(5);
    start();
}
