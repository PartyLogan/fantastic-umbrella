//
// Created by logan on 27/04/22.
//

#ifndef FANTASTIC_UMBRELLA_MAP_HPP
#define FANTASTIC_UMBRELLA_MAP_HPP

#include <libtcod.hpp>

#include "Tile.hpp"
class Map {
 public:
  int width, height;

  Map(int width, int height);
  ~Map();
  bool isWall(int x, int y) const;
  void render(tcod::Console& console) const;

 protected:
  Tile* tiles;

  void setWall(int x, int y);
};

#endif  // FANTASTIC_UMBRELLA_MAP_HPP
