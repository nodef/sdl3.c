// Example 7: Joystick Input
// This example demonstrates how to handle joystick input using SDL3.

#include "SDL3/SDL.h"

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    if (SDL_NumJoysticks() < 1) {
        SDL_Log("No joysticks connected.");
        SDL_Quit();
        return 1;
    }

    SDL_Joystick *joystick = SDL_JoystickOpen(0);
    if (!joystick) {
        SDL_Log("Could not open joystick: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Joystick Input", 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        SDL_Log("Could not create window: %s", SDL_GetError());
        SDL_JoystickClose(joystick);
        SDL_Quit();
        return 1;
    }

    SDL_bool running = SDL_TRUE;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = SDL_FALSE;
            } else if (event.type == SDL_JOYAXISMOTION) {
                SDL_Log("Joystick %d axis %d moved to %d", event.jaxis.which, event.jaxis.axis, event.jaxis.value);
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_JoystickClose(joystick);
    SDL_Quit();
    return 0;
}
