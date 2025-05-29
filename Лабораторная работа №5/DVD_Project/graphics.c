#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "graphics.h"


// Функция для инициализации и загрузки объекта
bool load_object(struct DVD_Object* dvd_obj, struct Screensaver* screensaver)
{

    int img_init = IMG_Init(IMAGE_FLAGS);
    if ((img_init & IMAGE_FLAGS) != IMAGE_FLAGS)
    {
        fprintf(stderr, "IMG_Init Error: %s\n", IMG_GetError());
        return true;
    }

    dvd_obj->object_image = IMG_LoadTexture(screensaver->renderer, "img\\DVD_logo.png");
    if (!dvd_obj->object_image)
    {
        fprintf(stderr, "IMG_LoadTexture Error: %s\n", IMG_GetError());
        return true;
    }

    if (SDL_QueryTexture(dvd_obj->object_image, NULL, NULL, &dvd_obj->object_rect.w, &dvd_obj->object_rect.h))
    {
        fprintf(stderr, "SDL_QueryTexture Error: %s\n", SDL_GetError());
        return true;
    }

    return false;
}


// Функция для "очистки" объекта
void object_cleanup(struct DVD_Object* dvd_obj, int exit_status)
{
    SDL_DestroyTexture(dvd_obj->object_image);
    IMG_Quit();

    exit(exit_status);
}


// Функция движения объекта
void object_update(struct DVD_Object* dvd_obj)
{
    dvd_obj->object_rect.x += dvd_obj->object_xvel;
    dvd_obj->object_rect.y += dvd_obj->object_yvel;

    if (dvd_obj->object_rect.x + dvd_obj->object_rect.w > SCREEN_WIDTH)
    { dvd_obj->object_xvel = -3; }

    if (dvd_obj->object_rect.x < 0)
    { dvd_obj->object_xvel = 3; }

    if (dvd_obj->object_rect.y + dvd_obj->object_rect.h > SCREEN_HEIGHT)
    { dvd_obj->object_yvel = -3; }

    if (dvd_obj->object_rect.y < 0)
    { dvd_obj->object_yvel = 3; }
}
