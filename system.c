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
	if(page == pages){
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

