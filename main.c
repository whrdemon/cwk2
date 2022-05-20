#include <stdio.h>
#include "run.h"
#include "SDL.h"
int main(int argc, char* args[]) {
    int choose, ch;
    printf("----------The Game of Life-----------\n");
    printf("1.Custom launch game\n");
    printf("2.Read the file to launch game\n");
    printf("3.Exit game\n");
    printf("-------------------------------------\n");
    printf("Please enter the choice:");
    scanf("%i", &choose);
    printf("----------The Game of Life-----------\n");
    printf("1.Custom run times\n");
    printf("2. Keeps evolving until terminate\n");
    printf("3.Exit game\n");
    printf("-------------------------------------\n");
    printf("Please enter the choice:");
    scanf("%i", &ch);
    if (choose == 1) {
        if (ch == 1)
            sdl();
        else if (ch == 2)
            sdll();

        else if (ch == 3)
            return 0;
        else {
            printf("Invalid option!");
            return 0;
        }}
    else if(choose==2){
        if(ch==1){
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

        else if(ch==2){
            if (getlength() == -1 || getheight() == -1) {
                printf("File not found.");
                return 0;
            }
            if (getheight() == 0) {
                printf("The file is null.");
                return 0;

            }

            runn(getheight(), getlength());}
        else if(ch==3){
            return 0;
        } else{
            printf("Invalid option!");
            return 0;
        }

    }
    else if (choose == 3) {
        return 0;
    } else {
        printf("Invalid option!");
        return 0;
    }
}
