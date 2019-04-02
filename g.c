#include "all.h"

int main(){
	loginphase();
	start();

	return 0;
}

void start(){
	head();
	for(int i = 0;i<8;i++){
		emptyborder();
	}
	for(int i = 0;i<12;i++){
		emptyborder();
	
	}
	checkerror == 1 ? centertext("Invalid response. Please try again."):emptyborder();
	emptyborder();
	centertext("Type \"L\" to Login || Type \"R\" to Register || Type \"Q\" to Quit");
	bottomborder();
	char inp;
	printf(">> ");
	scanf("\n%c", &inp);
	checkerror = 0;
	switch(toupper(inp)){
		case 'L':
			loginphase();
			break;
		case 'R':
			regisphase();
			break;
		case 'Q':
			//quit program
			break;
		default:
			checkerror =1;
			start();

	}
}

void home(){
	head();
	emptyborder();
	welcome();
	for(int i = 0;i<8;i++){
		emptyborder();
	}
	centertext("1. Dashboard");
	centertext("2. Record your income");
	centertext("3. See your plan");
	centertext("4. Reset");
	for(int i = 0;i<12;i++){
		emptyborder();
	}

	checkerror == 1 ? centertext("Invalid response. Please try again."):emptyborder();
	emptyborder();
	centertext("Type \"Q\" to Quit the program");
	bottomborder();
	char inp;
	printf(">> ");
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
		case '4':
			//dosomething
			break;
		case 'Q':
			//quit program
			break;
		default:
			checkerror =1;
			home();

	}
}