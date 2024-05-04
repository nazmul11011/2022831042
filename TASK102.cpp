#include <SDL2/SDL.h>
#include <stdio.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define INITIAL_RADIUS 60
#define RADIUS_INCREMENT 1

bool initializeSDL(SDL_Window** window, SDL_Renderer** renderer) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL initialization failed: %s\n", SDL_GetError());
        return false;
    }

    *window = SDL_CreateWindow("Circle Drawing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (*window == NULL) {
        printf("Window creation failed: %s\n", SDL_GetError());
        return false;
    }

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (*renderer == NULL) {
        printf("Renderer creation failed: %s\n", SDL_GetError());
        return false;
    }

    
    SDL_SetRenderDrawBlendMode(*renderer, SDL_BLENDMODE_BLEND);

    return true;
}

void fillCircle(SDL_Renderer* renderer, int cx, int cy, int radius) {
    for (int w = 0; w < radius * 2; w++) {
        for (int h = 0; h < radius * 2; h++) {
            int dx = radius - w; 
            int dy = radius - h; 
            if ((dx * dx + dy * dy) <= (radius * radius)) {
                SDL_RenderDrawPoint(renderer, cx + dx, cy + dy);
            }
        }
    }
}

int main(int argc, char* argv[]) {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    if (!initializeSDL(&window, &renderer)) {
        return 1;
    }

    int centerX = SCREEN_WIDTH / 2;
    int centerY = SCREEN_HEIGHT / 2;
    int radius = INITIAL_RADIUS;

    SDL_Event event;
    bool running = true;

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

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0); 
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); 
        fillCircle(renderer, centerX, centerY, radius);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
