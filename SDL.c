
#include <SDL2/SDL.h>
#include "run.h"


int sdl()
{

    int a,b,c,d;
    printf("Please enter the width:");
    scanf("%i",&a);
    printf("Please enter the length:");
    scanf("%i",&b);
    c=800/a;
    d=800/b;
    SDL_Window *sdl_window;
    SDL_Renderer *renderer;
    int quit = 1;
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


    SDL_Rect rect = {0, 0, 800, 800};
    SDL_RenderDrawRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, 128, 128, 128, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &rect);

    //draw a rect
    for(int x=0;x<a;x++){
        for(int y=0;y<b;y++){
            SDL_Rect q = {x*c, y*d, c-2, d-2};
            SDL_RenderDrawRect(renderer, &q);
            SDL_SetRenderDrawColor(renderer,0,0,0,SDL_ALPHA_OPAQUE);
            SDL_RenderFillRect(renderer,&q);

    }}



    // show window
    SDL_RenderPresent(renderer);

    do
    {

        SDL_WaitEvent(&event);
        switch (event.type)
        {
            case SDL_QUIT:
                quit = 0;
                break;
//            default:
//                SDL_Log("event type is %d \n", event.type);
        }
    } while (quit);

    __FAIL:
    if (renderer)
    {
        SDL_DestroyRenderer(renderer);
    }
    if (sdl_window)
    {
        SDL_DestroyWindow(sdl_window);
    }
    SDL_Quit();
    return 0;
}