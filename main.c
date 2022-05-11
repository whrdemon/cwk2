#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "run.h"
int main(){
    FILE *f= fopen("game.txt","r");
    if(f == NULL){
        printf("File not find.");
        return 0;
    }
    fclose(f);
    run(gettimes(),getheight(),getlength());
}
