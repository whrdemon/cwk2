#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "run.h"
int main(){

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