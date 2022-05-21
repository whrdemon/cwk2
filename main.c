#include <stdio.h>
#include <string.h>
#include "run.h"
#include "SDL.h"
#include "history.h"
int main(int argc, char* args[]) {
    char choose[100], ch[100];
    int cs,chs;
    printf("----------The Game of Life-----------\n");
    printf("1.Custom launch game\n");
    printf("2.Read the file to launch game\n");
    printf("3.Continue the game\n");
    printf("4.Exit\n");
    printf("-------------------------------------\n");
    printf("Please enter the choice:");
    scanf("%s", &choose);
    cs=strlen(choose);
    if(cs>=2||(choose[0]!='1'&&choose[0]!='2'&&choose[0]!='3'&&choose[0]!='4')){
        printf("Invalid option!");
        return 0;
    }
    if(choose[0]=='4'){
        return 0;
    }
    printf("----------The Game of Life-----------\n");
    printf("1.Custom run times\n");
    printf("2.Keeps evolving until terminate\n");
    printf("3.Exit game\n");
    printf("-------------------------------------\n");
    printf("Please enter the choice:");
    scanf("%s", &ch);
    chs=strlen(ch);

    if(chs>=2||(ch[0]!='1'&&ch[0]!='2'&&ch[0]!='3')){
        printf("Invalid option!");
        return 0;
    }
    if(ch[0]=='3'){
        return 0;
    }
    if (choose[0]=='1') {
        if (ch[0]=='1')
            sdl();
        else if (ch[0]=='2')
            sdll();

        }
    else if(choose[0]=='2'){
        if(ch[0]=='1'){
    int a;
    if (getlength() == -1 || getheight() == -1) {
        printf("File not found.");
        return 0;
    }
    if (getheight() == 0) {
        printf("The file is null.");
        return 0;

    }
    a = gettimes();
    if (a == -1) {
        printf("Please enter a positive integer.");
        return 0;
    }
    run(a, getheight(), getlength());}

        else if(ch[0]=='2'){
            if (getlength() == -1 || getheight() == -1) {
                printf("File not found.");
                return 0;
            }
            if (getheight() == 0) {
                printf("The file is null.");
                return 0;

            }

            runn(getheight(), getlength());}


    }
    else if(choose[0]=='3'){

        if(ch[0]=='1'){
            int a;
            if (getlengthh() == -1 || getheighth() == -1) {
                printf("File not found.");
                return 0;
            }
            if (getheighth() == 0) {
                printf("The file is null.");
                return 0;

            }
            a = gettimesh();
            if (a == -1) {
                printf("Please enter a positive integer.");
                return 0;
            }
            runh(a, getheighth(), getlengthh());}
        else if(ch[0]=='2'){
            if (getlengthh() == -1 || getheighth() == -1) {
                printf("File not found.");
                return 0;
            }
            if (getheighth() == 0) {
                printf("The file is null.");
                return 0;

            }

            runnh(getheighth(), getlengthh());}

    }

}
