#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "run.h"
#include <SDL2/SDL.h>
#include "SDL.h"
int main(int argc, char* args[]){
    sdl();

    int a;
    if(getlength()==-1||getheight()==-1){
        printf("File not found.");
        return 0;
    }
    if(getheight()==0){
        printf("The file is null.");
        return 0;

    }
    a=gettimes();
    if(a==-1){
        printf("Please enter a positive integer.");
        return 0;
    }
    run(a,getheight(),getlength());
}
//#include <stdio.h>
//#include "SDL.h"
//
//int main(int argc, char *argv[])
//{
//    sdl();
//    return 0;
//}
