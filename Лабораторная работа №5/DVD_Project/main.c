#define SDL_MAIN_HANDLED


#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "graphics.h"


void main_window_cleanup(struct Screensaver*, int);
bool sdl_initialize(struct Screensaver*);


int main(int argc, char* argv[])
{
    struct Screensaver screensaver = 
        {
            .window = NULL,
            .renderer = NULL
        };

    struct DVD_Object dvd_obj = 
        {
            .object_image = NULL,
            .object_rect = {0, 0, 0, 0},
            .object_xvel = 3,
            .object_yvel = 3
        };

    // Инициализация окна
    if (sdl_initialize(&screensaver))
    { main_window_cleanup(&screensaver, EXIT_FAILURE); }
    
    // Инициализация объекта
    if (load_object(&dvd_obj, &screensaver))
    { object_cleanup(&dvd_obj, EXIT_FAILURE); }

    while (true)
    {
        // Обработка события "Закрытие окна"
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    object_cleanup(&dvd_obj, EXIT_SUCCESS);
                    main_window_cleanup(&screensaver, EXIT_SUCCESS);
                    break;

                default: break;
            }
        }

        // Отрисовка объекта
        object_update(&dvd_obj);
        SDL_RenderClear(screensaver.renderer);
        SDL_RenderCopy(screensaver.renderer, dvd_obj.object_image, NULL, &dvd_obj.object_rect);
        SDL_RenderPresent(screensaver.renderer);
    
        SDL_Delay(17);  // Обноввление каждые 17 мс (~60 FPS)
    }

    // "Очищение" окна и объекта
    object_cleanup(&dvd_obj, EXIT_SUCCESS);
    main_window_cleanup(&screensaver, EXIT_SUCCESS);

    return 0;
}


// Функция для "очистки" SDL-объекта (основного окна)
void main_window_cleanup(struct Screensaver* screensaver, int exit_status)
{
    SDL_DestroyRenderer(screensaver->renderer);
    SDL_DestroyWindow(screensaver->window);
    SDL_Quit();

    exit(exit_status);
}


// Функция для инициализации SDL-объекта (основного окна)
bool sdl_initialize(struct Screensaver* screensaver)
{
    if (SDL_Init(SDL_INIT_EVERYTHING))
    {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        return true;
    }

    screensaver->window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!screensaver->window)
    {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        return true;
    }

    screensaver->renderer = SDL_CreateRenderer(screensaver->window, -1, 0);
    if (!screensaver->renderer)
    {
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        return true;
    }

    return false;
}
