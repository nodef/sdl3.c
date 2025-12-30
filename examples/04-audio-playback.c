// Example 4: Audio Playback
// This example demonstrates how to play audio using SDL3.

#include "SDL3/SDL.h"
#include "SDL3/SDL_audio.h"

void audio_callback(void *userdata, Uint8 *stream, int len) {
    static int phase = 0;
    for (int i = 0; i < len; i++) {
        stream[i] = (Uint8)(128 + 127 * SDL_sin(phase * 0.01f));
        phase++;
    }
}

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_AUDIO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    SDL_AudioSpec spec;
    spec.freq = 44100;
    spec.format = AUDIO_U8;
    spec.channels = 1;
    spec.samples = 4096;
    spec.callback = audio_callback;

    if (SDL_OpenAudio(&spec, NULL) < 0) {
        SDL_Log("Failed to open audio: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_PauseAudio(0);
    SDL_Delay(3000);
    SDL_CloseAudio();
    SDL_Quit();
    return 0;
}
