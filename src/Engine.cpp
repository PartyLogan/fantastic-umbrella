//
// Created by logan on 27/04/22.
//

#include "Engine.hpp"

#include <SDL.h>

#include "Actor.hpp"
#include "Map.hpp"
#include "libtcod.hpp"

Engine::Engine() {
  player = new Actor(40, 22, '@', TCOD_color_t{255, 255, 255});
  actors.push(player);
  actors.push(new Actor(60, 13, '@', TCOD_color_t{255, 255, 0}));
  map = new Map(80, 45);
}

Engine::~Engine() {
  actors.clearAndDelete();
  delete map;
}

void Engine::render(tcod::Console& console) const {
  // draw the map
  map->render(console);
  // draw the screen
  for (auto& actor : actors) {
    actor->render(console);
  }
}

void Engine::update() {
  // Handle input.
  SDL_Event event;
  SDL_WaitEvent(nullptr);
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
        /* Look for a keypress */
      case SDL_QUIT:
        std::exit(EXIT_SUCCESS);
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
          case SDLK_UP:
            if (!map->isWall(player->x, player->y - 1)) {
              player->y--;
            }
            break;
          case SDLK_DOWN:
            if (!map->isWall(player->x, player->y + 1)) {
              player->y++;
            }
            break;
          case SDLK_LEFT:
            if (!map->isWall(player->x - 1, player->y)) {
              player->x--;
            }
            break;
          case SDLK_RIGHT:
            if (!map->isWall(player->x + 1, player->y)) {
              player->x++;
            }
            break;
          default:
            break;
        }
      default:
        break;
    }
  }
}
