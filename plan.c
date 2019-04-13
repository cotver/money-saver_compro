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
			case 'P':
				if(counter.plancount >= Max_Plan){
					planfull();
				}
				else{
					createplan();
				}
				break;
			case 'E':
				planselect();
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
	emptyborder();
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

            break;
        case 'B':
            savingaccount();
            break;
        default:
            checkerror =1;
            userfull();

    }
}

void planselect(){
	char planname[100];
	emptyborder();
	centertext("Select your plan");
	emptyborder();
	for(int i=0; i<counter.plancount; i++){
		strcpy(planname, "");
		sprintf(planname, "%d. ", i+1);
		strcat(planname, plan[i].description);
		centertext(planname);
	}
}