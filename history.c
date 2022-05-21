#include <stdio.h>

#include "history.h"
#include <SDL2/SDL.h>
int gettimesh(){
    int times;
    printf("please enter the times:");
    int x= scanf("%i",&times);
    if (x==1)
        return times;
    if(x==0)
        return -1;

}
int getheighth(){
    FILE *f = fopen("history.txt","r");
    int height = 0;
    char temp;
    if(f == NULL){
        return -1;
    }
    while(!feof(f)){
        temp= fgetc(f);
        if(temp == '\n'){
            height++;
        }
    }
    fclose(f);
    if(height==0){
        return 0;
    }
    return height;
}

int getlengthh(){
    FILE *f = fopen("history.txt","r");
    int length = 0;
    char temp;

    if(f == NULL){
        return -1;
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
    fclose(f);
    return length;

}

void runh(int ut, int height, int length){
    int uu;
    printf("Please enter the stay time(ms):");
    int q = scanf("%i",&uu);
    if(q==0){
        printf("Please enter a positive integer.");
        return ;
    }
    int **map;
    int **mm;
    int aa;
    map = (int**)malloc(sizeof(int*) * height);
    for (int i = 0; i < height; i++) {
        map[i] = (int*)malloc(sizeof(int) * length);
    }
    mm = (int**)malloc(sizeof(int*) * height);
    for (int i = 0; i < height; i++) {
        mm[i] = (int*)malloc(sizeof(int) * length);
    }
    FILE *ff= fopen("history.txt","r");
    char temp;
    int x=0;
    int y=0;
    while(!feof(ff)){
        temp= fgetc(ff);
        if(temp=='1'||temp=='0'){
            int xx= (int)temp-(int)'0';
            map[x][y]= xx;

            y++;
            if(y==length){
                y=0;
            }
        }
        else if(temp=='\n'){
            x++;
        }
    }

    int times=0;
    fclose(ff);
    SDL_Window *sdl_window;
    SDL_Renderer *renderer;

    SDL_Event event;
    // 0 init sdl
    SDL_Init(SDL_INIT_VIDEO);

    //1 create window
    sdl_window = SDL_CreateWindow("Game of Life",
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  800,
                                  800,
                                  SDL_WINDOW_SHOWN);
    //2 create renderer
    renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_SOFTWARE);

    //3 set renderer color (set background color  Blue)
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);

    //4 clear color
    SDL_RenderClear(renderer);
    int de=0;
    while(times<ut){

        while(SDL_PollEvent(&event)){
            switch (event.type) {
                case SDL_KEYDOWN:
                    if( event.key.keysym.sym == SDLK_p){
                        if(de==0)
                            de=1;
                        else if(de==1)
                            de=0;
                        break;
                    }
                    else if(event.key.keysym.sym == SDLK_RIGHT){
                        if(uu>=200){
                            uu=uu-100;}
                        break;
                    }
                    else if(event.key.keysym.sym == SDLK_LEFT){
                        uu=uu+100;
                        break;
                    } else{
                        break;
                    }

                case SDL_QUIT:
                    exit(0);

            }
        }
        if(de==0){
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
            int c,d;
            c=800/length;
            d=800/height;



            SDL_Rect rect = {0, 0, 800, 800};
            SDL_RenderDrawRect(renderer, &rect);

            SDL_SetRenderDrawColor(renderer, 128, 128, 128, SDL_ALPHA_OPAQUE);
            SDL_RenderFillRect(renderer, &rect);

            //draw a rect
            for(int x=0;x<length;x++){
                for(int y=0;y<height;y++){
                    if(map[y][x]==1){
                        SDL_Rect q = {x*c, y*d, c-2, d-2};
                        SDL_RenderDrawRect(renderer, &q);
                        SDL_SetRenderDrawColor(renderer,0,0,0,SDL_ALPHA_OPAQUE);
                        SDL_RenderFillRect(renderer,&q);}
                    else if(map[y][x]==0){
                        SDL_Rect q = {x*c, y*d, c-2, d-2};
                        SDL_RenderDrawRect(renderer, &q);
                        SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
                        SDL_RenderFillRect(renderer,&q);}


                }}
            int oo=0;
            for (int a = 0; a < height; a++) {
                for (int b = 0; b < length; b++) {
                    if(map[a][b] ==1){
                        oo++;
                    }
                }

            }
            SDL_RenderPresent(renderer);
            printf("Times:%i\n",times);
            printf("Lived cells:%i\n",oo);
            SDL_Delay(uu);


            // show window





            FILE *p= fopen("history.txt","w");
            for(int a=0;a< height;a++){
                for(int b=0;b<length;b++){
                    if(b!=length-1){
                        fprintf(p,"%i",map[a][b]);
                        fprintf(p,",");}
                    else{
                        fprintf(p,"%i",map[a][b]);
                        fprintf(p,"\n");}
                }
            }

            fclose(p);
        }
        else if(de==1){
            int zz;
            zz++;
        }

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
void runnh( int height, int length){
    int uu;
    printf("Please enter the stay time(ms):");
    int q = scanf("%i",&uu);
    if(q==0){
        printf("Please enter a positive integer.");
        return ;
    }
    int map[height][length];
    int mm[height][length];
    int aa;

    FILE *ff= fopen("history.txt","r");
    char temp;
    int x=0;
    int y=0;
    while(!feof(ff)){
        temp= fgetc(ff);
        if(temp=='1'||temp=='0'){
            int xx= (int)temp-(int)'0';
            map[x][y]= xx;

            y++;
            if(y==length){
                y=0;
            }
        }
        else if(temp=='\n'){
            x++;
        }
    }

    int times=0;
    int ttt=0;
    fclose(ff);
    SDL_Window *sdl_window;
    SDL_Renderer *renderer;
    SDL_Event event;
    // 0 init sdl
    SDL_Init(SDL_INIT_VIDEO);

    //1 create window
    sdl_window = SDL_CreateWindow("Game of Life",
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  800,
                                  800,
                                  SDL_WINDOW_SHOWN);
    //2 create renderer
    renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_SOFTWARE);

    //3 set renderer color (set background color  Blue)
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);

    //4 clear color
    SDL_RenderClear(renderer);
    int de=0;
    while(times==0){
        while(SDL_PollEvent(&event)){
            switch (event.type) {
                case SDL_KEYDOWN:
                    if( event.key.keysym.sym == SDLK_p){
                        if(de==0)
                            de=1;
                        else if(de==1)
                            de=0;
                        break;
                    }
                    else if(event.key.keysym.sym == SDLK_RIGHT){
                        if(uu>=200){
                            uu=uu-100;}
                        break;
                    }
                    else if(event.key.keysym.sym == SDLK_LEFT){
                        uu=uu+100;
                        break;
                    } else{
                        break;
                    }

                case SDL_QUIT:
                    exit(0);

            }
        }
        if (de==0){
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

            int c,d;
            c=800/length;
            d=800/height;





            SDL_Rect rect = {0, 0, 800, 800};
            SDL_RenderDrawRect(renderer, &rect);

            SDL_SetRenderDrawColor(renderer, 128, 128, 128, SDL_ALPHA_OPAQUE);
            SDL_RenderFillRect(renderer, &rect);

            //draw a rect
            for(int x=0;x<length;x++){
                for(int y=0;y<height;y++){
                    if(map[y][x]==1){
                        SDL_Rect q = {x*c, y*d, c-2, d-2};
                        SDL_RenderDrawRect(renderer, &q);
                        SDL_SetRenderDrawColor(renderer,0,0,0,SDL_ALPHA_OPAQUE);
                        SDL_RenderFillRect(renderer,&q);}
                    else if(map[y][x]==0){
                        SDL_Rect q = {x*c, y*d, c-2, d-2};
                        SDL_RenderDrawRect(renderer, &q);
                        SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
                        SDL_RenderFillRect(renderer,&q);}


                }}

            int oo=0;
            for (int a = 0; a < height; a++) {
                for (int b = 0; b < length; b++) {
                    if(map[a][b] ==1){
                        oo++;
                    }
                }

            }

            // show window
            ttt++;
            SDL_RenderPresent(renderer);
            printf("Times:%i\n",ttt);
            printf("Lived cells:%i\n",oo);
            SDL_Delay(uu);

            FILE *p= fopen("history.txt","w");
            for(int a=0;a< height;a++){
                for(int b=0;b<length;b++){
                    if(b!=length-1){
                        fprintf(p,"%i",map[a][b]);
                        fprintf(p,",");}
                    else{
                        fprintf(p,"%i",map[a][b]);
                        fprintf(p,"\n");}
                }
            }

            fclose(p);
            int op=0;
            for (int a = 0; a < height; a++) {
                for (int b = 0; b < length; b++) {
                    if(map[a][b] ==0){
                        op++;
                    }
                }

            }
            if(op==height*length){
                times++;
            }
        } else{
            int zz;
            zz++;
        }
    }



}
