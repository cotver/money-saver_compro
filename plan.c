#include "all.h"

void savingaccount(){
	char inp;
	int pages = counter.plancount/3, pagecheck, page=1; // 25 list per page
	counter.plancount%3==0 ? pages:pages++;
	savingpage(1, pages);
	while(1){
		checkerror = 0;
		scanf("\n%c", &inp);
		if(isdigit(inp)){
			pagecheck = (int) inp - 48;
            if ((pagecheck <= pages) && (pagecheck >= 1)) {
                page = (int) inp - 48;
                savingpage(page, pages);
            } 
            else {
            	checkerror =1;
                savingpage(page, pages);
                
            }
		}
		else{
			switch(toupper(inp)){
			case 'W':
				withdraw();
				break;
			case 'P':
				if(counter.plancount >= Max_Plan){
					planfull();
				}
				else{
					createplan();
				}
				break;
			case 'E':
				EditPlan();
				break;
			case 'B':
				home();
				break;
			case 'Q':
				quit();
				break;
			default:
				checkerror =1;
				savingpage(page, pages);

			}
		}
	}
	
}

void savingpage(int page, int pages){
	clearscreen();
	userhead("Your Saving Balance", user.savingbalance);
	centertext("Your Plan");
	fullborder();
	printf("| Description                                                                        | success(%%)                                           |\n");
	fullsmallborder();
	if((page == pages || pages == 0) && counter.plancount%3!= 0){
		for(int i = (page-1)*3;i<counter.plancount;i++){
			printf("|                                                                                    |                                                      |\n");
			int percen = (plan[i].current/plan[i].goal)*100, tube = percen/2;
			printf("| %-83s| %26.2lf/%-26.2lf|\n", "", plan[i].current, plan[i].goal);
			printf("| %-83s| ┏                                                  ┓ |\n", "" );
			printf("| %-83s| ┃", plan[i].description);
			for(int j=0; j<50; j++){
				if(j<tube){
					printf("|");
				}
				else{
					printf(" ");
				}
			}
			printf("┃ |\n");
			printf("| %-83s| ┗                                                  ┛ |\n", "");
			percen >= 100 ? printf("| %-83s|       Success!! Type \"E\" to finish your plan         |\n", "" ):printf("| %-83s| %27d%%                         |\n", "", percen );
			fullsmallborder();
		}
		for(int i = 0;i<3-(counter.plancount%3);i++){
			for(int j=0; j < 7; j++){
				printf("|                                                                                    |                                                      |\n");
			}
		}
	}
	else{
		for(int i = (page-1)*3; i < page*3; i++){
			printf("|                                                                                    |                                                      |\n");
			int percen = (plan[i].current/plan[i].goal)*100, tube = percen/2;
			printf("| %-83s| %26.2lf/%-26.2lf|\n", "", plan[i].current, plan[i].goal);
			printf("| %-83s| ┏                                                  ┓ |\n", "" );
			printf("| %-83s| ┃", plan[i].description);
			for(int j=0; j<50; j++){
				if(j<tube){
					printf("|");
				}
				else{
					printf(" ");
				}
			}
			printf("┃ |\n");
			printf("| %-83s| ┗                                                  ┛ |\n", "");
			percen >= 100 ? printf("| %-83s|       Success!! Type \"E\" to finish your plan         |\n", "" ):printf("| %-83s| %27d%%                         |\n", "", percen );
			fullsmallborder();
		}
	}
	centertext("Type \"W\" to Withdraw");
	centertext("Type \"P\" to Create your plan || Type \"E\" to Edit your plan");
	fullborder();
	checkerror == 1 ? centertext("Invalid response. Please try again."):emptyborder();
	printf("|                                                                << %d of %d >>                                                               |\n", page, pages);
	centertext("Type \"B\" to Back || Type \"Q\" to Quit");
	bottomborder();
	printf(">>");
}

void createplan(){
	clearscreen();
	smallhead("Record");
	for(int i = 0;i<14;i++){
        emptyborder();
    }
    if(counter.phasecount == 0){
    	centertext("Please Enter your description for your record");
    	centertext("(Up to 50 character)");
    }
    else if(counter.phasecount == 1){
    	centertext("Please Enter your goal");
    	emptyborder();
    }
    else{
    	centertext("success");
    	emptyborder();
    }
    for(int i = 0;i<16;i++){
        emptyborder();
    }
    checkerror == 1 ? centertext("Invalid input. Please Try Again"):emptyborder();
    emptyborder();
    bottomborder();
    if(counter.phasecount >= 2){
    	plan[counter.plancount].goal = inpplan.goal;
    	strcpy(plan[counter.plancount].description, inpplan.description);
    	plan[counter.plancount].current = 0;
		counter.plancount++;
		planwrite();
    	sleep(2);
    }
    else{
    	printf(">> ");
    }
    checkerror = 0;
    switch(counter.phasecount){
		case 0:
			scanf("\n%[^\n]", inpplan.description);
			counter.phasecount++;
			createplan();
			break;
		case 1:
			scanf("\n%lf", &inpplan.goal);
			counter.phasecount++;
			if(inpplan.goal<=0){
				checkerror=1;
				counter.phasecount--;
			}
			createplan();
			break;
		default:
			counter.phasecount =0;
			savingaccount();

	}
}

void planfull(){
    clearscreen();
    smallhead("Oops !!!");
    emptyborder();
    emptyborder();
    centertext("Sorry, your plan is full.");
    emptyborder();
    centertext("Please try again later.");
    for(int i = 0;i<26;i++){
        emptyborder();
    }
    checkerror == 1 ? centertext("Invalid response. Please try again."):emptyborder();
    emptyborder();
    centertext("Type \"E\" to Edit your plan || Type \"B\" to Back");
    bottomborder();
    char inp;
    printf(">> ");
    scanf("\n%c", &inp);
    checkerror = 0;
    switch(toupper(inp)){
        case 'E':
        	EditPlan();
            break;
        case 'B':
            savingaccount();
            break;
        default:
            checkerror =1;
            userfull();

    }
}


void EditPlan(){
	int select = planselect();
	while(1){
		clearscreen();
		smallhead("Edit your plan");
		emptyborder();
		centertext(plan[select].description);
		for(int i = 0;i<12;i++){
    	    emptyborder();
    	}
   		centertext("1. Edit Plan Description");
   		centertext("2. Edit Plan Goal");
   		centertext("3. Delete this plan");
    	plan[select].goal == plan[select].current ? centertext("4. Finish this plan"):emptyborder();
    	for(int i = 0;i<13;i++){
    	    emptyborder();
    	}
    	checkerror == 1 ? centertext("Invalid input. Please Try Again"):emptyborder();
    	emptyborder();
    	centertext("Type \"B\" to Back");
    	bottomborder();
    	checkerror=0;
    	char inp;
    	printf(">> ");
    	scanf("\n%c", &inp);
    	if(isdigit(inp)){
        	switch(inp-48){
				case 1:
					editdescription(select);
					break;
				case 2:
					editgoal(select);
					break;
				case 3:
					deleteplan(select);
					editsuccess();
					savingaccount();
					break;
				case 4:
					if(plan[select].goal == plan[select].current){
						user.savingbalance -= plan[select].goal;
						usercheck[userorder].savingbalance -= plan[select].goal;
						userwrite();
						deleteplan(select);
						editsuccess();
						savingaccount();
					}
					else{
						checkerror=1;
					}
					break;
				default:
					checkerror=1;
    		}
    	}
		else{
			switch(toupper(inp)){
				case 'B':
					savingaccount();
					break;
				default:
					checkerror=1;
    				EditPlan();

			}
		}
	}
}

void editgoal(int select){
	double newgoal;
	char old[100];
	sprintf(old, "(your old goal: %.2lf)", plan[select].goal);
	clearscreen();
	smallhead("Edit your plan");
	for(int i = 0;i<16;i++){
    	emptyborder();
    }
    centertext("Please Enter your new goal");
    centertext(old);
    for(int i = 0;i<14;i++){
    	emptyborder();
    }
    checkerror == 1 ? centertext("Invalid response. Please try again."):emptyborder();
    emptyborder();
    bottomborder();
    checkerror = 0;
    printf(">> ");
    scanf("\n%lf", &newgoal);
    if(newgoal<=0){
    	checkerror =1;
    	editgoal(select);
    }
    else{
    	if(newgoal < plan[select].current){
    		plan[select].current = newgoal;
    	}
    	plan[select].goal = newgoal;
    	planwrite();
    	editsuccess();
		savingaccount();
    }
}

void editdescription(int select){
	char newdescription[50], old[100];
	sprintf(old, "(your old description: %s)", plan[select].description);
	clearscreen();
	smallhead("Edit your plan");
	for(int i = 0;i<16;i++){
    	emptyborder();
    }
    centertext("Please Enter your new description");
    centertext(old);
    for(int i = 0;i<16;i++){
    	emptyborder();
    }
    bottomborder();

    printf(">> ");
    scanf("\n%[^\n]", newdescription);

    strcpy(plan[select].description, newdescription);
    planwrite();
    editsuccess();
	savingaccount();
}

void editsuccess(){
	clearscreen();
	smallhead("Edit your plan");
	for(int i = 0;i<16;i++){
    	emptyborder();
    }
    centertext("Success");
    for(int i = 0;i<17;i++){
    	emptyborder();
    }
    bottomborder();
    sleep(1);
}

int planselect(){
	char planname[100];
	clearscreen();
	smallhead("Edit your plan");
	for(int i = 0;i<11;i++){
    	emptyborder();
    }
	emptyborder();
	centertext("Select your plan");
	emptyborder();
	for(int i=0; i<counter.plancount; i++){
		sprintf(planname, "%d. %s", i+1, plan[i].description);
		centertext(planname);
	}
	for(int i = 0;i<17-counter.plancount;i++){
    	emptyborder();
    }
    checkerror == 1 ? centertext("Invalid response. Please try again."):emptyborder();
    emptyborder();
    centertext("Type \"B\" to Back");
    bottomborder();
    checkerror=0;
    char inp;
    printf(">> ");
    scanf("\n%c", &inp);
    if(isdigit(inp)){
        if(inp-48 >= 1 && inp-48 <= counter.plancount) {
            return inp-48-1;
        } 
        else {
            checkerror =1;
            planselect();   
            }
		}
	else{
		switch(toupper(inp)){
			case 'B':
				savingaccount();
				break;
			default:
				checkerror=1;
    			planselect();

		}
	}
}


void withdraw(){
	double amount, sumofplan=0;
	char description[60], maxinp[50];
	for(int i = 0; i < counter.plancount; i++){
		sumofplan += plan[i].current;
	}
	sprintf(maxinp, "(Max %.2lf)", user.savingbalance - sumofplan);
	while(1){
		clearscreen();
		smallhead("Withdraw");
		for(int i = 0;i<14;i++){
    	    emptyborder();
    	}
    	if(counter.phasecount == 0){
   		 	centertext("Please Enter your amount");
    		centertext(maxinp);
    	}
    	else{
    		centertext("success");
    		emptyborder();
    	}
    	for(int i = 0;i<16;i++){
    	    emptyborder();
    	}
    	checkerror == 1 ? amount < 0? centertext("Invalid input. Please Try Again"):centertext("You don't have enough money. Please Try Again"):emptyborder();
    	emptyborder();
    	bottomborder();
    	if(counter.phasecount >= 1){
    		sprintf(description, "Withdraw from Savings Account");
    		user.savingbalance -= amount;
    		usercheck[userorder].savingbalance -= amount;
    		user.balance += amount;
    		usercheck[userorder].balance += amount;

    		get_time();
    		inprecord.day = times.day;
			inprecord.month = times.month;
			inprecord.year = times.year;
			inprecord.hour = times.hour;
			inprecord.min = times.min;
			inprecord.sec = times.sec;
			strcpy(inprecord.description, description);
    		inprecord.income = amount;
    		inprecord.expense = 0;
    		inprecord.balance = user.balance;
    		addrecord();
			recordwrite();
    		userwrite();

    		sleep(2);
    	}
    	else{
    		printf(">> ");
    	}
    	checkerror = 0;
    	switch(counter.phasecount){
			case 0:
				scanf("\n%lf", &amount);
				counter.phasecount++;
				if(amount < 0 || amount > user.savingbalance - sumofplan){
					checkerror=1;
					counter.phasecount--;
				}
				break;
			default:
				counter.phasecount =0;
				savingaccount();

		}
	}
}


void deposit(){
	int select = depositplanselect();
	double amount;
	char description[60], maxinp[50];
	sprintf(maxinp, "(Max %.2lf)", user.balance);
	while(1){
		clearscreen();
		smallhead("Deposit");
		for(int i = 0;i<14;i++){
    	    emptyborder();
    	}
    	if(counter.phasecount == 0){
   		 	centertext("Please Enter your amount");
    		centertext(maxinp);
    	}
    	else{
    		centertext("success");
    		emptyborder();
    	}
    	for(int i = 0;i<16;i++){
    	    emptyborder();
    	}
    	checkerror == 1 ? amount < 0? centertext("Invalid input. Please Try Again"):centertext("You don't have enough money. Please Try Again"):emptyborder();
    	emptyborder();
    	bottomborder();
    	if(counter.phasecount >= 1){
    		if(select>=0){
    			sprintf(description, "For %s", plan[select].description);
    		}
    		else{
    			sprintf(description, "For %s", "Savings");
    		}
    		user.savingbalance += amount;
    		usercheck[userorder].savingbalance += amount;
    		user.balance -= amount;
    		usercheck[userorder].balance -= amount;

    		get_time();
    		inprecord.day = times.day;
			inprecord.month = times.month;
			inprecord.year = times.year;
			inprecord.hour = times.hour;
			inprecord.min = times.min;
			inprecord.sec = times.sec;
			strcpy(inprecord.description, description);
    		inprecord.income = 0;
    		inprecord.expense = amount;
    		inprecord.balance = user.balance;
    		addrecord();
			recordwrite();
    		userwrite();
    		if(plan[select].current + amount > plan[select].goal){
    			plan[select].current += plan[select].goal - plan[select].current;
    		}
    		else{
    			plan[select].current += amount;
    		}
    		planwrite();
    		sleep(2);
    	}
    	else{
    		printf(">> ");
    	}
    	checkerror = 0;
    	switch(counter.phasecount){
			case 0:
				scanf("\n%lf", &amount);
				counter.phasecount++;
				if(amount < 0 || amount > user.balance){
					checkerror=1;
					counter.phasecount--;
				}
				break;
			default:
				counter.phasecount =0;
				home();

		}
	}
	
}

int depositplanselect(){
	char planname[100];
	clearscreen();
	smallhead("Deposit");
	for(int i = 0;i<10;i++){
    	emptyborder();
    }
	emptyborder();
	centertext("Select your plan");
	emptyborder();
	centertext("1. For Savings");
	for(int i=0; i<counter.plancount; i++){
		sprintf(planname, "%d. For %s", i+2, plan[i].description);
		centertext(planname);
	}
	for(int i = 0;i<17-counter.plancount;i++){
    	emptyborder();
    }
    checkerror == 1 ? centertext("Invalid response. Please try again."):emptyborder();
    emptyborder();
    centertext("Type \"B\" to Back");
    bottomborder();
    checkerror=0;
    char inp;
    printf(">> ");
    scanf("\n%c", &inp);
    if(isdigit(inp)){
        if(inp-48 >= 1 && inp-48 <= counter.plancount+1) {
            return inp-48-2;
        } 
        else {
            checkerror =1;
            depositplanselect();   
            }
		}
	else{
		switch(toupper(inp)){
			case 'B':
				home();
				break;
			default:
				checkerror=1;
    	depositplanselect();

		}
	}
}