//
// Created by logan on 27/04/22.
//

#ifndef FANTASTIC_UMBRELLA_ENGINE_HPP
#define FANTASTIC_UMBRELLA_ENGINE_HPP

#include <libtcod.hpp>

class Actor;
class Map;

class Engine {
 public:
  TCODList<Actor*> actors;
  Actor* player;
  Map* map;

  Engine();
  ~Engine();
  void update();
  void render(tcod::Console& console) const;
};

extern Engine engine;

#endif  // FANTASTIC_UMBRELLA_ENGINE_HPP
