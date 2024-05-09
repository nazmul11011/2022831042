#include <SDL2/SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int INITIAL_RADIUS = 60;
const int RADIUS_INCREMENT = 1;

int main(int argc, char ** argv) {

    // Window Event Initialization
    bool running = true;
    SDL_Event event;

    // Window and Renderer Initialization  
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    // Initialization
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer);

    // Main Loop
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    int centerX = SCREEN_WIDTH / 2;
    int centerY = SCREEN_HEIGHT / 2;
    int radius = INITIAL_RADIUS;

    // Event Loop
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        radius += RADIUS_INCREMENT;

        if (centerX + radius >= SCREEN_WIDTH || centerY + radius >= SCREEN_HEIGHT || centerX - radius <= 0 || centerY - radius <= 0) {
            radius = INITIAL_RADIUS;
        }

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); 
        
        // Circle Drawing
        for (int w = 0; w < radius * 2; w++) {
            for (int h = 0; h < radius * 2; h++) {
                int dx = radius - w; 
                int dy = radius - h; 
                if ((dx * dx + dy * dy) <= (radius * radius)) {
                    SDL_RenderDrawPoint(renderer, centerX + dx, centerY + dy);
                }
            }
        }

        SDL_RenderPresent(renderer);
    }

    // Clean Up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
