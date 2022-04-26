//
// Created by logan on 27/04/22.
//

#include "Map.hpp"

#include "libtcod.hpp"

Map::Map(int width, int height) : width(width), height(height) {
  tiles = new Tile[width * height];
  setWall(30, 22);
  setWall(50, 22);
}

Map::~Map() { delete[] tiles; }

bool Map::isWall(int x, int y) const { return !tiles[x + y * width].canWalk; }

void Map::setWall(int x, int y) { tiles[x + y * width].canWalk = false; }

void Map::render(tcod::Console& console) const {
  static const TCOD_color_t darkWall{0, 0, 100};
  static const TCOD_color_t darkGround{50, 50, 150};

  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      console.at(x, y).ch = '#';
      console.at(x, y).fg = isWall(x, y) ? darkWall : darkGround;
    }
  }
}