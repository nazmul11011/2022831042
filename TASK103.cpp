#include <SDL2/SDL.h>
#include <cmath>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char **argv) {

    bool quit = false;
    SDL_Event event;

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);

    int radius = 40;
    int centerX = radius;
    int centerY = SCREEN_HEIGHT / 2;
    int speed = 2;

    int centerX2 = SCREEN_WIDTH / 2;
    int centerY2 = radius;
    int velX2 = 0;
    int velY2 = 0;
    int speed2 = 5;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                quit = true;
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                case SDLK_UP:
                    velY2 = -speed2;
                    break;
                case SDLK_DOWN:
                    velY2 = speed2;
                    break;
                case SDLK_LEFT:
                    velX2 = -speed2;
                    break;
                case SDLK_RIGHT:
                    velX2 = speed2;
                    break;
                }
            }
        }

        centerX += speed;
        if (centerX > SCREEN_WIDTH + radius) {
            centerX = -radius;
        }

        centerX2 += velX2;
        centerY2 += velY2;

        if (centerX2 < radius) {
            centerX2 = radius;
            velX2 = -velX2;
        } else if (centerX2 > SCREEN_WIDTH - radius) {
            centerX2 = SCREEN_WIDTH - radius;
            velX2 = -velX2;
        }
        if (centerY2 < radius) {
            centerY2 = radius;
            velY2 = -velY2;
        } else if (centerY2 > SCREEN_HEIGHT - radius) {
            centerY2 = SCREEN_HEIGHT - radius;
            velY2 = -velY2;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Collision check
        int dx = centerX - centerX2;
        int dy = centerY - centerY2;
        double distance = sqrt(dx * dx + dy * dy);
        bool collided = distance < (2 * radius);

        if (collided) {
            velX2 = -velX2;
            velY2 = -velY2;
        }

        int colorR = collided ? 255 : 255;
        int colorG = collided ? 255 : 0;
        int colorB = collided ? 0 : 0;

        // 1st Circle
        SDL_SetRenderDrawColor(renderer, colorR, colorG, colorB, 255);
        for (int w = 0; w < radius * 2; w++) {
            for (int h = 0; h < radius * 2; h++) {
                int dx = radius - w;
                int dy = radius - h;
                if ((dx * dx + dy * dy) <= (radius * radius)) {
                    SDL_RenderDrawPoint(renderer, centerX + dx, centerY + dy);
                }
            }
        }

        // 2nd Circle
        SDL_SetRenderDrawColor(renderer, colorR, colorG, colorB, 255);
        for (int w = 0; w < radius * 2; w++) {
            for (int h = 0; h < radius * 2; h++) {
                int dx = radius - w;
                int dy = radius - h;
                if ((dx * dx + dy * dy) <= (radius * radius)) {
                    SDL_RenderDrawPoint(renderer, centerX2 + dx, centerY2 + dy);
                }
            }
        }

        SDL_RenderPresent(renderer);

        //SDL_Delay(10);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
