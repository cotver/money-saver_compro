#include "all.h"

void head(){
	printf("|━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┏━┓┏━┓ ┏━━━┓ ┏━┓ ┏┓ ┏━━━┓ ┏┓  ┏┓   ┏━━━┓ ┏━━━┓ ┏┓  ┏┓ ┏━━━┓ ┏━━━┓━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━|\n");
	printf("|                                     ┃┃┗┛┃┃ ┃┏━┓┃ ┃┃┗┓┃┃ ┃┏━━┛ ┃┗┓┏┛┃   ┃┏━┓┃ ┃┏━┓┃ ┃┗┓┏┛┃ ┃┏━━┛ ┃┏━┓┃                                     |\n");
	printf("|                                     ┃┏┓┏┓┃ ┃┃ ┃┃ ┃┏┓┗┛┃ ┃┗━━┓ ┗┓┗┛┏┛   ┃┗━━┓ ┃┃ ┃┃ ┗┓┃┃┏┛ ┃┗━━┓ ┃┗━┛┃                                     |\n");
	printf("|                                     ┃┃┃┃┃┃ ┃┃ ┃┃ ┃┃┗┓┃┃ ┃┏━━┛  ┗┓┏┛    ┗━━┓┃ ┃┗━┛┃  ┃┗┛┃  ┃┏━━┛ ┃┏┓┏┛                                     |\n");
	printf("|                                     ┃┃┃┃┃┃ ┃┗━┛┃ ┃┃ ┃┃┃ ┃┗━━┓   ┃┃     ┃┗━┛┃ ┃┏━┓┃  ┗┓┏┛  ┃┗━━┓ ┃┃┃┗┓                                     |\n");
	printf("|━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┗┛┗┛┗┛ ┗━━━┛ ┗┛ ┗━┛ ┗━━━┛   ┗┛     ┗━━━┛ ┗┛ ┗┛   ┗┛   ┗━━━┛ ┗┛┗━┛━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━|\n");
}

void emptyborder(){
	printf("|                                                                                                                                           |\n");
}

void centertext(char text[139]){
	int lenght = strlen(text);
	int strlenght = screen_lenght-lenght, right, left, i;
	if (strlenght%2 != 0){
		right = strlenght/2;
		left = strlenght/2 + 1;
	}
	else{
		right = strlenght/2;
		left = strlenght/2;
	}
	printf("|");
	for(i=0; i<right; i++){
		printf(" ");
	}
	printf("%s", text);
	for(i=0; i<left; i++){
		printf(" ");
	}
	printf("|");
	printf("\n");
}

void righttext(char text[139]){
	printf("|%139s|\n", text);
}

void lefttext(char text[139]){
	printf("|%-139s|\n", text);
}

void clearscreen(){
	printf("\n");
	system("clear");
}

void bottomborder(){
	printf("|━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━|\n\n");
}

void fullborder(){
	printf("|━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━|\n");
}

void welcome(){
	printf("|  █   █ █▀▀ █   █▀▀ █▀▀█ █▀▄▀█ █▀▀                                                                                                         |\n");
	printf("|  █▄█▄█ █▀▀ █   █   █  █ █ ▀ █ █▀▀                                                                                                         |\n");
	printf("|   ▀ ▀  ▀▀▀ ▀▀▀ ▀▀▀ ▀▀▀▀ ▀   ▀ ▀▀▀     %-100s|\n", user.name);
}

void logtext(char text[69], char inp[69]){
	printf("|%68s %-70s|\n", text, inp);
}

void smallhead(char text[139]){
	fullborder();
	centertext(text);
	fullborder();
}

void userhead(){
	printf("|━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┏━┓┏━┓━━━┏━━━┓━|\n");
	printf("|                                                                                                                            ┃┃┗┛┃┃   ┃┏━┓┃ |\n");
	printf("|         name: %-100s         ┃┏┓┏┓┃   ┃┗━━┓ |\n", user.name);
	printf("|                                                                                                                            ┃┃┃┃┃┃   ┗━━┓┃ |\n");
	printf("| Your Balance: %-100.2lf         ┃┃┃┃┃┃   ┃┗━┛┃ |\n", user.balance);
	printf("|━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┗┛┗┛┗┛━━━┗━━━┛━|\n");
}