#include <stdio.h>
#include <malloc.h>
#include "run.h"
int gettimes(){
    int times;
    printf("please enter the times:");
    scanf("%i",&times);
    return times;
}

int getheight(){
    FILE *f = fopen("game.txt","r");
    int height = 0;
    char temp;
    if(f == NULL){
        printf("File not find.");
        return 0;
    }
    while(!feof(f)){
        temp= fgetc(f);
        if(temp == '\n'){
            height++;
        }
    }
    return height;
}

int getlength(){
    FILE *f = fopen("game.txt","r");
    int length = 0;
    char temp;
    if(f == NULL){
        printf("File not find.");
        return 0;
    }
    while(!feof(f)){
        temp= fgetc(f);
        if(temp == ','){
            length++;
        }
        else if(temp == '\n'){
            length++;
            break;
        }
    }
    return length;
}

void run(int ut, int height, int length){
    int** map;
    int** mm;
    int aa;
    map = (int**)malloc(sizeof(int*) * height);
    for (int i = 0; i < height; i++) {
        map[i] = (int*)malloc(sizeof(int) * length);
    }
    mm = (int**)malloc(sizeof(int*) * height);
    for (int i = 0; i < height; i++) {
        mm[i] = (int*)malloc(sizeof(int) * length);
    }
    int times=0;

    while(times<ut){
        for (int row = 0; row < height; row++) {
            for (int  col= 0; col < length; col++) {
                mm[row][col] = 0;
            }
        }


        for(int b=0;b<length;b++){
            int a=0;
            if(b==0){
                if(map[a+1][b]+map[a][b+1]+map[a+1][b+1]==3)
                    mm[a][b]=1;
                else if(map[a+1][b]+map[a][b+1]+map[a+1][b+1]==2)
                    mm[a][b]=map[a][b];
                else
                    mm[a][b]=0;
            }
            else if(b==length-1){
                if(map[a+1][b]+map[a][b-1]+map[a+1][b-1]==3)
                    mm[a][b]=1;
                else if(map[a+1][b]+map[a][b-1]+map[a+1][b-1]==2)
                    mm[a][b]=map[a][b];
                else
                    mm[a][b]=0;
            }
            else{
                if(map[a+1][b]+map[a][b-1]+map[a+1][b-1]+map[a+1][b+1]+map[a][b+1]==3)
                    mm[a][b]=1;
                else if(map[a+1][b]+map[a][b-1]+map[a+1][b-1]+map[a+1][b+1]+map[a][b+1]==2)
                    mm[a][b]=map[a][b];
                else
                    mm[a][b]=0;
            }
        }
        for(int b=0;b<length;b++){
            int a=height-1;
            if(b==0){
                if(map[a-1][b]+map[a][b+1]+map[a-1][b+1]==3)
                    mm[a][b]=1;
                else if(map[a-1][b]+map[a][b+1]+map[a-1][b+1]==2)
                    mm[a][b]=map[a][b];
                else
                    mm[a][b]=0;
            }
            else if(b==length-1){
                if(map[a-1][b]+map[a][b-1]+map[a-1][b-1]==3)
                    mm[a][b]=1;
                else if(map[a-1][b]+map[a][b-1]+map[a-1][b-1]==2)
                    mm[a][b]=map[a][b];
                else
                    mm[a][b]=0;
            }
            else{
                if(map[a-1][b]+map[a][b-1]+map[a-1][b-1]+map[a-1][b+1]+map[a][b+1]==3)
                    mm[a][b]=1;
                else if(map[a-1][b]+map[a][b-1]+map[a-1][b-1]+map[a-1][b+1]+map[a][b+1]==2)
                    mm[a][b]=map[a][b];
                else
                    mm[a][b]=0;
            }
        }
        for(int a=1;a<height-1;a++){
            int b=0;
            if(map[a-1][b]+map[a][b+1]+map[a-1][b+1]+map[a+1][b+1]+map[a+1][b]==3)
                mm[a][b]=1;
            else if(map[a-1][b]+map[a][b+1]+map[a-1][b+1]+map[a+1][b+1]+map[a+1][b]==2)
                mm[a][b]=map[a][b];
            else
                mm[a][b]=0;
        }
        for(int a=1;a<height-1;a++){
            int b=length-1;
            if(map[a-1][b]+map[a][b-1]+map[a-1][b-1]+map[a+1][b-1]+map[a+1][b]==3)
                mm[a][b]=1;
            else if(map[a-1][b]+map[a][b-1]+map[a-1][b-1]+map[a+1][b-1]+map[a+1][b]==2)
                mm[a][b]=map[a][b];
            else
                mm[a][b]=0;
        }

        for(int a=1;a< height-1;a++){
            for(int b=1;b<length-1;b++){
                aa=map[a-1][b-1]+map[a-1][b]+map[a-1][b+1]+map[a][b-1]+map[a][b+1]+map[a+1][b+1]+map[a+1][b]+map[a+1][b-1];
                if(map[a][b]==1){
                    if(aa==2||aa==3){
                        mm[a][b]=1;
                    }
                    else{
                        mm[a][b]=0;
                    }
                }
                if(map[a][b]==0){
                    if(aa==3){
                        mm[a][b]=1;
                    }
                    else{
                        mm[a][b]=0;
                    }
                }


            }
        }
        for(int a=0;a< height;a++){
            for(int b=0;b<length;b++){
                map[a][b]=mm[a][b];
            }

        }
        times++;
    }
    for(int a=0;a< height;a++){
        for(int b=0;b<length;b++){
            printf("%i",map[a][b]);
        }
        printf("\n");
    }
    for (int i = 0; i < height; i++) {
        free(map[i]);
    }
    free(map);
    for (int i = 0; i < height; i++) {
        free(mm[i]);
    }
    free(mm);
}