#ifndef GRAPHICS_H
#define GRAPHICS_H


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


#define WINDOW_TITLE "DVD Screensaver"  // Название окна
#define SCREEN_WIDTH 900    // Ширина окна (в пикселях)
#define SCREEN_HEIGHT 500   // Высота окна (в пикселях)
#define IMAGE_FLAGS IMG_INIT_PNG    // Флаг для формата загружаемого изображения


// Объект, который движется
struct DVD_Object
{
    SDL_Texture* object_image;
    SDL_Rect object_rect;
    int object_xvel;    // Скорость по оси x
    int object_yvel;    // Скорость по оси y
};

// Объект самой SDL-программы (окно и поверхность)
struct Screensaver
{
    SDL_Window* window;
    SDL_Renderer* renderer; 
};


bool load_object(struct DVD_Object*, struct Screensaver*);
void object_cleanup(struct DVD_Object*, int);
void object_update(struct DVD_Object*);


#endif