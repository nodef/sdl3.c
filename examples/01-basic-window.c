// Example 1: Basic Window
// This example demonstrates how to create a simple window using SDL3.

#define SDL3_IMPLEMENTATION
#include <SDL3.h>

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Basic Window", 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        SDL_Log("Could not create window: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Delay(3000); // Keep the window open for 3 seconds

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
