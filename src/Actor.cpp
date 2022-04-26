//
// Created by logan on 26/04/22.
//

#include "Actor.hpp"

#include "libtcod.hpp"

Actor::Actor(int x, int y, int glyph, const TCOD_color_t& col) : x(x), y(y), glyph(glyph), col(col) {}

void Actor::render(tcod::Console& console) const {
  console.at(x, y).ch = glyph;
  console.at(x, y).fg = col;
  console.at(x, y).bg = TCOD_color_t{0, 0, 0};
}