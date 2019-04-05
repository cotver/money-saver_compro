#include "all.h"

void loginphase(){
    clearscreen();
    head();
    for(int i = 0;i<13;i++){
        emptyborder();
    }
    logtext("username:", user.username);
    emptyborder();
    logtext("password:", "");
    emptyborder();
    for(int i = 0;i<14;i++){
        emptyborder();
    }
    bottomborder();
    
    switch(counter.registercount){
        case 0:
            printf("Enter your username: ");
            scanf("\n%s", user.username);
            counter.registercount++;
            loginphase();
            break;
        case 1:
            printf("Enter your password: ");
            scanf("\n%s", user.password);
            counter.registercount++;
            loginphase();
            break;
        default:
            counter.registercount=0;
            for(int i=0;i<counter.usercount;i++){
                if(strcmp(usercheck[i].username, user.username)==0){
                    if(strcmp(usercheck[i].password, user.password)==0){
                        strcpy(user.name, usercheck[i].name);
                        user.balance = usercheck[i].balance;
                        loginload();
                    }else
                        loginfail();
                }else
                    loginfail();
            }
            
    }

}
void loginload(){
    clearscreen();
    head();
    for(int i = 0;i<13;i++){
        emptyborder();
    }
    logtext("username:", user.username);
    emptyborder();
    logtext("password:", "********");
    for(int i = 0;i<3;i++){
        emptyborder();
    }
    if(counter.registercount == 1){
        printf("|                                                                         ****                                                              |\n");
        printf("|                                                                        ****                                                               |\n");
        printf("|                                                                       ****                                                                |\n");
        printf("|                                                                 **   ****                                                                 |\n");
        printf("|                                                                 *** ****                                                                  |\n");
        printf("|                                                                  ******                                                                   |\n");
        printf("|                                                                   ****                                                                    |\n");
    }
    else if(counter.registercount == 0){
        emptyborder();
        emptyborder();
        printf("|                                                                *    *    *                                                                |\n");
        printf("|                                                               ***  ***  ***                                                               |\n");
        printf("|                                                                *    *    *                                                                |\n");
        emptyborder();
        emptyborder();
    }
    for(int i = 0;i<5;i++){
        emptyborder();
    }
    bottomborder();
    sleep(2);
    if(counter.registercount == 1){
        counter.registercount =0;
        home();
    }
    else{
        counter.registercount++;
        loginload();
    }
}
void loginfail(){
    clearscreen();
    fullborder();
    centertext("Oops !!!");
    fullborder();
    emptyborder();
    emptyborder();
    centertext("Your username or password is incorrect.");
    emptyborder();
    centertext("Please Type any key to try again");
    emptyborder();
    centertext("or Type \"B\" to Back to main page.");
    for(int i = 0;i<27;i++){
        emptyborder();
    }
    bottomborder();
    strcpy(user.username,"");
    strcpy(user.password,"");
    char inp;
    printf(">> ");
    scanf("\n%c", &inp);
    switch(toupper(inp)){
        case 'B':
            start();
            break;
        default:
            loginphase();
    }
}

void regisphase(){
    clearscreen();
    head();
    for(int i = 0;i<14;i++){
        emptyborder();
    }
    logtext("username:", user.username);
    emptyborder();
    logtext("password:", user.password);
    emptyborder();
    logtext("fullname:", user.name);
    for(int i = 0;i<10;i++){
        emptyborder();
    }
    checkerror == 1 ? centertext("This username is already used. Please Try Again."):emptyborder();
    emptyborder();
    bottomborder();

    checkerror = 0;

    switch(counter.registercount){
        case 0:
            printf("Enter your username: ");
            scanf("\n%s", user.username);
            counter.registercount++;
            for(int i=0;i<counter.usercount;i++){
                if(strcmp(usercheck[i].username, user.username)==0){
                    checkerror = 1;
                    counter.registercount--;
                    strcpy(user.username, "");
                    break;
                }
            }
            regisphase();
            break;
        case 1:
            printf("Enter your password: ");
            scanf("\n%s", user.password);
            counter.registercount++;
            regisphase();
            break;
        case 2:
            printf("Enter your full name: ");
            scanf("\n%[^\n]", user.name);
            counter.registercount++;
            regisphase();
            break;
        default:
            counter.registercount=0;
            user.balance = 0;
            regisload();
    }
}

void regisload(){
    clearscreen();
    head();
    for(int i = 0;i<6;i++){
        emptyborder();
    }
    centertext("We\'re creating your Account. Please wait.");
    for(int i = 0;i<7;i++){
        emptyborder();
    }
    logtext("username:", user.username);
    emptyborder();
    logtext("password:", user.password);
    emptyborder();
    logtext("fullname:", user.name);
    for(int i = 0;i<3;i++){
        emptyborder();
    }
    if(counter.registercount >=3){
        printf("|                                                                    ***                                                                    |\n");
        printf("|                                                                   *****                                                                   |\n");
    }
    else{
        emptyborder();
        emptyborder();
    }
    if(counter.registercount >=2){
        printf("|                                                                    ***                                                                    |\n");
        printf("|                                                                  *******                                                                  |\n");
        createuser(user.username, user.password, user.name, user.balance);
    }
    else{
        emptyborder();
        emptyborder();
    }
    if(counter.registercount >=1){
        printf("|                                                                 *********                                                                 |\n");
        printf("|                                                                 *********                                                                 |\n");
    }
    else{
        emptyborder();
        emptyborder();
    }
    if(counter.registercount >=0){
        printf("|                                                                 *********                                                                 |\n");
    }
    for(int i = 0;i<2;i++){
        emptyborder();
    }
    bottomborder();
    counter.registercount++;
    sleep(2);

    if(counter.registercount >=4){
        counter.registercount =0;
        home();
    } 
    else
        regisload();
}

void userfull(){
    clearscreen();
    fullborder();
    centertext("Oops !!!");
    fullborder();
    emptyborder();
    emptyborder();
    centertext("Sorry, our account is full.");
    emptyborder();
    centertext("Please try again later.");
    for(int i = 0;i<26;i++){
        emptyborder();
    }
    checkerror == 1 ? centertext("Invalid response. Please try again."):emptyborder();
    emptyborder();
    centertext("Type \"B\" to Back || Type \"Q\" to Quit");
    bottomborder();
    char inp;
    printf(">> ");
    scanf("\n%c", &inp);
    checkerror = 0;
    switch(toupper(inp)){
        case 'B':
            start();
            break;
        case 'Q':
            //dosomething
            break;
        default:
            checkerror =1;
            userfull();

    }
}
