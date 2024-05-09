#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char ** argv) {

    // Window Event Initialization
    bool quit = false;
    SDL_Event event;

    // Window and Renderer Initialization
    SDL_Window * window=NULL;
    SDL_Renderer * renderer=NULL;

    // Initialization
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer);

    // Main Loop
    int centerX = SCREEN_WIDTH/2;
    int centerY = SCREEN_HEIGHT/2;
    int radius = 100;

    // Circle Drawing
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
    for (int w = 0; w < radius * 2; w++) {
        for (int h = 0; h < radius * 2; h++) {
            int dx = radius - w;
            int dy = radius - h;
            if ((dx*dx + dy*dy) <= (radius * radius)) {
                SDL_RenderDrawPoint(renderer, centerX + dx, centerY + dy);
            }
        }
    }

    // Present Renderer
    SDL_RenderPresent(renderer);

    // Event Loop
    while (!quit)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            quit = true;
            break;
        }
    }

    // Clean Up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}