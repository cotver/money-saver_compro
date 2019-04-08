#include "all.h"

void Dashboard(){
	clearscreen();
	head();
	for(int i = 0;i<8;i++){
		emptyborder();
	}
	centertext("balance");
	for(int i = 0;i<19;i++){
		emptyborder();
	}
	checkerror == 1 ? centertext("Invalid response. Please try again."):emptyborder();
	emptyborder();
	centertext("Type \"B\" to Back || Type \"Q\" to Quit");
	bottomborder();
	char inp;
	printf(">>");
	scanf("\n%c", &inp);
	checkerror = 0;
	switch(toupper(inp)){
		case '1':
			Dashboard();
			break;
		case '2':
			//dosomething
			break;
		case '3':
			//dosomething
			break;
		case 'B':
			home();
			break;
		case 'Q':
			quit();
			break;
		default:
			checkerror =1;
			Dashboard();

	}
}