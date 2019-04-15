#include "all.h"

void recordpage(){
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
    	centertext("Please Enter your amount");
    	centertext("(If Expense Enter Negative number)");
    }
    else{
    	centertext("success");
    	emptyborder();
    }
    for(int i = 0;i<16;i++){
        emptyborder();
    }
    checkerror == 1 ? inprecord.income == 0? centertext("Invalid input. Please Try Again"):centertext("You don't have enough money. Please Try Again"):emptyborder();
    emptyborder();
    bottomborder();
    if(counter.phasecount >= 2){
    	get_time();
    	inprecord.day = times.day;
		inprecord.month = times.month;
		inprecord.year = times.year;
		inprecord.hour = times.hour;
		inprecord.min = times.min;
		inprecord.sec = times.sec;
		user.balance+=inprecord.income;
		user.balance-=inprecord.expense;
		inprecord.balance=user.balance;
		addrecord();
		recordwrite();
		usercheck[userorder].balance = user.balance;
		userwrite();
    	sleep(2);
    }
    else{
    	printf(">> ");
    }
    checkerror = 0;
    switch(counter.phasecount){
		case 0:
			scanf("\n%[^\n]", inprecord.description);
			counter.phasecount++;
			recordpage();
			break;
		case 1:
			scanf("\n%lf", &inprecord.income);
			counter.phasecount++;
			if(inprecord.income==0){
				checkerror=1;
				counter.phasecount--;
			}
			else if(inprecord.income < 0){
				if(inprecord.income*-1 > user.balance){
					checkerror=1;
					counter.phasecount--;
				}
				else{
					inprecord.expense = inprecord.income*-1;
					inprecord.income = 0;
				}
			}
			else{
				inprecord.expense =0;
			}
			recordpage();
			break;
		default:
			counter.phasecount =0;
			home();

	}
}


void addrecord(){

	if(counter.recordcount+1 > Max_Record){
		counter.recordcount = Max_Record;
	}
	else{
		counter.recordcount++;
	}

	for(int i=0; i<counter.recordcount; i++){
		saverec.day = record[i].day;
		saverec.month = record[i].month;
		saverec.year = record[i].year;
		saverec.hour = record[i].hour;
		saverec.min = record[i].min;
		saverec.sec = record[i].sec;
		strcpy(saverec.description, record[i].description);
		saverec.income = record[i].income;
		saverec.expense = record[i].expense;
		saverec.balance = record[i].balance;
		
		record[i].day = inprecord.day;
		record[i].month = inprecord.month;
		record[i].year = inprecord.year;
		record[i].hour = inprecord.hour;
		record[i].min = inprecord.min;
		record[i].sec = inprecord.sec;
		strcpy(record[i].description, inprecord.description);
		record[i].income = inprecord.income;
		record[i].expense = inprecord.expense;
		record[i].balance = inprecord.balance;
		
		inprecord.day = saverec.day;
		inprecord.month = saverec.month;
		inprecord.year = saverec.year;
		inprecord.hour = saverec.hour;
		inprecord.min = saverec.min;
		inprecord.sec = saverec.sec;
		strcpy(inprecord.description, saverec.description);
		inprecord.income = saverec.income;
		inprecord.expense = saverec.expense;
		inprecord.balance = saverec.balance;
	}
}

