#ifndef GRAPHICS_H
#define GRAPHICS_H


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


#define WINDOW_TITLE "DVD Screensaver"
#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 500
#define IMAGE_FLAGS IMG_INIT_PNG


struct DVD_Object
{
    SDL_Texture* object_image;
    SDL_Rect object_rect;
    int object_xvel;
    int object_yvel;
};

struct Screensaver
{
    SDL_Window* window;
    SDL_Renderer* renderer;
};


bool load_object(struct DVD_Object*, struct Screensaver*);
void object_cleanup(struct DVD_Object*, int);
void object_update(struct DVD_Object*);


#endif